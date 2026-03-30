LONG __cdecl __addlocaleref(volatile LONG *lpAddend)
{
  volatile LONG **v2; // ebx
  int lpAddenda; // [esp+14h] [ebp+8h]

  InterlockedIncrement(lpAddend);
  if ( *((_DWORD *)lpAddend + 44) )
    InterlockedIncrement(*((volatile LONG **)lpAddend + 44));
  if ( *((_DWORD *)lpAddend + 46) )
    InterlockedIncrement(*((volatile LONG **)lpAddend + 46));
  if ( *((_DWORD *)lpAddend + 45) )
    InterlockedIncrement(*((volatile LONG **)lpAddend + 45));
  if ( *((_DWORD *)lpAddend + 48) )
    InterlockedIncrement(*((volatile LONG **)lpAddend + 48));
  v2 = (volatile LONG **)(lpAddend + 20);
  lpAddenda = 6;
  do
  {
    if ( *(v2 - 2) != (volatile LONG *)Str2 && *v2 )
      InterlockedIncrement(*v2);
    if ( *(v2 - 1) && v2[1] )
      InterlockedIncrement(v2[1]);
    v2 += 4;
    --lpAddenda;
  }
  while ( lpAddenda );
  return InterlockedIncrement((volatile LONG *)(*((_DWORD *)lpAddend + 53) + 180));
}
