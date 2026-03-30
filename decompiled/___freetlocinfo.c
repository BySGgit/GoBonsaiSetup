void __cdecl __freetlocinfo(char *Block)
{
  char **v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  int v7; // eax
  void **v8; // edi
  _DWORD *v9; // eax
  int Blocka; // [esp+14h] [ebp+8h]

  v2 = (char **)*((_DWORD *)Block + 47);
  if ( v2 )
  {
    if ( v2 != &off_4C91D8 )
    {
      v3 = (_DWORD *)*((_DWORD *)Block + 44);
      if ( v3 )
      {
        if ( !*v3 )
        {
          v4 = (_DWORD *)*((_DWORD *)Block + 46);
          if ( v4 && !*v4 )
          {
            free(*((void **)Block + 46));
            __free_lconv_mon(*((_DWORD *)Block + 47));
          }
          v5 = (_DWORD *)*((_DWORD *)Block + 45);
          if ( v5 && !*v5 )
          {
            free(*((void **)Block + 45));
            __free_lconv_num(*((_DWORD *)Block + 47));
          }
          free(*((void **)Block + 44));
          free(*((void **)Block + 47));
        }
      }
    }
  }
  v6 = (_DWORD *)*((_DWORD *)Block + 48);
  if ( v6 && !*v6 )
  {
    free((void *)(*((_DWORD *)Block + 49) - 254));
    free((void *)(*((_DWORD *)Block + 51) - 128));
    free((void *)(*((_DWORD *)Block + 52) - 128));
    free(*((void **)Block + 48));
  }
  v7 = *((_DWORD *)Block + 53);
  if ( (_UNKNOWN **)v7 != &off_4C9920 && !*(_DWORD *)(v7 + 180) )
  {
    __free_lc_time(*((_DWORD *)Block + 53));
    free(*((void **)Block + 53));
  }
  v8 = (void **)(Block + 80);
  Blocka = 6;
  do
  {
    if ( *(v8 - 2) != Str2 && *v8 && !*(_DWORD *)*v8 )
      free(*v8);
    if ( *(v8 - 1) )
    {
      v9 = v8[1];
      if ( v9 )
      {
        if ( !*v9 )
          free(v8[1]);
      }
    }
    v8 += 4;
    --Blocka;
  }
  while ( Blocka );
  free(Block);
}
