# -*- coding: utf-8 -*-
"""
GoBonsai.exe — трассировка одного запуска под отладчиком IDA.

Цель: за ~20–30 с игры собрать JSONL-лог по срабатыванию точек останова на ключевых
сабах + снимок глобалей мира и полей корневой TreeSection (как в TS-порте).

Использование (IDA Pro, локальный Win32 debugger):
  1. File → Open → GoBonsai.exe, дождаться анализа; имена sub_* из декомпила должны быть в IDB.
  2. Debugger → Select debugger → Local Windows debugger.
  3. File → Script file… → выбрать этот скрипт (или Alt+F7).
  4. В консоли/выводе скрипта смотреть путь к логу (по умолчанию рядом с IDB или с входным exe). CONFIG["LOG_PATH"] переопределяет.
  5. Debugger → Start process (F9). Играть/ждать ~20–30 с. Остановы на BPT пишут строки в лог.
  6. Debugger → Pause / остановить игру → gobonsai_trace_stop() из консоли IDAPython (или перезапуск IDA).

Зависимости: IDAPython 3.x (IDA 8+). Чтение памяти — idc.get_bytes(..., use_dbg=True) при активном отладчике.

Ограничения:
  - Не «всё в игре»: только то, что перечислено в CONFIG и карте полей ниже.
  - Виртуальные вызовы без имени в графе — не логируются, пока не добавите явный BPT.
  - Частые сабы (например sub_416510 на каждом листе) дадут огромный лог — отключайте в CONFIG.
"""

from __future__ import annotations

import json
import os
import struct
import time
import traceback
from typing import Any, Dict, List, Optional

# --- IDAPython (вне IDA этот модуль не импортируется) ---
try:
    import idaapi
    import ida_bytes
    import ida_dbg
    import ida_name
    import ida_nalt
    import idc
except ImportError:
    idaapi = None  # type: ignore
    ida_nalt = None  # type: ignore

# ---------------------------------------------------------------------------
# Карта полей TreeSection (см. GUIDES/spec_constructor_sub_413F50.md)
# ---------------------------------------------------------------------------
ROOT_DUMP_FIELDS: List[tuple] = [
    (4, "u32", "sectionRuntimeType4"),
    (172, "u32", "childCount172"),
    (180, "u32", "parentPtr180"),
    (420, "f32", "energyProduction420"),
    (424, "f32", "energyAccumulator424"),
    (428, "f32", "energyWeight428"),
    (432, "f32", "energyBudget432"),
    (436, "f32", "energySpent436"),
    (440, "f32", "energyTickCounter440"),
    (444, "f32", "twigRadius444"),
    (448, "f32", "twigLength448"),
    (452, "f32", "maxGrowth452"),
    (456, "f32", "healthEnergy456"),
    (460, "f32", "totalWeight460_slot"),
    (480, "u32", "rollupDword480"),
    (484, "u32", "rollupDword484"),
]

# Смещения от базы мира dword_4D7EE8 (не указатель — структура в .bss/.data)
WORLD_DUMP_FIELDS: List[tuple] = [
    (196, "f32", "energyPool196"),
    (216, "f32", "simulationDay216"),
    (220, "u8", "worldFlagByte220"),
    (240, "u32", "rootTreeSectionPtr240"),
]


def _default_log_path() -> str:
    """IDA 7–9.2: рядом с .idb/.i64, иначе рядом с входным файлом (get_input_file_path)."""
    for getter in (
        getattr(ida_nalt, "get_idb_path", None),
        getattr(idc, "get_idb_path", None),
    ):
        if callable(getter):
            try:
                p = getter()
                if p:
                    root, _ = os.path.splitext(p)
                    return root + "_gobonsai_trace.jsonl"
            except Exception:
                pass
    inp = ida_nalt.get_input_file_path()
    root, _ = os.path.splitext(inp)
    return root + "_gobonsai_trace.jsonl"


def _get_name_ea(name: str) -> Optional[int]:
    if not idaapi:
        return None
    ea = ida_name.get_name_ea(idaapi.BADADDR, name)
    if ea == idaapi.BADADDR:
        return None
    return ea


