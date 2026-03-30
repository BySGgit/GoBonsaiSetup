void __cdecl _lock_file(FILE *Stream)
{
  if ( Stream < (FILE *)&off_4C9F00 || Stream > &stru_4CA160 )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&Stream[1]);
  }
  else
  {
    _lock((((char *)Stream - (char *)&off_4C9F00) >> 5) + 16);
    Stream->_flag |= 0x8000u;
  }
}
