size_t __cdecl wcsnlen(const wchar_t *Source, size_t MaxCount)
{
  size_t result; // eax

  for ( result = 0; result < MaxCount; ++Source )
  {
    if ( !*Source )
      break;
    ++result;
  }
  return result;
}
