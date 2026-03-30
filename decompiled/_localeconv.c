struct lconv *__cdecl localeconv()
{
  int v0; // eax

  v0 = _getptd();
  if ( *(volatile LONG **)(v0 + 108) != off_4C9B60 && (dword_4C9918 & *(_DWORD *)(v0 + 112)) == 0 )
    __updatetlocinfo();
  return (struct lconv *)off_4C9228;
}