def _func_ea_by_name_or_rva(name: str, rva_hex: str) -> Optional[int]:
    ea = _get_name_ea(name)
    if ea is not None:
        return ea
    base = idaapi.get_imagebase()
    rva = int(rva_hex, 16)
    return base + rva if base is not None else None


def _read_mem(ea: int, n: int) -> Optional[bytes]:
    if ea is None or ea == idaapi.BADADDR or n <= 0:
        return None
    if ida_dbg.is_debugger_on():
        try:
            b = idc.get_bytes(ea, n, use_dbg=True)
            if b is not None and len(b) == n:
                return bytes(b) if not isinstance(b, bytes) else b
        except TypeError:
            pass
        try:
            buf = bytearray(n)
            nread = ida_dbg.read_dbg_memory(ea, buf)
            if nread == n:
                return bytes(buf)
        except Exception:
            pass
    try:
        return ida_bytes.get_bytes(ea, n)
    except Exception:
        return None


def _u32(b: Optional[bytes]) -> Optional[int]:
    if not b or len(b) != 4:
        return None
    return struct.unpack("<I", b)[0]


def _f32(b: Optional[bytes]) -> Optional[float]:
    if not b or len(b) != 4:
        return None
    return struct.unpack("<f", b)[0]


def _dump_struct_fields(base: int, fields: List[tuple]) -> Dict[str, Any]:
    out: Dict[str, Any] = {}
    if base == 0 or base is None:
        return out
    for off, kind, label in fields:
        ea = base + off
        if kind == "u32":
            v = _u32(_read_mem(ea, 4))
            if v is not None:
                out[label] = v
        elif kind == "f32":
            v = _f32(_read_mem(ea, 4))
            if v is not None and v == v:  # not NaN filter loose
                out[label] = round(v, 8)
        elif kind == "u8":
            b = _read_mem(ea, 1)
            if b:
                out[label] = b[0]
    return out


def _dump_world_and_root() -> Dict[str, Any]:
    payload: Dict[str, Any] = {}
    sym_ea = _get_name_ea("dword_4D7EE8")
    if sym_ea is None:
        payload["world_error"] = "name dword_4D7EE8 not found"
        return payload

    payload["world_global_symbol_ea"] = hex(sym_ea)

    # В GoBonsai.c: `dword_4D7EE8` — глобал типа int, в рантайме хранит АДРЕС объекта мира
    # (см. `*(float *)(dword_4D7EE8 + 216)`, `*(_DWORD *)(dword_4D7EE8 + 240)`).
    # Читать поля нужно по *sym_ea, а не по адресу символа в .data.
    world_base: Optional[int] = None
    if CONFIG.get("WORLD_DEREF_DWORD_4D7EE8", True):
        world_base = _u32(_read_mem(sym_ea, 4))
        payload["world_object_base"] = hex(world_base) if world_base else None
        if world_base is not None and world_base not in (0, 0xFFFFFFFF) and world_base >= 0x10000:
            w = _dump_struct_fields(world_base, WORLD_DUMP_FIELDS)
        else:
            payload["world_deref_warning"] = (
                "dword_4D7EE8 разыменование дало мусор/null — fallback: поля по адресу символа"
            )
            w = _dump_struct_fields(sym_ea, WORLD_DUMP_FIELDS)
            world_base = sym_ea
    else:
        world_base = sym_ea
        w = _dump_struct_fields(sym_ea, WORLD_DUMP_FIELDS)

    payload["world"] = w

    root_ptr = w.get("rootTreeSectionPtr240")
    if isinstance(root_ptr, int) and root_ptr not in (0, 0xFFFFFFFF) and root_ptr >= 0x10000:
        payload["root_section"] = _dump_struct_fields(root_ptr, ROOT_DUMP_FIELDS)
        payload["root_section"]["_ptr"] = hex(root_ptr)
    else:
        payload["root_section"] = None
        if root_ptr is not None:
            payload["root_section_invalid_ptr"] = hex(root_ptr) if isinstance(root_ptr, int) else root_ptr

    # Плавающие глобали цикла роста (имена из full.c / декомпила)
    for gname in CONFIG.get("GLOBAL_NAMES_FLOAT", []):
        gea = _get_name_ea(gname)
        if gea is not None:
            fv = _f32(_read_mem(gea, 4))
            if fv is not None:
                payload.setdefault("globals_float", {})[gname] = round(fv, 8)

    return payload


