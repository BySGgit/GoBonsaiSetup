int __usercall sub_4298F0@<eax>(int a1@<eax>)
{
  int *v1; // edi
  void *v2; // eax
  int result; // eax

  v1 = (int *)(a1 + 32);
  v2 = *(void **)(a1 + 32);
  if ( v2 )
  {
    free(v2);
    *v1 = 0;
  }
  v1[2] = 0;
  v1[1] = 0;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 0;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 1;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 2;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 3;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 4;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 5;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 6;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 7;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 8;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 9;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 10;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 11;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 12;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 13;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 14;
  if ( sub_42DBC0(v1[1] + 1, (int)v1) >= 0 )
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 15;
  result = sub_42DBC0(v1[1] + 1, (int)v1);
  if ( result >= 0 )
  {
    result = *v1;
    *(_DWORD *)(*v1 + 4 * v1[1]++) = 16;
  }
  return result;
}
