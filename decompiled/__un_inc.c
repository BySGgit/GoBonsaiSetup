wint_t __cdecl _un_inc(wint_t Character, FILE *Stream)
{
  wint_t result; // ax

  result = -1;
  if ( Character != 0xFFFF )
    return _ungetwc_nolock(Character, Stream);
  return result;
}
