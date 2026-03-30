int __usercall sub_437640@<eax>(int a1@<esi>)
{
  DWORD LowPart; // ecx
  LONG HighPart; // eax
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-Ch] BYREF

  LowPart = *(_DWORD *)(a1 + 16);
  HighPart = *(_DWORD *)(a1 + 20);
  if ( !*(_QWORD *)(a1 + 16) )
  {
    QueryPerformanceCounter(&PerformanceCount);
    HighPart = PerformanceCount.HighPart;
    LowPart = PerformanceCount.LowPart;
  }
  *(_DWORD *)(a1 + 36) = HighPart;
  *(_DWORD *)(a1 + 28) = HighPart;
  *(_DWORD *)(a1 + 32) = LowPart;
  *(_DWORD *)(a1 + 24) = LowPart;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_BYTE *)(a1 + 1) = 0;
  return 0;
}
