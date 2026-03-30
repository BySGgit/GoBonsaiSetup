int __cdecl _fflush_nolock(FILE *Stream)
{
  int v2; // eax

  if ( !Stream )
    return flsall(0);
  if ( _flush(Stream) )
    return -1;
  if ( (Stream->_flag & 0x4000) == 0 )
    return 0;
  v2 = _fileno(Stream);
  return -(_commit(v2) != 0);
}
