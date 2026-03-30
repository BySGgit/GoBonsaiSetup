volatile LONG *___lc_handle_func()
{
  int v0; // ecx
  volatile LONG *v1; // eax

  v0 = _getptd();
  v1 = *(volatile LONG **)(v0 + 108);
  if ( v1 != off_4C9B60 && (dword_4C9918 & *(_DWORD *)(v0 + 112)) == 0 )
    v1 = (volatile LONG *)__updatetlocinfo();
  return v1 + 3;
}
