volatile LONG *__cdecl __removelocaleref(volatile LONG *lpAddend)
{
  volatile LONG **v2; // ebx
  int lpAddenda; // [esp+Ch] [ebp+8h]

  if ( lpAddend )
  {
    InterlockedDecrement(lpAddend);
    if ( *((_DWORD *)lpAddend + 44) )
      InterlockedDecrement(*((volatile LONG **)lpAddend + 44));
    if ( *((_DWORD *)lpAddend + 46) )
      InterlockedDecrement(*((volatile LONG **)lpAddend + 46));
    if ( *((_DWORD *)lpAddend + 45) )
      InterlockedDecrement(*((volatile LONG **)lpAddend + 45));
    if ( *((_DWORD *)lpAddend + 48) )
      InterlockedDecrement(*((volatile LONG **)lpAddend + 48));
    v2 = (volatile LONG **)(lpAddend + 20);
    lpAddenda = 6;
    do
    {
      if ( *(v2 - 2) != (volatile LONG *)Str2 && *v2 )
        InterlockedDecrement(*v2);
      if ( *(v2 - 1) && v2[1] )
        InterlockedDecrement(v2[1]);
      v2 += 4;
      --lpAddenda;
    }
    while ( lpAddenda );
    InterlockedDecrement((volatile LONG *)(*((_DWORD *)lpAddend + 53) + 180));
  }
  return lpAddend;
}
