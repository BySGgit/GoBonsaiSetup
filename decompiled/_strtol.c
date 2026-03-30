int __cdecl strtol(const char *String, char **EndPtr, int Radix)
{
  if ( dword_4D6F30 )
    return strtoxl(0, String, (const char **)EndPtr, Radix, 0);
  else
    return strtoxl((struct localeinfo_struct *)&off_4C9B64, String, (const char **)EndPtr, Radix, 0);
}
