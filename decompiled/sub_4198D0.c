void __stdcall sub_4198D0(int a1, int a2)
{
  bool v2; // zf

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = byte_4CA649 == 0;
  *(_DWORD *)(a1 + 568) = a2;
  if ( !v2 )
    LeaveCriticalSection(&CriticalSection);
}
