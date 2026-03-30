int __usercall sub_430210@<eax>(int a1@<eax>)
{
  int v1; // ecx
  _DWORD *v2; // edx
  _DWORD *v3; // eax
  int v4; // ecx

  v1 = *(_DWORD *)(a1 + 28) - 1;
  v2 = *(_DWORD **)(a1 + 24);
  v3 = v2;
  if ( v1 >= 0 )
    return *(_DWORD *)(v2[152] + 4 * v1);
  do
  {
    v3 = (_DWORD *)v3[186];
    if ( !v3 )
      v3 = v2;
    v4 = v3[153] - 1;
  }
  while ( v4 < 0 );
  return *(_DWORD *)(v3[152] + 4 * v4);
}
