int __cdecl CompareFunction(_DWORD *a1, _DWORD *a2)
{
  unsigned int v3; // edx
  unsigned int v4; // esi
  int v5; // edx
  int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // ecx

  if ( *a1 > *a2 )
    return 1;
  if ( *a1 < *a2 )
    return -1;
  v3 = a1[1];
  v4 = a2[1];
  if ( v3 > v4 )
    return 1;
  if ( v3 < v4 )
    return -1;
  v5 = a1[3];
  v6 = a2[3];
  if ( v5 > v6 )
    return 1;
  if ( v5 < v6 )
    return -1;
  v7 = a1[2];
  v8 = a2[2];
  if ( v7 > v8 )
    return 1;
  return -(v7 < v8);
}
