void __cdecl std::locale::_Setgloballocale(void *a1)
{
  if ( !byte_4D6DC5 )
  {
    byte_4D6DC5 = 1;
    _Atexit(tidy_global);
  }
  dword_4D6DA0 = (int)a1;
}
