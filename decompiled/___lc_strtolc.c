int __cdecl __lc_strtolc(char *a1, char *Str)
{
  const char *v2; // esi
  rsize_t v4; // eax
  bool i; // zf
  const char *v6; // edi
  char v7; // bl
  errno_t v8; // eax
  char *v9; // eax
  rsize_t v10; // [esp-Ch] [ebp-18h]
  const char *v12; // [esp-8h] [ebp-14h]
  rsize_t v13; // [esp-4h] [ebp-10h]
  char *Stra; // [esp+18h] [ebp+Ch]

  memset(a1, 0, 0x90u);
  v2 = Str;
  if ( !*Str )
    return 0;
  if ( *Str == 46 && Str[1] )
  {
    if ( strncpy_s(a1 + 128, 0x10u, Str + 1, 0xFu) )
      _invoke_watson(0, 0, 0, 0, 0);
    a1[143] = 0;
    return 0;
  }
  Stra = 0;
  v4 = strcspn(Str, "_.,");
  for ( i = v4 == 0; !i; i = v4 == 0 )
  {
    v6 = &v2[v4];
    v7 = v2[v4];
    if ( Stra )
    {
      if ( Stra == (char *)1 )
      {
        if ( v4 >= 0x40 || v7 == 95 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 64;
        v9 = a1 + 64;
      }
      else
      {
        if ( Stra != (char *)2 || v4 >= 0x10 || v7 && v7 != 44 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 16;
        v9 = a1 + 128;
      }
      v8 = strncpy_s(v9, v10, v12, v13);
    }
    else
    {
      if ( v4 >= 0x40 || v7 == 46 )
        return -1;
      v8 = strncpy_s(a1, 0x40u, v2, v4);
    }
    if ( v8 )
      _invoke_watson(0, 0, 0, 0, 0);
    if ( v7 == 44 || !v7 )
      return 0;
    ++Stra;
    v2 = v6 + 1;
    v4 = strcspn(v6 + 1, "_.,");
  }
  return -1;
}
