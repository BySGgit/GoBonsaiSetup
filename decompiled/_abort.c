void __cdecl __noreturn abort()
{
  if ( sub_4622B9() )
    raise(22);
  if ( (dword_4C93E8 & 2) != 0 )
    _call_reportfault(3, 1073741845, 1);
  _exit(3);
}
