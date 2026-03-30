int __userpurge sub_4295B0@<eax>(int a1@<ecx>, int a2@<edi>, int a3)
{
  int v3; // esi
  int v4; // eax
  _DWORD *i; // ecx
  _DWORD *v6; // edx
  int result; // eax
  int v8; // esi
  int v9; // ecx
  int *j; // edx

  v3 = *(_DWORD *)(a1 + 92);
  v4 = 0;
  if ( v3 <= 0 )
    return 0;
  for ( i = *(_DWORD **)(a1 + 88); ; ++i )
  {
    v6 = (_DWORD *)*i;
    if ( *(_DWORD *)*i == a2 )
      break;
    if ( ++v4 >= v3 )
      return 0;
  }
  v8 = v6[408];
  v9 = 0;
  if ( v8 <= 0 )
    return 0;
  for ( j = (int *)v6[407]; ; ++j )
  {
    result = *j;
    if ( *(_DWORD *)(*j + 4) == a3 )
      break;
    if ( ++v9 >= v8 )
      return 0;
  }
  return result;
}
