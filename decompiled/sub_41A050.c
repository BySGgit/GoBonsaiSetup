void __userpurge sub_41A050(_DWORD *a1@<esi>, int a2, int a3, int a4, int a5, int a6, int a7)
{
  bool v7; // zf

  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = byte_4CA649 == 0;
  a1[181] = a2;
  a1[182] = a3;
  a1[183] = a4;
  a1[184] = a5;
  a1[185] = a6;
  a1[186] = a7;
  if ( !v7 )
    LeaveCriticalSection(&CriticalSection);
}
