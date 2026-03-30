void __stdcall sub_419D50(int a1, char a2)
{
  bool v2; // zf

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = byte_4CA649 == 0;
  *(_BYTE *)(a1 + 647) = a2;
  if ( !v2 )
    LeaveCriticalSection(&CriticalSection);
}
