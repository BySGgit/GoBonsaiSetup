int __thiscall sub_434C90(int this)
{
  int *v2; // edi
  int v3; // edx

  v2 = (int *)(this + 64);
  SetRect(
    (LPRECT)(this + 64),
    *(_DWORD *)(this + 8),
    *(_DWORD *)(this + 12),
    *(_DWORD *)(this + 8) + *(_DWORD *)(this + 16),
    *(_DWORD *)(this + 12) + *(_DWORD *)(this + 20));
  SetRect(
    (LPRECT)(this + 84),
    *v2,
    *(_DWORD *)(this + 68),
    *(_DWORD *)(this + 72),
    *(_DWORD *)(this + 72) + *(_DWORD *)(this + 68) - *v2);
  SetRect(
    (LPRECT)(this + 100),
    *v2,
    *(_DWORD *)(this + 76) + *(_DWORD *)(this + 64) - *(_DWORD *)(this + 72),
    *(_DWORD *)(this + 72),
    *(_DWORD *)(this + 76));
  SetRect(
    (LPRECT)(this + 116),
    *(_DWORD *)(this + 84),
    *(_DWORD *)(this + 96),
    *(_DWORD *)(this + 108),
    *(_DWORD *)(this + 104));
  v3 = *(_DWORD *)(this + 92);
  *(_DWORD *)(this + 132) = *(_DWORD *)(this + 84);
  *(_DWORD *)(this + 140) = v3;
  return sub_434D20(this);
}
