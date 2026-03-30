unsigned int *__cdecl __doserrno()
{
  int v0; // eax

  v0 = _getptd_noexit();
  if ( v0 )
    return (unsigned int *)(v0 + 12);
  else
    return (unsigned int *)&unk_4C93D4;
}
