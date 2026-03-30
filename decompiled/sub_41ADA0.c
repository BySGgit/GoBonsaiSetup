void __stdcall sub_41ADA0(int a1)
{
  bool v1; // zf

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = byte_4CA649 == 0;
  *(_BYTE *)(a1 + 860) = 1;
  if ( !v1 )
    LeaveCriticalSection(&CriticalSection);
}
