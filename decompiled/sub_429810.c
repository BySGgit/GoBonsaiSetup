int __usercall sub_429810@<eax>(int a1@<eax>)
{
  _DWORD *v1; // edi
  void *v2; // eax
  int result; // eax

  v1 = (_DWORD *)(a1 + 20);
  v2 = *(void **)(a1 + 20);
  if ( v2 )
  {
    free(v2);
    *v1 = 0;
  }
  v1[2] = 0;
  v1[1] = 0;
  if ( sub_42DBC0(1u, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 80;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 73;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 77;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 75;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 79;
  result = sub_42DBC0(v1[1] + 1, (int)v1);
  if ( result >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 71;
  return result;
}
