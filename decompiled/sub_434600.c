BOOL __thiscall sub_434600(int this)
{
  _DWORD *v2; // ebx
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // eax

  v2 = (_DWORD *)(this + 64);
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
  *(_DWORD *)(this + 116) = *(_DWORD *)(this + 108) + v5 - *(_DWORD *)(this + 112);
  OffsetRect((LPRECT)(this + 108), (*(_DWORD *)(this + 116) - *(_DWORD *)(this + 108)) / -2, 0);
  v6 = (int)((double)(*(_DWORD *)(this + 80) - *(_DWORD *)(this + 84))
           * (double)(*(_DWORD *)(this + 72) - *(_DWORD *)(this + 64))
           / (double)(*(_DWORD *)(this + 88) - *(_DWORD *)(this + 84)));
  *(_DWORD *)(this + 100) = v6;
  return OffsetRect((LPRECT)(this + 108), v6, 0);
}
