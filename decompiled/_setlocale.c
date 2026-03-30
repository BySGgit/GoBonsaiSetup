char *__cdecl setlocale(int Category, const char *Locale)
{
  int v3; // esi
  volatile LONG *v4; // ebx
  char *v5; // [esp+14h] [ebp-20h]

  v5 = 0;
  if ( (unsigned int)Category <= 5 )
  {
    v3 = _getptd();
    __updatetlocinfo();
    *(_DWORD *)(v3 + 112) |= 0x10u;
    v4 = (volatile LONG *)_calloc_crt(216, 1);
    if ( v4 )
    {
      _lock(12);
      _copytlocinfo_nolock(v4, *(_DWORD **)(v3 + 108));
      _unlock(12);
      v5 = _setlocale_nolock(Category, v4, (char *)Locale);
      if ( v5 )
      {
        if ( Locale && strcmp(Locale, Str2) )
          dword_4D6F30 = 1;
        _lock(12);
        _updatetlocinfoEx_nolock(v3 + 108, v4);
        __removelocaleref(v4);
        if ( (*(_BYTE *)(v3 + 112) & 2) == 0 && (dword_4C9918 & 1) == 0 )
        {
          _updatetlocinfoEx_nolock((int)&off_4C9B60, *(volatile LONG **)(v3 + 108));
          off_4C9228 = (char **)*((_DWORD *)off_4C9B60 + 47);
          off_4C93D8 = (wchar_t *)*((_DWORD *)off_4C9B60 + 50);
          dword_4C9DA4 = *((_DWORD *)off_4C9B60 + 43);
        }
        _unlock(12);
      }
      else
      {
        __removelocaleref(v4);
        __freetlocinfo((void *)v4);
      }
    }
    *(_DWORD *)(v3 + 112) &= ~0x10u;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
}
