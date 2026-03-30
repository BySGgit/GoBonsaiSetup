void __cdecl _unlock_file(FILE *Stream)
{
  if ( Stream < (FILE *)&off_4C9F00 || Stream > &stru_4CA160 )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)&Stream[1]);
  }
  else
  {
    Stream->_flag &= ~0x8000u;
    _unlock((((char *)Stream - (char *)&off_4C9F00) >> 5) + 16);
  }
}
