double __stdcall sub_41A2A0(int a1)
{
  float v2; // [esp+4h] [ebp+4h]

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = *(float *)(a1 + 760);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v2;
}
