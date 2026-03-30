int __cdecl wcstol(const wchar_t *String, wchar_t **EndPtr, int Radix)
{
  return wcstoxl(String, (const wchar_t **)EndPtr, Radix, 0);
}
