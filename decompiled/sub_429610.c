int __userpurge sub_429610@<eax>(int a1@<eax>, int a2@<ecx>, int a3, int a4, int a5, int a6)
{
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  int *i; // edx
  int result; // eax

  v6 = sub_4295B0(a2, a3, a1);
  if ( !v6 )
    return 0;
  v7 = *(_DWORD *)(v6 + 316);
  v8 = 0;
  if ( v7 <= 0 )
    return 0;
  for ( i = *(int **)(v6 + 312); ; ++i )
  {
    result = *i;
    if ( *(_DWORD *)(*i + 8) == a4 && *(_DWORD *)(result + 12) == a5 && *(_DWORD *)(result + 16) == a6 )
      break;
    if ( ++v8 >= v7 )
      return 0;
  }
  return result;
}
