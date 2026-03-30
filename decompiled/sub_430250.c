int __userpurge sub_430250@<eax>(int a1@<edi>, int a2)
{
  int i; // esi
  int result; // eax
  _DWORD *v4; // ecx

  for ( i = 0; i < *(_DWORD *)(a1 + 612); ++i )
  {
    result = *(_DWORD *)(a1 + 608);
    v4 = *(_DWORD **)(result + 4 * i);
    if ( v4[12] == 3 && v4[160] == a2 )
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD, _DWORD))(*v4 + 84))(v4, 0, 0, 0);
  }
  return result;
}
