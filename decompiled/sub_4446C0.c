__int16 __thiscall sub_4446C0(int this)
{
  unsigned int *v1; // edx
  unsigned int v2; // esi
  int *v4; // edi
  unsigned int v5; // eax

  v1 = *(unsigned int **)(this + 32);
  v2 = *v1;
  if ( !*v1 )
    return -1;
  v4 = *(int **)(this + 48);
  if ( v2 < v2 + 2 * *v4 )
    return *(_WORD *)v2;
  if ( (*(_BYTE *)(this + 64) & 4) != 0 )
    return -1;
  v5 = **(_DWORD **)(this + 36);
  if ( !v5 || v5 <= v2 && *(_DWORD *)(this + 60) <= v2 )
    return -1;
  if ( *(_DWORD *)(this + 60) < v5 )
    *(_DWORD *)(this + 60) = v5;
  *v4 = (int)(*(_DWORD *)(this + 60) - *v1) >> 1;
  return ***(_WORD ***)(this + 32);
}
