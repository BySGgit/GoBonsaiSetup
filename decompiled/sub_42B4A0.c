int __usercall sub_42B4A0@<eax>(int a1@<esi>)
{
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  *(_BYTE *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_BYTE *)(a1 + 52) = 0;
  *(_DWORD *)(a1 + 40) = 0;
  *(_DWORD *)(a1 + 24) = 640;
  *(_DWORD *)(a1 + 32) = 480;
  *(_DWORD *)(a1 + 28) = -1;
  *(_DWORD *)(a1 + 36) = -1;
  *(_DWORD *)(a1 + 44) = -1;
  sub_42C130(a1);
  return a1;
}
