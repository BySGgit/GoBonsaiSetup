void __stdcall _freefls(void *Block)
{
  void *v1; // edi
  volatile LONG *v2; // edi
  int savedregs; // [esp+28h] [ebp+0h]

  if ( Block )
  {
    if ( *((_DWORD *)Block + 9) )
      free(*((void **)Block + 9));
    if ( *((_DWORD *)Block + 11) )
      free(*((void **)Block + 11));
    if ( *((_DWORD *)Block + 13) )
      free(*((void **)Block + 13));
    if ( *((_DWORD *)Block + 15) )
      free(*((void **)Block + 15));
    if ( *((_DWORD *)Block + 16) )
      free(*((void **)Block + 16));
    if ( *((_DWORD *)Block + 17) )
      free(*((void **)Block + 17));
    if ( *((_DWORD *)Block + 18) )
      free(*((void **)Block + 18));
    if ( *((_UNKNOWN **)Block + 23) != &unk_474EA8 )
      free(*((void **)Block + 23));
    _lock(13);
    v1 = (void *)*((_DWORD *)Block + 26);
    if ( v1 && !InterlockedDecrement(*((volatile LONG **)Block + 26)) && v1 != &unk_4C93F8 )
      free(v1);
    _unlock(13);
    _lock(12);
    v2 = (volatile LONG *)*((_DWORD *)Block + 27);
    if ( v2 )
    {
      __removelocaleref(*((volatile LONG **)Block + 27));
      if ( v2 != off_4C9B60 && v2 != dword_4C9A88 && !*v2 )
        __freetlocinfo((void *)v2);
    }
    savedregs = 4563941;
    _unlock(12);
    free(Block);
  }
}
