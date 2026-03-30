double __cdecl strtod(const char *String, char **EndPtr)
{
  return _strtod_l(String, EndPtr, 0);
}
