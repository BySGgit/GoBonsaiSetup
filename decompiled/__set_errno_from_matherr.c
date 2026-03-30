void __cdecl _set_errno_from_matherr(int a1)
{
  if ( a1 == 1 )
  {
    *_errno() = 33;
  }
  else if ( a1 > 1 && a1 <= 3 )
  {
    *_errno() = 34;
  }
}
