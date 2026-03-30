wchar_t *__cdecl wcsstr(const wchar_t *Str, const wchar_t *SubStr)
{
  wchar_t *result; // eax
  wchar_t *v3; // edi
  wchar_t v4; // dx
  int i; // eax
  const wchar_t *v6; // ecx
  int v7; // edx

  result = (wchar_t *)Str;
  v3 = (wchar_t *)Str;
  if ( *SubStr )
  {
    if ( *Str )
    {
      v4 = *Str;
      for ( i = (char *)Str - (char *)SubStr; ; i += 2 )
      {
        v6 = SubStr;
        if ( v4 )
          break;
LABEL_8:
        if ( !*v6 )
          return v3;
        v4 = *++v3;
        if ( !*v3 )
          return 0;
      }
      while ( 1 )
      {
        v7 = *v6;
        if ( !(_WORD)v7 )
          return v3;
        if ( *(const wchar_t *)((char *)v6 + i) == v7 )
        {
          if ( *(const wchar_t *)((char *)++v6 + i) )
            continue;
        }
        goto LABEL_8;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
