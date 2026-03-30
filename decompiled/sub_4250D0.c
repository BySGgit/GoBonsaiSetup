void __stdcall sub_4250D0(char a1, char a2)
{
  _DWORD *EngineInstance; // esi
  int v3; // esi
  int v4; // ebp
  _DWORD *v5; // esi
  _DWORD *v6; // esi
  int v7; // esi
  int v8; // edi
  _DWORD *v9; // esi
  _BYTE *v10; // esi
  _BYTE *v11; // esi
  LARGE_INTEGER PerformanceCount; // [esp+10h] [ebp-Ch] BYREF
  int v13; // [esp+20h] [ebp+4h]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = EngineInstance[198];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v4 = v3 + 1;
  if ( !a1 )
    v4 = v3 - 1;
  v13 = v4;
  if ( v4 < 0 )
  {
    v4 = 0;
    v13 = 0;
  }
  v5 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5[198] = v4;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v6 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = v6[197];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v8 = v7 + 1;
  if ( !a2 )
    v8 = v7 - 1;
  if ( v8 < 0 )
    v8 = 0;
  v9 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v9[197] = v8;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v4 <= 0 )
  {
    if ( (dword_4D8DF8 & 1) == 0 )
    {
      dword_4D8DF8 |= 1u;
      sub_4375D0();
    }
    PerformanceCount.QuadPart = 0;
    QueryPerformanceCounter(&PerformanceCount);
    if ( byte_4D8DD1 )
    {
      v4 = v13;
      qword_4D8DF0 += PerformanceCount.QuadPart - qword_4D8DE0;
    }
    qword_4D8DE0 = 0;
    qword_4D8DE8 = PerformanceCount.QuadPart;
    byte_4D8DD1 = 0;
  }
  else
  {
    if ( (dword_4D8DF8 & 1) == 0 )
    {
      dword_4D8DF8 |= 1u;
      sub_4375D0();
    }
    if ( !byte_4D8DD1 )
    {
      PerformanceCount.QuadPart = 0;
      QueryPerformanceCounter(&PerformanceCount);
      qword_4D8DE0 = PerformanceCount.QuadPart;
      qword_4D8DE8 = PerformanceCount.QuadPart;
      byte_4D8DD1 = 1;
    }
  }
  v10 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v10[784] = v8 > 0;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v11 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v11[783] = v4 > 0;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
}
