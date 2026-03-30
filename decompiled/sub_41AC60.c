void __stdcall sub_41AC60(int a1, float a2)
{
  bool v2; // zf

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = byte_4CA649 == 0;
  *(float *)(a1 + 848) = a2;
  if ( !v2 )
    LeaveCriticalSection(&CriticalSection);
}
