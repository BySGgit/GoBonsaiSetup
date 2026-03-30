int __userpurge sub_429330@<eax>(_DWORD *a1@<esi>, int a2)
{
  int result; // eax
  int v4; // ebx
  int i; // [esp+34h] [ebp+4h]

  result = 0;
  for ( i = 0; result < *(_DWORD *)(a2 + 24); i = result )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * result);
    if ( (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, int, int, int))(**(_DWORD **)(a2 + 4) + 40))(
           *(_DWORD *)(a2 + 4),
           *a1,
           a1[1],
           a1[2],
           2,
           1,
           v4) >= 0
      && (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(a2 + 4) + 48))(
           *(_DWORD *)(a2 + 4),
           *a1,
           a1[1],
           a1[2],
           a1[3],
           v4) >= 0
      && sub_42DBC0(a1[6] + 1, (int)(a1 + 5)) >= 0 )
    {
      *(_DWORD *)(a1[5] + 4 * a1[6]++) = v4;
    }
    result = i + 1;
  }
  return result;
}
