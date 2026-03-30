int __cdecl strncmp(const char *Str1, const char *Str2, size_t MaxCount)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  size_t i; // esi
  size_t v13; // [esp+4h] [ebp-4h]

  v13 = 0;
  if ( !MaxCount )
    return 0;
  if ( MaxCount <= 4 )
  {
    v4 = Str2;
    v5 = Str1;
LABEL_20:
    for ( i = v13; ; ++i )
    {
      if ( i >= MaxCount )
        return 0;
      if ( !*v5 || *v5 != *v4 )
        break;
      ++v5;
      ++v4;
    }
    v10 = *(unsigned __int8 *)v5;
    v11 = *(unsigned __int8 *)v4;
  }
  else
  {
    v4 = Str2;
    v5 = Str1;
    while ( 1 )
    {
      v6 = *v5;
      v5 += 4;
      v4 += 4;
      if ( !v6 || v6 != *(v4 - 4) )
        break;
      v7 = *(v5 - 3);
      if ( !v7 || v7 != *(v4 - 3) )
      {
        v10 = *((unsigned __int8 *)v5 - 3);
        v11 = *((unsigned __int8 *)v4 - 3);
        return v10 - v11;
      }
      v8 = *(v5 - 2);
      if ( !v8 || v8 != *(v4 - 2) )
      {
        v10 = *((unsigned __int8 *)v5 - 2);
        v11 = *((unsigned __int8 *)v4 - 2);
        return v10 - v11;
      }
      v9 = *(v5 - 1);
      if ( !v9 || v9 != *(v4 - 1) )
      {
        v10 = *((unsigned __int8 *)v5 - 1);
        v11 = *((unsigned __int8 *)v4 - 1);
        return v10 - v11;
      }
      v13 += 4;
      if ( v13 >= MaxCount - 4 )
        goto LABEL_20;
    }
    v10 = *((unsigned __int8 *)v5 - 4);
    v11 = *((unsigned __int8 *)v4 - 4);
  }
  return v10 - v11;
}
