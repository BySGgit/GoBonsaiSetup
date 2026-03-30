std::_Init_locks *__thiscall std::_Init_locks::_Init_locks(std::_Init_locks *this)
{
  struct _RTL_CRITICAL_SECTION *v2; // esi

  if ( !InterlockedIncrement(&Addend) )
  {
    v2 = &stru_4D6D38;
    do
      _Mtxinit(v2++);
    while ( (int)v2 < (int)&unk_4D6D98 );
  }
  return this;
}
