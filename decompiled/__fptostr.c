int __cdecl _fptostr(char *a1, unsigned int a2, int a3, int a4)
{
  int v4; // ecx
  char *v5; // ebx
  int v6; // eax
  int v7; // esi
  int v9; // edx
  char *v10; // eax
  char v11; // cl
  size_t v12; // eax

  v4 = a4;
  v5 = *(char **)(a4 + 12);
  v6 = 0;
  if ( !a1 || !a2 )
  {
    v7 = 22;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter_noinfo();
    return v7;
  }
  v9 = a3;
  *a1 = 0;
  if ( a3 > 0 )
    v6 = a3;
  if ( a2 <= v6 + 1 )
  {
    *_errno() = 34;
    v7 = 34;
    goto LABEL_3;
  }
  *a1 = 48;
  v10 = a1 + 1;
  if ( a3 > 0 )
  {
    do
    {
      v11 = *v5;
      if ( *v5 )
        ++v5;
      else
        v11 = 48;
      *v10++ = v11;
      --v9;
    }
    while ( v9 > 0 );
    v4 = a4;
  }
  *v10 = 0;
  if ( v9 >= 0 && *v5 >= 53 )
  {
    while ( *--v10 == 57 )
      *v10 = 48;
    ++*v10;
  }
  if ( *a1 == 49 )
  {
    ++*(_DWORD *)(v4 + 4);
  }
  else
  {
    v12 = strlen(a1 + 1);
    memcpy(a1, a1 + 1, v12 + 1);
  }
  return 0;
}
