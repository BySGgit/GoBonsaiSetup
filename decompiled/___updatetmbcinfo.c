volatile LONG *__updatetmbcinfo()
{
  DWORD *v0; // edi
  volatile LONG *v1; // esi

  v0 = _getptd();
  if ( (dword_4C9918 & v0[28]) != 0 && v0[27] )
  {
    v1 = (volatile LONG *)v0[26];
  }
  else
  {
    _lock(13);
    v1 = (volatile LONG *)v0[26];
    if ( v1 != lpAddend )
    {
      if ( v1 && !InterlockedDecrement(v1) && v1 != (volatile LONG *)&unk_4C93F8 )
        free((void *)v1);
      v0[26] = (DWORD)lpAddend;
      v1 = lpAddend;
      InterlockedIncrement(lpAddend);
    }
    _unlock(13);
  }
  if ( !v1 )
    _amsg_exit(32);
  return v1;
}
