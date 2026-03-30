int __cdecl ___mb_cur_max_l_func(_locale_t Locale)
{
  if ( Locale )
    return *((_DWORD *)Locale->locinfo + 43);
  else
    return ___mb_cur_max_func();
}
