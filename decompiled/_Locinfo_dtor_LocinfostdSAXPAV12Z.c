void __cdecl std::_Locinfo::_Locinfo_dtor(const char **a1)
{
  if ( a1[5] )
    setlocale(0, a1[5]);
}
