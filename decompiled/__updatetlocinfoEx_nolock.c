volatile LONG *__cdecl _updatetlocinfoEx_nolock(volatile LONG **a1, volatile LONG *lpAddend)
{
  volatile LONG *v2; // esi

  if ( !lpAddend || !a1 )
    return 0;
  v2 = *a1;
  if ( *a1 != lpAddend )
  {
    *a1 = lpAddend;
    __addlocaleref(lpAddend);
    if ( v2 )
    {
      __removelocaleref(v2);
      if ( !*v2 && v2 != dword_4C9A88 )
        __freetlocinfo((char *)v2);
    }
  }
  return lpAddend;
}
