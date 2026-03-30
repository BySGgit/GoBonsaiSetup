int __usercall sub_44DE80@<eax>(int a1@<esi>)
{
  int v1; // eax
  int v2; // edi
  _DWORD *v3; // ecx
  int v4; // eax
  int v5; // eax

  v1 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  v2 = 0;
  if ( (*(_BYTE *)(v1 + a1 + 12) & 6) == 0
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v1 + a1 + 56) + 52))(*(_DWORD *)(v1 + a1 + 56)) == -1 )
  {
    v2 = 4;
  }
  v3 = (_DWORD *)(a1 + *(_DWORD *)(*(_DWORD *)a1 + 4));
  if ( v2 )
  {
    v4 = v2 | v3[3];
    if ( !v3[14] )
      LOBYTE(v4) = v4 | 4;
    v5 = v4 & 0x17;
    v3[3] = v5;
    if ( (v5 & v3[4]) != 0 )
      sub_44DDA0(0);
  }
  return a1;
}
