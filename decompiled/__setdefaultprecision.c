errno_t _setdefaultprecision()
{
  errno_t result; // eax

  result = _controlfp_s(0, 0x10000u, 0x30000u);
  if ( result )
    _invoke_watson(0, 0, 0, 0, 0);
  return result;
}
