int __cdecl _set_error_mode(int Mode)
{
  int result; // eax

  if ( Mode >= 0 )
  {
    if ( Mode <= 2 )
    {
      result = dword_4D6F2C;
      dword_4D6F2C = Mode;
      return result;
    }
    if ( Mode == 3 )
      return dword_4D6F2C;
  }
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}