class _GoBonsaiTraceHooks(ida_dbg.DBG_Hooks):
    def __init__(self, log_path: str, bpt_eas: Dict[int, str]):
        ida_dbg.DBG_Hooks.__init__(self)
        self.log_path = log_path
        self.bpt_eas = bpt_eas
        self._seq = 0
        self._f = open(log_path, "a", encoding="utf-8")

    def _write_event(self, kind: str, ea: int, extra: Optional[Dict] = None) -> None:
        self._seq += 1
        rec: Dict[str, Any] = {
            "seq": self._seq,
            "ts_wall": time.time(),
            "kind": kind,
            "ea": hex(ea),
            "name": self.bpt_eas.get(ea, ""),
        }
        if extra:
            rec.update(extra)
        try:
            dump = _dump_world_and_root()
            rec["dump"] = dump
        except Exception:
            rec["dump_error"] = traceback.format_exc()
        self._f.write(json.dumps(rec, ensure_ascii=False) + "\n")
        self._f.flush()

    def dbg_bpt(self, tid: int, bptea: int) -> int:
        if bptea in self.bpt_eas:
            self._write_event("bpt", bptea)
        return 0

    def close(self) -> None:
        try:
            self._f.close()
        except Exception:
            pass


_HOOK: Optional[_GoBonsaiTraceHooks] = None


def gobonsai_trace_start() -> str:
    """Запуск: ставит BPT, вешает DBG_Hooks, открывает лог."""
    global _HOOK
    if _HOOK is not None:
        return "already running: call gobonsai_trace_stop() first"

    log_path = CONFIG["LOG_PATH"] or _default_log_path()

    bpt_eas: Dict[int, str] = {}
    for entry in CONFIG["BREAKPOINTS"]:
        if isinstance(entry, str):
            name, rva = entry, None
        else:
            name, rva = entry[0], entry[1]
        ea = _func_ea_by_name_or_rva(name, rva) if rva else _get_name_ea(name)
        if ea is None:
            print("[gobonsai_trace] skip (not found):", name)
            continue
        bpt_eas[ea] = name
        _bpt_ty = getattr(idaapi, "BPT_SOFT", getattr(ida_dbg, "BPT_SOFT", 0))
        ida_dbg.add_bpt(ea, 0, _bpt_ty)
        print("[gobonsai_trace] BPT", hex(ea), name)

    _HOOK = _GoBonsaiTraceHooks(log_path, bpt_eas)
    _HOOK.hook()
    print("[gobonsai_trace] log ->", log_path)
    return log_path


def gobonsai_trace_stop() -> None:
    """Снять хуки и удалить наши BPT (по списку из последнего start)."""
    global _HOOK
    if _HOOK is None:
        return
    for ea in list(_HOOK.bpt_eas.keys()):
        ida_dbg.del_bpt(ea)
    _HOOK.unhook()
    _HOOK.close()
    _HOOK = None
    print("[gobonsai_trace] stopped")


# ---------------------------------------------------------------------------
# Настройка под ваш IDB (при отсутствии имени используется RVA для образа по base)
# ---------------------------------------------------------------------------
CONFIG: Dict[str, Any] = {
    # False — старый (ошибочный для GoBonsai) режим: поля «мира» по адресу символа в .data
    "WORLD_DEREF_DWORD_4D7EE8": True,
    # Пустая строка → _default_log_path() (IDB или входной файл)
    "LOG_PATH": "",
    # (имя_в_IDB,) или (имя, "RVA") если имя не переименовано
    "BREAKPOINTS": [
        ("sub_412700", "412700"),
        ("sub_4130D0", "4130D0"),
        ("sub_40DC90", "40DC90"),
        ("sub_40E0A0", "40E0A0"),
        ("sub_4143E0", "4143E0"),
        # Осторожно: очень шумно на большом дереве
        # ("sub_416510", "416510"),
    ],
    "GLOBAL_NAMES_FLOAT": [
        "flt_4D7EF8",
        "flt_4D526C",
        "flt_4D8D04",
        "flt_4D8D18",
        "flt_4D8D00",
    ],
}


def main() -> None:
    if idaapi is None:
        print("Run inside IDA Pro only.")
        return
    gobonsai_trace_start()


if __name__ == "__main__":
    main()
