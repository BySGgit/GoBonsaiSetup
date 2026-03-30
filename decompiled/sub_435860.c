BOOL __thiscall sub_435860(int this)
{
  int *v2; // ebx
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v11; // [esp-8h] [ebp-18h]
  int v12; // [esp-4h] [ebp-14h]

  v2 = (int *)(this + 64);
  SetRect(
    (LPRECT)(this + 64),
    *(_DWORD *)(this + 8),
    *(_DWORD *)(this + 12),
    *(_DWORD *)(this + 8) + *(_DWORD *)(this + 16),
    *(_DWORD *)(this + 12) + *(_DWORD *)(this + 20));
  v3 = *(_DWORD *)(this + 68);
  v4 = *(_DWORD *)(this + 72);
  *(_DWORD *)(this + 108) = *v2;
  v5 = *(_DWORD *)(this + 76);
  *(_DWORD *)(this + 112) = v3;
  *(_DWORD *)(this + 116) = v4;
  *(_DWORD *)(this + 120) = v5;
  InflateRect((LPRECT)(this + 108), -*(_DWORD *)(this + 100), -*(_DWORD *)(this + 100));
  v6 = *(_DWORD *)(this + 112);
  v7 = *(_DWORD *)(this + 116);
  *(_DWORD *)(this + 124) = *(_DWORD *)(this + 108);
  v8 = *(_DWORD *)(this + 120);
  *(_DWORD *)(this + 128) = v6;
  v12 = *(_DWORD *)(this + 112);
  v9 = *v2;
  *(_DWORD *)(this + 132) = v7;
  v11 = *(_DWORD *)(this + 108);
  *(_DWORD *)(this + 136) = v8;
  SetRect((LPRECT)(this + 140), v9, *(_DWORD *)(this + 68), v11, v12);
  SetRect(
    (LPRECT)(this + 156),
    *(_DWORD *)(this + 108),
    *(_DWORD *)(this + 68),
    *(_DWORD *)(this + 116),
    *(_DWORD *)(this + 112));
  SetRect(
    (LPRECT)(this + 172),
    *(_DWORD *)(this + 116),
    *(_DWORD *)(this + 68),
    *(_DWORD *)(this + 72),
    *(_DWORD *)(this + 112));
  SetRect((LPRECT)(this + 188), *v2, *(_DWORD *)(this + 112), *(_DWORD *)(this + 108), *(_DWORD *)(this + 120));
  SetRect(
    (LPRECT)(this + 204),
    *(_DWORD *)(this + 116),
    *(_DWORD *)(this + 112),
    *(_DWORD *)(this + 72),
    *(_DWORD *)(this + 120));
  SetRect((LPRECT)(this + 220), *v2, *(_DWORD *)(this + 120), *(_DWORD *)(this + 108), *(_DWORD *)(this + 76));
  SetRect(
    (LPRECT)(this + 236),
    *(_DWORD *)(this + 108),
    *(_DWORD *)(this + 120),
    *(_DWORD *)(this + 116),
    *(_DWORD *)(this + 76));
  SetRect(
    (LPRECT)(this + 252),
    *(_DWORD *)(this + 116),
    *(_DWORD *)(this + 120),
    *(_DWORD *)(this + 72),
    *(_DWORD *)(this + 76));
  return InflateRect((LPRECT)(this + 108), -*(_DWORD *)(this + 104), -*(_DWORD *)(this + 104));
}
