BOOL __thiscall sub_435EE0(int this)
{
  BOOL result; // eax
  LARGE_INTEGER PerformanceCount; // [esp+4h] [ebp-8h] BYREF

  *(_BYTE *)(this + 6) = 1;
  *(_BYTE *)(this + 288) = 1;
  if ( (dword_4D8DF8 & 1) == 0 )
  {
    dword_4D8DF8 |= 1u;
    sub_4375D0();
  }
  PerformanceCount.QuadPart = 0;
  result = QueryPerformanceCounter(&PerformanceCount);
  *(double *)(this + 280) = (double)PerformanceCount.QuadPart / (double)qword_4D8DD8;
  return result;
}
