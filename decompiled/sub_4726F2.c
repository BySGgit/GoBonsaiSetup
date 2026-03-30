LONG sub_4726F2()
{
  LONG result; // eax
  struct _RTL_CRITICAL_SECTION *v1; // esi

  result = InterlockedDecrement(&Addend);
  if ( result < 0 )
  {
    v1 = &stru_4D6D38;
    do
      result = _Mtxdst(v1++);
    while ( (int)v1 < (int)&unk_4D6D98 );
  }
  return result;
}
