int __usercall sub_4301A0@<eax>(int a1@<eax>, int a2@<edi>)
{
  int v2; // esi
  int v3; // ecx
  int *i; // edx
  int result; // eax

  v2 = *(_DWORD *)(a1 + 612);
  v3 = 0;
  if ( v2 <= 0 )
    return 0;
  for ( i = *(int **)(a1 + 608); ; ++i )
  {
    result = *i;
    if ( *(_DWORD *)(*i + 44) == a2 )
      break;
    if ( ++v3 >= v2 )
      return 0;
  }
  return result;
}
