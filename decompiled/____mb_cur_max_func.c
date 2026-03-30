int __cdecl ___mb_cur_max_func()
{
  int v0; // ecx
  int v1; // eax

  v0 = _getptd();
  v1 = *(_DWORD *)(v0 + 108);
  if ( (volatile LONG *)v1 != off_4C9B60 && (dword_4C9918 & *(_DWORD *)(v0 + 112)) == 0 )
    v1 = __updatetlocinfo();
  return *(_DWORD *)(v1 + 172);
}
