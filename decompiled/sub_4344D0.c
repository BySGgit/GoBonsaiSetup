int __usercall sub_4344D0@<eax>(_DWORD *a1@<eax>, int a2@<esi>)
{
  int v2; // ecx
  int i; // edx
  int v5; // ecx
  void (__stdcall *v6)(int, _DWORD, _DWORD *, _DWORD); // edx

  v2 = 0;
  if ( (int)a1[219] <= 0 )
    return -2147467259;
  for ( i = a1[218]; *(_DWORD *)(*(_DWORD *)i + 512) != a2; i += 4 )
  {
    if ( ++v2 >= a1[219] )
      return -2147467259;
  }
  a1[151] = v2;
  a1[152] = v2;
  v5 = a1[6];
  v6 = *(void (__stdcall **)(int, _DWORD, _DWORD *, _DWORD))(v5 + 576);
  if ( v6 )
  {
    if ( *(_BYTE *)v5 )
      v6(513, a1[11], a1, *(_DWORD *)(v5 + 580));
  }
  return 0;
}
