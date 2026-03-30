double *__userpurge sub_437680@<eax>(int a1@<esi>, double *a2, double *a3, float *a4)
{
  DWORD LowPart; // edx
  LONG HighPart; // ecx
  double v6; // st7
  double v7; // st6
  double v9; // st6
  float v10; // [esp+8h] [ebp-10h]
  LARGE_INTEGER PerformanceCount; // [esp+10h] [ebp-8h] BYREF

  LowPart = *(_DWORD *)(a1 + 16);
  HighPart = *(_DWORD *)(a1 + 20);
  if ( *(_QWORD *)(a1 + 16) )
  {
    PerformanceCount.QuadPart = __PAIR64__(HighPart, LowPart);
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    HighPart = PerformanceCount.HighPart;
    LowPart = PerformanceCount.LowPart;
  }
  v6 = (double)*(__int64 *)(a1 + 8);
  v7 = (double)(__int64)(__PAIR64__(HighPart, LowPart) - *(_QWORD *)(a1 + 24));
  *(_DWORD *)(a1 + 24) = LowPart;
  *(_DWORD *)(a1 + 28) = HighPart;
  v10 = v7 / v6;
  if ( v10 < 0.0 )
    v10 = 0.0;
  v9 = (double)PerformanceCount.QuadPart / v6;
  PerformanceCount.QuadPart = __PAIR64__(HighPart, LowPart) - *(_QWORD *)(a1 + 32);
  *a3 = v9;
  *a2 = (double)PerformanceCount.QuadPart / v6;
  *a4 = v10;
  return a3;
}
