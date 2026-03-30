char *__fastcall _setlocale_nolock(int a1, _DWORD *a2, char *Str2)
{
  int v3; // ebx
  _DWORD *v4; // esi
  char *result; // eax
  const char *v6; // edi
  char *v7; // eax
  char *v8; // ebx
  size_t v9; // eax
  const char **v10; // esi
  const char *v11; // ebx
  rsize_t v12; // edi
  const char *v13; // edi
  const char **v14; // edi
  int v16; // [esp+10h] [ebp-94h]
  int v17; // [esp+14h] [ebp-90h]
  size_t v18; // [esp+14h] [ebp-90h]
  int v19; // [esp+18h] [ebp-8Ch]
  char Str1[132]; // [esp+1Ch] [ebp-88h] BYREF

  v3 = 0;
  v4 = a2;
  if ( a1 )
  {
    if ( Str2 )
      return (char *)_setlocale_set_cat(a1, a2, Str2);
    else
      return (char *)a2[4 * a1 + 18];
  }
  v17 = 1;
  v19 = 0;
  if ( !Str2 )
    return (char *)_setlocale_get_all((int)v4);
  if ( *Str2 == 76 && Str2[1] == 67 && Str2[2] == 95 )
  {
    v6 = Str2;
    do
    {
      v7 = strpbrk(v6, "=;");
      v8 = v7;
      if ( !v7 )
        return 0;
      v9 = v7 - v6;
      v18 = v9;
      if ( !v9 || *v8 == 59 )
        return 0;
      v16 = 1;
      v10 = (const char **)off_473774;
      while ( strncmp(*v10, v6, v9) || v18 != strlen(*v10) )
      {
        ++v16;
        v10 += 3;
        if ( (int)v10 > (int)off_4737A4 )
          break;
        v9 = v18;
      }
      v11 = v8 + 1;
      v12 = strcspn(v11, ";");
      if ( !v12 && *v11 != 59 )
        return 0;
      if ( v16 <= 5 )
      {
        if ( strncpy_s(Str1, 0x83u, v11, v12) )
          _invoke_watson(0, 0, 0, 0, 0);
        Str1[v12] = 0;
        if ( _setlocale_set_cat(v16, a2, Str1) )
          ++v19;
      }
      v13 = &v11[v12];
      if ( !*v13 )
        break;
      v6 = v13 + 1;
    }
    while ( *v6 );
    result = 0;
    if ( !v19 )
      return result;
    v4 = a2;
    return (char *)_setlocale_get_all((int)v4);
  }
  result = _expandlocale(Str2, Str1, 0x83u, 0, 0);
  if ( result )
  {
    v14 = (const char **)(v4 + 18);
    do
    {
      if ( v3 )
      {
        if ( !strcmp(Str1, *v14) || _setlocale_set_cat(v3, v4, Str1) )
          ++v19;
        else
          v17 = 0;
      }
      ++v3;
      v14 += 4;
    }
    while ( v3 <= 5 );
    result = 0;
    if ( v17 || v19 )
      return (char *)_setlocale_get_all((int)v4);
  }
  return result;
}
