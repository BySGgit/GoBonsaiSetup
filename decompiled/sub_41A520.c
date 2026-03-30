char __stdcall sub_41A520(int a1)
{
  char v1; // bl

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = *(_BYTE *)(a1 + 777);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1;
}
