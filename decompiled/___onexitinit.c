int __onexitinit()
{
  _DWORD *v0; // esi

  v0 = (_DWORD *)_calloc_crt(32, 4);
  Ptr = EncodePointer(v0);
  dword_4DD044 = Ptr;
  if ( !v0 )
    return 24;
  *v0 = 0;
  return 0;
}
