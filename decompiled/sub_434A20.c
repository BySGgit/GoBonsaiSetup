int __userpurge sub_434A20@<eax>(int result@<eax>, _DWORD *a2@<esi>, char a3)
{
  int (__stdcall *v3)(int, _DWORD, _DWORD *, _DWORD); // ecx

  if ( a2[21] > result )
    result = a2[21];
  if ( a2[22] < result )
    result = a2[22];
  if ( result != a2[20] )
  {
    a2[20] = result;
    (*(void (__thiscall **)(_DWORD *))(*a2 + 76))(a2);
    result = a2[6];
    v3 = *(int (__stdcall **)(int, _DWORD, _DWORD *, _DWORD))(result + 576);
    if ( v3 )
    {
      if ( a3 || *(_BYTE *)result )
        return v3(1281, a2[11], a2, *(_DWORD *)(result + 580));
    }
  }
  return result;
}
