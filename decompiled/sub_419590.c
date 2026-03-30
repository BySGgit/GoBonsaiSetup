int __stdcall sub_419590(int *a1)
{
  int v1; // esi

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = *a1;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1;
}
