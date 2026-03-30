int __userpurge sub_42F9D0@<eax>(int a1@<edi>, int a2, int a3)
{
  int result; // eax
  int v4; // ecx
  int v5; // esi

  result = sub_42F960(a1, a2, a3);
  v4 = *(_DWORD *)(a1 + 16);
  v5 = result;
  if ( result != v4 )
  {
    if ( v4 )
      result = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 44))(v4);
    *(_DWORD *)(a1 + 16) = v5;
    if ( v5 )
      return (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 40))(v5);
  }
  return result;
}
