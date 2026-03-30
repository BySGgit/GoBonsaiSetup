int __userpurge sub_4293C0@<eax>(_DWORD *a1@<esi>, unsigned int a2)
{
  unsigned int v2; // ebx
  int result; // eax
  int v4; // ebp
  int i; // [esp+1Ch] [ebp-4h]

  v2 = a2;
  result = 0;
  for ( i = 0; result < *(_DWORD *)(v2 + 36); i = result )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(v2 + 32) + 4 * result);
    if ( (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, unsigned int *))(**(_DWORD **)(v2 + 4) + 44))(
           *(_DWORD *)(v2 + 4),
           *a1,
           a1[1],
           a1[3],
           a1[4],
           v4,
           &a2) >= 0 )
    {
      if ( sub_42DBC0(a1[9] + 1, (int)(a1 + 8)) >= 0 )
        *(_DWORD *)(a1[8] + 4 * a1[9]++) = v4;
      if ( a2 > *(_DWORD *)(v2 + 84) + 1 )
        a2 = *(_DWORD *)(v2 + 84) + 1;
      if ( sub_42DBC0(a1[12] + 1, (int)(a1 + 11)) >= 0 )
        *(_DWORD *)(a1[11] + 4 * a1[12]++) = a2;
    }
    result = i + 1;
  }
  return result;
}
