int __cdecl _fileno(FILE *Stream)
{
  if ( Stream )
    return Stream->_file;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}
