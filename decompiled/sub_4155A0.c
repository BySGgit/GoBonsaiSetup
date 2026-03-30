char __stdcall sub_4155A0(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi
  int v3; // edi

  v1 = *(_DWORD **)(a1 + 168);
  v2 = (_DWORD *)*v1;
  if ( (_DWORD *)*v1 == v1 )
    return 0;
  while ( 1 )
  {
    v3 = v2[2];
    if ( v3 )
    {
      if ( (dword_4D8CF8 & 1) == 0 )
      {
        dword_4D8CF8 |= 1u;
        sub_413C20();
      }
      if ( byte_4D8229[11 * *(_DWORD *)(v3 + 4)] )
        break;
    }
    v2 = (_DWORD *)*v2;
    if ( v2 == *(_DWORD **)(a1 + 168) )
      return 0;
  }
  return 1;
}
