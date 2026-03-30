int __cdecl _wtol(const wchar_t *String)
{
  return wcstol(String, 0, 10);
}
