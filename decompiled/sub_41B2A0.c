void __stdcall sub_41B2A0(int a1, int a2)
{
  bool v2; // zf

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = byte_4CA649 == 0;
  *(_DWORD *)(a1 + 1528) = a2;
  if ( !v2 )
    LeaveCriticalSection(&CriticalSection);
}
