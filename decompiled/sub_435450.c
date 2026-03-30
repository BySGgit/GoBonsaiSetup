int __stdcall sub_435450(int a1, int a2)
{
  int v3; // edx
  bool v4; // zf
  double QuadPart; // st7
  double v6; // st6
  LARGE_INTEGER PerformanceCount; // [esp+14h] [ebp-18h] BYREF
  int v9; // [esp+28h] [ebp-4h]
  UINT CaretBlinkTime; // [esp+30h] [ebp+4h]

  *(_DWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 40) = 0;
  *(_DWORD *)(a1 + 48) = 0;
  *(_DWORD *)(a1 + 44) = 0;
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 56) = 0;
  *(_BYTE *)(a1 + 60) = 1;
  *(_DWORD *)(a1 + 4) = 1;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 68) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  *(_DWORD *)(a1 + 76) = 0;
  v9 = 0;
  *(_DWORD *)a1 = &CDXUTEditBox::`vftable';
  sub_4369B0();
  *(_DWORD *)(a1 + 84) = 0;
  *(_DWORD *)(a1 + 80) = 0;
  *(_BYTE *)(a1 + 92) = 1;
  *(_DWORD *)(a1 + 96) = 0;
  *(_DWORD *)(a1 + 88) = 0;
  sub_436A80(1, v3, a1 + 80);
  *(_DWORD *)(a1 + 48) = 6;
  *(_DWORD *)(a1 + 24) = a2;
  *(_DWORD *)(a1 + 100) = 5;
  *(_DWORD *)(a1 + 104) = 4;
  *(_BYTE *)(a1 + 288) = 1;
  CaretBlinkTime = GetCaretBlinkTime();
  v4 = (dword_4D8DF8 & 1) == 0;
  *(double *)(a1 + 272) = (double)CaretBlinkTime * 0.001000000047497451;
  if ( v4 )
  {
    dword_4D8DF8 |= 1u;
    sub_4375D0();
  }
  PerformanceCount.QuadPart = 0;
  QueryPerformanceCounter(&PerformanceCount);
  QuadPart = (double)PerformanceCount.QuadPart;
  v6 = (double)qword_4D8DD8;
  byte_4D7DEC = 0;
  *(_DWORD *)(a1 + 304) = 0;
  *(_DWORD *)(a1 + 308) = -15724528;
  *(_DWORD *)(a1 + 312) = -1;
  *(_DWORD *)(a1 + 316) = -14142884;
  *(_DWORD *)(a1 + 320) = -16777216;
  *(_DWORD *)(a1 + 300) = 0;
  *(_DWORD *)(a1 + 292) = 0;
  *(_BYTE *)(a1 + 296) = 1;
  *(_BYTE *)(a1 + 324) = 0;
  *(double *)(a1 + 280) = QuadPart / v6;
  return a1;
}
