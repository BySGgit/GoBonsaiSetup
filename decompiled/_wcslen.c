size_t __cdecl wcslen(const wchar_t *String)
{
  const wchar_t *v1; // eax

  v1 = String;
  while ( *v1++ )
    ;
  return v1 - String - 1;
}
