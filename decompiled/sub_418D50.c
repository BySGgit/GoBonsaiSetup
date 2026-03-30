int __usercall sub_418D50@<eax>(int a1@<esi>)
{
  void *v1; // edi
  void *v2; // eax
  int v3; // eax
  int v4; // edx

  v1 = *(void **)(a1 + 180);
  v2 = operator new(0x220u);
  if ( v2 )
    v3 = sub_417550(v1, (int)v2, *(float *)(a1 + 428), (const void *)(a1 + 240));
  else
    v3 = 0;
  *(_DWORD *)(v3 + 304) = *(_DWORD *)(a1 + 304);
  *(_DWORD *)(v3 + 308) = *(_DWORD *)(a1 + 308);
  *(_DWORD *)(v3 + 312) = *(_DWORD *)(a1 + 312);
  *(_DWORD *)(v3 + 316) = *(_DWORD *)(a1 + 316);
  *(_DWORD *)(v3 + 320) = *(_DWORD *)(a1 + 304);
  *(_DWORD *)(v3 + 324) = *(_DWORD *)(a1 + 308);
  *(_DWORD *)(v3 + 328) = *(_DWORD *)(a1 + 312);
  v4 = *(_DWORD *)v3;
  *(_DWORD *)(v3 + 332) = *(_DWORD *)(a1 + 316);
  *(float *)(v3 + 444) = *(float *)(a1 + 444);
  return (*(int (__thiscall **)(int))(v4 + 16))(v3);
}
