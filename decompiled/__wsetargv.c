int _wsetargv()
{
  __int16 *v0; // edi
  unsigned int v1; // ebx
  size_t v2; // eax
  __int16 **v3; // eax
  int v4; // esi
  unsigned int v6; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v7; // [esp+10h] [ebp-4h] BYREF

  word_4D7B18 = 0;
  GetModuleFileNameW(0, &word_4D7910, 0x104u);
  dword_4D7294 = (int)&word_4D7910;
  if ( !dword_4DD058 || (v0 = (__int16 *)dword_4DD058, !*(_WORD *)dword_4DD058) )
    v0 = (__int16 *)&word_4D7910;
  wparse_cmdline(v0, 0, &v6, 0, &v7);
  v1 = v7;
  if ( v7 >= 0x3FFFFFFF )
    return -1;
  if ( v6 >= 0x7FFFFFFF )
    return -1;
  v2 = 2 * (v6 + 2 * v7);
  if ( v2 < 2 * v6 )
    return -1;
  v3 = (__int16 **)_malloc_crt(v2);
  v4 = (int)v3;
  if ( !v3 )
    return -1;
  wparse_cmdline(v0, (__int16 *)&v3[v1], &v6, v3, &v7);
  dword_4D7274 = v7 - 1;
  dword_4D727C = v4;
  return 0;
}
