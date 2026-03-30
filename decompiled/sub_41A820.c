int __stdcall sub_41A820(int a1)
{
  int v1; // esi

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = *(_DWORD *)(a1 + 804);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v1;
}
