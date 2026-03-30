int __usercall sub_42C130@<eax>(int a1@<eax>)
{
  _DWORD *v1; // edi
  void *v2; // eax
  int result; // eax

  v1 = (_DWORD *)(a1 + 12);
  v2 = *(void **)(a1 + 12);
  if ( v2 )
  {
    free(v2);
    *v1 = 0;
  }
  v1[2] = 0;
  v1[1] = 0;
  if ( sub_42DBC0(1u, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 20;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 40;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 45;
  result = sub_42DBC0(v1[1] + 1, (int)v1);
  if ( result >= 0 )
  {
    result = v1[1];
    *(_DWORD *)(*v1 + 4 * result) = 55;
    ++v1[1];
  }
  return result;
}
