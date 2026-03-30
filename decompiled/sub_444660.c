int __thiscall sub_444660(int this, unsigned __int16 a2)
{
  unsigned int v2; // eax

  v2 = **(_DWORD **)(this + 32);
  if ( !v2
    || v2 <= **(_DWORD **)(this + 16)
    || a2 != 0xFFFF && a2 != *(_WORD *)(v2 - 2) && (*(_BYTE *)(this + 64) & 2) != 0 )
  {
    return 0xFFFF;
  }
  ++**(_DWORD **)(this + 48);
  **(_DWORD **)(this + 32) -= 2;
  if ( a2 == 0xFFFF )
    return 0;
  ***(_WORD ***)(this + 32) = a2;
  return a2;
}
