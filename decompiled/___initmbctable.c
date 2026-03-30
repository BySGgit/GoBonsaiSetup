int __initmbctable()
{
  if ( !dword_4DD04C )
  {
    _setmbcp(-3);
    dword_4DD04C = 1;
  }
  return 0;
}
