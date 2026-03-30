char __stdcall sub_4197D0(int a1)
{
  char v1; // bl

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = *(_BYTE *)(a1 + 412);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1;
}
