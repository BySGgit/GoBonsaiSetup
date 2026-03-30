unsigned __int64 __cdecl _Stoullx(char *a1, char **a2, int MaxCount, _DWORD *a4)
{
  char *v4; // ebx
  int v5; // eax
  char *v6; // edi
  char v7; // al
  char v8; // al
  int v9; // eax
  void *v10; // eax
  char v11; // cl
  int v12; // eax
  void *v13; // eax
  char **v14; // eax
  bool v15; // zf
  int v16; // eax
  unsigned __int64 v17; // kr00_8
  unsigned __int64 v19; // [esp+14h] [ebp-20h]
  unsigned __int64 v20; // [esp+1Ch] [ebp-18h]
  char *v21; // [esp+24h] [ebp-10h]
  char *v22; // [esp+28h] [ebp-Ch]
  char v23; // [esp+32h] [ebp-2h]
  char v24; // [esp+33h] [ebp-1h]

  if ( a4 )
    *a4 = 0;
  v4 = a1;
  v5 = (unsigned __int8)*a1;
  v6 = a1;
  while ( isspace(v5) )
    v5 = (unsigned __int8)*++v6;
  if ( *v6 == 45 || *v6 == 43 )
    v24 = *v6++;
  else
    v24 = 43;
  if ( MaxCount < 0 || MaxCount == 1 || MaxCount > 36 )
  {
    v14 = a2;
    v15 = a2 == 0;
    goto LABEL_47;
  }
  if ( MaxCount <= 0 )
  {
    if ( *v6 == 48 )
    {
      v8 = v6[1];
      if ( v8 == 120 || v8 == 88 )
      {
        MaxCount = 16;
LABEL_25:
        v6 += 2;
        goto LABEL_26;
      }
      MaxCount = 8;
    }
    else
    {
      MaxCount = 10;
    }
  }
  else if ( MaxCount == 16 && *v6 == 48 )
  {
    v7 = v6[1];
    if ( v7 == 120 || v7 == 88 )
      goto LABEL_25;
  }
LABEL_26:
  v22 = v6;
  while ( *v6 == 48 )
    ++v6;
  v20 = 0;
  v21 = v6;
  v19 = 0;
  v23 = 0;
  v9 = tolower(*v6);
  v10 = memchr("0123456789abcdefghijklmnopqrstuvwxyz", v9, MaxCount);
  v11 = (char)v10;
  if ( v10 )
  {
    do
    {
      v19 = v20;
      v23 = v11 - (unsigned __int8)"0123456789abcdefghijklmnopqrstuvwxyz";
      ++v6;
      v20 = v23 + MaxCount * v20;
      v12 = tolower(*v6);
      v13 = memchr("0123456789abcdefghijklmnopqrstuvwxyz", v12, MaxCount);
      v11 = (char)v13;
    }
    while ( v13 );
    v4 = a1;
  }
  if ( v22 == v6 )
  {
    v14 = a2;
    v15 = a2 == 0;
LABEL_47:
    if ( !v15 )
      *v14 = v4;
    return 0;
  }
  v16 = &v6[-byte_473638[MaxCount]] - v21;
  if ( v16 >= 0 )
  {
    if ( v16 > 0 || (v17 = v20 - v23, v20 < v17) || v17 / MaxCount != v19 )
    {
      *_errno() = 34;
      if ( a4 )
        *a4 = 1;
      v20 = -1;
      v24 = 43;
    }
  }
  if ( v24 == 45 )
    v20 = -(__int64)v20;
  if ( a2 )
    *a2 = v6;
  return v20;
}
