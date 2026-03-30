int __usercall sub_429B10@<eax>(int a1@<eax>)
{
  _DWORD *v1; // edi
  void *v2; // eax
  int result; // eax

  v1 = (_DWORD *)(a1 + 44);
  v2 = *(void **)(a1 + 44);
  if ( v2 )
  {
    free(v2);
    *v1 = 0;
  }
  v1[2] = 0;
  v1[1] = 0;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 0x80000000;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 0;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 1;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 2;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 4;
  result = sub_42DBC0(v1[1] + 1, (int)v1);
  if ( result >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 8;
  return result;
}
