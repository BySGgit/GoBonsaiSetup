_BYTE *_FF_MSGBANNER()
{
  _BYTE *result; // eax

  if ( _set_error_mode(3) == 1 || (result = (_BYTE *)_set_error_mode(3)) == 0 && dword_4C9230 == 1 )
  {
    _NMSG_WRITE(252);
    return _NMSG_WRITE(255);
  }
  return result;
}
