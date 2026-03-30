int __usercall sub_432780@<eax>(int a1@<eax>, int a2@<esi>)
{
  int i; // edi
  int v3; // edx

  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_BYTE *)(a2 + 60) = 1;
  *(_DWORD *)(a2 + 4) = 1;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 76) = 0;
  *(_DWORD *)a2 = &CDXUTStatic::`vftable';
  *(_DWORD *)(a2 + 48) = 1;
  *(_DWORD *)(a2 + 24) = a1;
  memset((void *)(a2 + 80), 0, 0x208u);
  for ( i = 0; i < *(_DWORD *)(a2 + 36); ++i )
  {
    v3 = *(_DWORD *)(a2 + 32);
    if ( *(_DWORD *)(v3 + 4 * i) )
      operator delete(*(void **)(v3 + 4 * i));
  }
  if ( *(_DWORD *)(a2 + 32) )
  {
    free(*(void **)(a2 + 32));
    *(_DWORD *)(a2 + 32) = 0;
  }
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  return a2;
}
