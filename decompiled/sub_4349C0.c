int __usercall sub_4349C0@<eax>(_DWORD *a1@<esi>)
{
  int v1; // ecx
  int result; // eax
  int (__stdcall *v3)(int, _DWORD, _DWORD *, _DWORD); // ecx

  v1 = a1[20];
  result = v1;
  a1[21] = 0;
  a1[22] = 1000;
  if ( v1 >= 0 )
  {
    if ( v1 > 1000 )
      result = 1000;
  }
  else
  {
    result = 0;
  }
  if ( result != v1 )
  {
    a1[20] = result;
    (*(void (__thiscall **)(_DWORD *))(*a1 + 76))(a1);
    result = a1[6];
    v3 = *(int (__stdcall **)(int, _DWORD, _DWORD *, _DWORD))(result + 576);
    if ( v3 )
    {
      if ( *(_BYTE *)result )
        return v3(1281, a1[11], a1, *(_DWORD *)(result + 580));
    }
  }
  return result;
}
