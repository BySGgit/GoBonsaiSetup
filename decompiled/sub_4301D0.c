int __usercall sub_4301D0@<eax>(int a1@<eax>)
{
  int v1; // ecx
  _DWORD *v2; // eax
  int v3; // ecx

  v1 = *(_DWORD *)(a1 + 28);
  v2 = *(_DWORD **)(a1 + 24);
  v3 = v1 + 1;
  if ( v3 < v2[153] )
    return *(_DWORD *)(v2[152] + 4 * v3);
  do
    v2 = (_DWORD *)v2[185];
  while ( (int)v2[153] <= 0 );
  return *(_DWORD *)v2[152];
}
