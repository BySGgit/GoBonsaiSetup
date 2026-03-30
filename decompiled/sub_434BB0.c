int __usercall sub_434BB0@<eax>(int a1@<eax>, int a2@<esi>)
{
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
  *(_DWORD *)a2 = &CDXUTScrollBar::`vftable';
  *(_DWORD *)(a2 + 48) = 9;
  *(_DWORD *)(a2 + 24) = a1;
  *(_WORD *)(a2 + 80) = 1;
  SetRect((LPRECT)(a2 + 84), 0, 0, 0, 0);
  SetRect((LPRECT)(a2 + 100), 0, 0, 0, 0);
  SetRect((LPRECT)(a2 + 116), 0, 0, 0, 0);
  SetRect((LPRECT)(a2 + 132), 0, 0, 0, 0);
  *(double *)(a2 + 176) = 0.0;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 152) = 1;
  *(_DWORD *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 160) = 1;
  *(_DWORD *)(a2 + 172) = 0;
  return a2;
}
