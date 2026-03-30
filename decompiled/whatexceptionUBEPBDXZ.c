const char *__thiscall exception::what(exception *this)
{
  const char *result; // eax

  result = (const char *)*((_DWORD *)this + 1);
  if ( !result )
    return "Unknown exception";
  return result;
}
