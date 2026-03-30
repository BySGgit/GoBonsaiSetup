void __cdecl std::_Locinfo::_Locinfo_ctor(void **a1, char *Locale)
{
  char *v2; // eax
  char *v3; // eax

  v2 = setlocale(0, 0);
  if ( !v2 )
    v2 = (char *)&unk_4BC05D;
  std::_Yarn<char>::operator=(a1 + 5, v2);
  if ( !Locale || (v3 = setlocale(0, Locale)) == 0 )
    v3 = (char *)&unk_4735B0;
  std::_Yarn<char>::operator=(a1 + 7, v3);
}
