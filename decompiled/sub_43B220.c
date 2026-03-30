int sub_43B220()
{
  _DWORD *v0; // eax
  int v1; // esi
  int v2; // ecx
  _DWORD *i; // edx
  _DWORD *v4; // eax

  v0 = sub_42B3D0();
  v1 = v0[15];
  v2 = 0;
  if ( v1 <= 0 )
    return 0;
  for ( i = (_DWORD *)v0[14]; ; ++i )
  {
    v4 = (_DWORD *)*i;
    if ( *(_DWORD *)*i == dword_4D7DF4 )
      break;
    if ( ++v2 >= v1 )
      return 0;
  }
  if ( v4[140] <= dword_4D7DFC )
    return 0;
  else
    return *(_DWORD *)(v4[139] + 4 * dword_4D7DFC);
}
