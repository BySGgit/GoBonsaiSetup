int __cdecl _IsExceptionObjectToBeDestroyed(int a1)
{
  _DWORD *i; // eax

  for ( i = *(_DWORD **)(_getptd() + 152); ; i = (_DWORD *)i[1] )
  {
    if ( !i )
      return 1;
    if ( *i == a1 )
      break;
  }
  return 0;
}
