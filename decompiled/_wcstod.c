double __cdecl wcstod(const wchar_t *String, wchar_t **EndPtr)
{
  return _wcstod_l(String, EndPtr, 0);
}
