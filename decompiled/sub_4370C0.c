BOOL __usercall sub_4370C0@<eax>(int a1@<esi>)
{
  BOOL result; // eax
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-Ch] BYREF

  *(_BYTE *)(a1 + 288) = 1;
  if ( (dword_4D8DF8 & 1) == 0 )
  {
    dword_4D8DF8 |= 1u;
    sub_4375D0();
  }
  PerformanceCount.QuadPart = 0;
  result = QueryPerformanceCounter(&PerformanceCount);
  *(double *)(a1 + 280) = (double)PerformanceCount.QuadPart / (double)qword_4D8DD8;
  return result;
}
