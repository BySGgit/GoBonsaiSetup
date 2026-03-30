void __stdcall sub_419E50(int a1, double a2)
{
  bool v2; // zf

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = byte_4CA649 == 0;
  *(double *)(a1 + 680) = a2;
  if ( !v2 )
    LeaveCriticalSection(&CriticalSection);
}
