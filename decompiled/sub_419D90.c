char __stdcall sub_419D90(int a1)
{
  char v1; // bl

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = *(_BYTE *)(a1 + 647);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1;
}
