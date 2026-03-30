void __cdecl __noreturn CallUnexpected()
{
  if ( *(_DWORD *)(_getptd() + 148) )
    _inconsistency();
  unexpected();
}
