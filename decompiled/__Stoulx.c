size_t __cdecl _Stoulx(char *a1, char **a2, int MaxCount, _DWORD *a4)
{
  int v4; // eax
  char *v5; // esi
  char v6; // al
  char v7; // al
  int v8; // eax
  void *v9; // eax
  char v10; // bl
  int v11; // eax
  int v12; // eax
  char *v14; // [esp+Ch] [ebp-14h]
  char *v15; // [esp+10h] [ebp-10h]
  size_t v16; // [esp+14h] [ebp-Ch]
  size_t v17; // [esp+18h] [ebp-8h]
  char v18; // [esp+1Fh] [ebp-1h]

  if ( a4 )
    *a4 = 0;
  v4 = (unsigned __int8)*a1;
  v5 = a1;
  while ( isspace(v4) )
    v4 = (unsigned __int8)*++v5;
  if ( *v5 == 45 || *v5 == 43 )
    v18 = *v5++;
  else
    v18 = 43;
  if ( MaxCount < 0 || MaxCount == 1 || MaxCount > 36 )
  {
    if ( a2 )
      *a2 = a1;
    return 0;
  }
  if ( MaxCount <= 0 )
  {
    if ( *v5 == 48 )
    {
      v7 = v5[1];
      if ( v7 == 120 || v7 == 88 )
      {
        MaxCount = 16;
LABEL_25:
        v5 += 2;
        goto LABEL_26;
      }
      MaxCount = 8;
    }
    else
    {
      MaxCount = 10;
    }
  }
  else if ( MaxCount == 16 && *v5 == 48 )
  {
    v6 = v5[1];
    if ( v6 == 120 || v6 == 88 )
      goto LABEL_25;
  }
LABEL_26:
  v15 = v5;
  while ( *v5 == 48 )
    ++v5;
  v17 = 0;
  v14 = v5;
  v16 = 0;
  v8 = tolower(*v5);
  v9 = memchr("0123456789abcdefghijklmnopqrstuvwxyz", v8, MaxCount);
  if ( v9 )
  {
    do
    {
      v10 = (_BYTE)v9 - (unsigned __int8)"0123456789abcdefghijklmnopqrstuvwxyz";
      v16 = v17;
      v17 = v10 + MaxCount * v17;
      v11 = tolower(*++v5);
      v9 = memchr("0123456789abcdefghijklmnopqrstuvwxyz", v11, MaxCount);
    }
    while ( v9 );
  }
  else
  {
    v10 = HIBYTE(MaxCount);
  }
  if ( v15 == v5 )
  {
    if ( a2 )
      *a2 = a1;
    return 0;
  }
  v12 = &v5[-byte_4735E8[MaxCount]] - v14;
  if ( v12 >= 0 && (v12 > 0 || v17 < v10 || (v17 - v10) / MaxCount != v16) )
  {
    *_errno() = 34;
    if ( a4 )
      *a4 = 1;
    v17 = -1;
    v18 = 43;
  }
  if ( v18 == 45 )
    v17 = -v17;
  if ( a2 )
    *a2 = v5;
  return v17;
}
