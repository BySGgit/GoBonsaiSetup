int __stdcall sub_419B10(int a1)
{
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return a1 + 600;
}
