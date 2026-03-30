errno_t __cdecl memmove_s(
        void *const Destination,
        const rsize_t DestinationSize,
        const void *const Source,
        const rsize_t SourceSize)
{
  errno_t v4; // esi

  if ( SourceSize )
  {
    if ( !Destination || !Source )
    {
      v4 = 22;
      *_errno() = 22;
LABEL_4:
      _invalid_parameter_noinfo();
      return v4;
    }
    if ( DestinationSize < SourceSize )
    {
      *_errno() = 34;
      v4 = 34;
      goto LABEL_4;
    }
    memcpy(Destination, Source, SourceSize);
  }
  return 0;
}
