char __thiscall sub_435F40(int this, unsigned int a2, __int16 a3, int a4)
{
  int v5; // eax
  int v6; // eax
  void (__stdcall *v7)(int, _DWORD, int, _DWORD); // ecx
  char result; // al
  int v9; // eax
  void (__stdcall *v10)(int, _DWORD, int, _DWORD); // ecx
  int v11; // eax
  int v12; // eax
  void (__stdcall *v13)(int, _DWORD, int, _DWORD); // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  void (__stdcall *v18)(int, _DWORD, int, _DWORD); // ecx
  int v19; // [esp-Ch] [ebp-10h]
  const WCHAR *v20; // [esp-Ch] [ebp-10h]

  if ( !*(_BYTE *)(this + 60) || !*(_BYTE *)(this + 4) || a2 < 0x100 )
    return 0;
  if ( a2 <= 0x101 )
    return 1;
  if ( a2 != 258 )
    return 0;
  switch ( a3 )
  {
    case 1:
      if ( *(_DWORD *)(this + 300) != *(_DWORD *)(this + 292) )
        return 1;
      v20 = *(const WCHAR **)(this + 80);
      *(_DWORD *)(this + 300) = 0;
      v11 = lstrlenW(v20);
      sub_435650(v11, (_DWORD *)this);
      return 1;
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 23:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
      return 1;
    case 3:
    case 24:
      sub_4359A0(this);
      if ( a3 != 24 )
        return 1;
      sub_4357D0(this);
LABEL_16:
      v9 = *(_DWORD *)(this + 24);
      v10 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v9 + 576);
      if ( !v10 )
        return 1;
      v10(1538, *(_DWORD *)(this + 44), this, *(_DWORD *)(v9 + 580));
      return 1;
    case 8:
      v5 = *(_DWORD *)(this + 292);
      if ( v5 == *(_DWORD *)(this + 300) )
      {
        if ( v5 <= 0 )
          goto LABEL_13;
        sub_435650(v5 - 1, (_DWORD *)this);
        v19 = *(_DWORD *)(this + 292);
        *(_DWORD *)(this + 300) = v19;
        sub_436C80(this + 80, v19);
      }
      else
      {
        sub_4357D0(this);
      }
      v6 = *(_DWORD *)(this + 24);
      v7 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v6 + 576);
      if ( v7 )
        v7(1538, *(_DWORD *)(this + 44), this, *(_DWORD *)(v6 + 580));
LABEL_13:
      sub_4370C0(this);
      result = 1;
      break;
    case 13:
      v12 = *(_DWORD *)(this + 24);
      v13 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v12 + 576);
      if ( !v13 )
        return 1;
      v13(1537, *(_DWORD *)(this + 44), this, *(_DWORD *)(v12 + 580));
      return 1;
    case 22:
      sub_435A60((_DWORD *)this);
      goto LABEL_16;
    default:
      if ( *(_DWORD *)(this + 292) != *(_DWORD *)(this + 300) )
        sub_4357D0(this);
      if ( *(_BYTE *)(this + 296)
        || (v14 = lstrlenW(*(LPCWSTR *)(this + 80)), v15 = *(_DWORD *)(this + 292), v15 >= v14) )
      {
        if ( sub_436C00(this + 80, *(_DWORD *)(this + 292), a3) )
        {
          sub_435650(*(_DWORD *)(this + 292) + 1, (_DWORD *)this);
          *(_DWORD *)(this + 300) = *(_DWORD *)(this + 292);
        }
      }
      else
      {
        v16 = *(_DWORD *)(this + 80);
        *(_BYTE *)(this + 92) = 1;
        *(_WORD *)(v16 + 2 * v15) = a3;
        sub_435650(*(_DWORD *)(this + 292) + 1, (_DWORD *)this);
        *(_DWORD *)(this + 300) = *(_DWORD *)(this + 292);
      }
      sub_4370C0(this);
      v17 = *(_DWORD *)(this + 24);
      v18 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v17 + 576);
      if ( v18 )
        v18(1538, *(_DWORD *)(this + 44), this, *(_DWORD *)(v17 + 580));
      return 1;
  }
  return result;
}
