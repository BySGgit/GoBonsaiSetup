int __stdcall sub_4154B0(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // edi
  int v3; // esi
  int v5; // [esp+14h] [ebp-10h]

  v1 = *(_DWORD **)(a1 + 168);
  v2 = (_DWORD *)*v1;
  v5 = 0;
  if ( (_DWORD *)*v1 == v1 )
    return 0;
  do
  {
    v3 = v2[2];
    if ( 0.0 != *(float *)(v3 + 456) )
    {
      if ( (dword_4D8CE0 & 1) == 0 )
      {
        dword_4D8CE0 |= 1u;
        sub_40FBA0();
      }
      if ( byte_4D822A[11 * *(_DWORD *)(v3 + 4)] )
        goto LABEL_9;
      if ( (dword_4D8CF8 & 1) == 0 )
      {
        dword_4D8CF8 |= 1u;
        sub_413C20();
      }
      if ( byte_4D8229[11 * *(_DWORD *)(v3 + 4)] )
LABEL_9:
        ++v5;
    }
    v2 = (_DWORD *)*v2;
  }
  while ( v2 != *(_DWORD **)(a1 + 168) );
  return v5;
}
