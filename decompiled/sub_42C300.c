int __userpurge sub_42C300@<eax>(int a1@<edx>, int a2@<edi>, int a3, int a4)
{
  int v4; // ecx
  int v5; // eax
  _DWORD *i; // esi
  _DWORD *v7; // edx
  int result; // eax
  int v9; // esi
  int v10; // ecx
  int *j; // edx

  v4 = *(_DWORD *)(a1 + 60);
  v5 = 0;
  if ( v4 <= 0 )
    return 0;
  for ( i = *(_DWORD **)(a1 + 56); ; ++i )
  {
    v7 = (_DWORD *)*i;
    if ( *(_DWORD *)*i == a2 )
      break;
    if ( ++v5 >= v4 )
      return 0;
  }
  v9 = v7[146];
  v10 = 0;
  if ( v9 <= 0 )
    return 0;
  for ( j = (int *)v7[145]; ; ++j )
  {
    result = *j;
    if ( *(_DWORD *)(*j + 8) == a3 && *(_DWORD *)(result + 12) == a4 )
      break;
    if ( ++v10 >= v9 )
      return 0;
  }
  return result;
}
