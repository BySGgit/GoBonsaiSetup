int __thiscall sub_434D20(int this)
{
  int v1; // ebx
  int v2; // edi
  int v3; // ebp
  int v4; // eax
  int v5; // eax
  int result; // eax

  v1 = *(_DWORD *)(this + 152);
  v2 = *(_DWORD *)(this + 160) - *(_DWORD *)(this + 156);
  if ( v2 <= v1 )
  {
    result = *(_DWORD *)(this + 136);
    *(_BYTE *)(this + 80) = 0;
    *(_DWORD *)(this + 144) = result;
  }
  else
  {
    v3 = v1 * (*(_DWORD *)(this + 128) - *(_DWORD *)(this + 120)) / v2;
    if ( v3 <= 8 )
      v3 = 8;
    v4 = (*(_DWORD *)(this + 128) - *(_DWORD *)(this + 120) - v3)
       * (*(_DWORD *)(this + 148) - *(_DWORD *)(this + 156))
       / (v2 - v1);
    *(_BYTE *)(this + 80) = 1;
    v5 = *(_DWORD *)(this + 120) + v4;
    *(_DWORD *)(this + 136) = v5;
    result = v3 + v5;
    *(_DWORD *)(this + 144) = result;
  }
  return result;
}
