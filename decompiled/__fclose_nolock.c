int __cdecl _fclose_nolock(FILE *Stream)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( Stream )
  {
    if ( (Stream->_flag & 0x83) != 0 )
    {
      v1 = _flush(Stream);
      _freebuf(Stream);
      v3 = _fileno(Stream);
      if ( _close(v3) >= 0 )
      {
        if ( Stream->_tmpfname )
        {
          free(Stream->_tmpfname);
          Stream->_tmpfname = 0;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    Stream->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}
