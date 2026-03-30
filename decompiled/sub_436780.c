float *__thiscall sub_436780(char **this, float *a2)
{
  char *v2; // edx
  int v3; // ebp
  float *result; // eax
  char *i; // ebx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  wchar_t *v8; // eax
  unsigned int v9; // edi
  unsigned int v10; // esi
  int v11; // edx
  wchar_t v12; // cx
  double v13; // st7
  float *v14; // eax
  float *v15; // [esp+10h] [ebp-80h]
  wchar_t String[60]; // [esp+14h] [ebp-7Ch] BYREF

  v2 = *(this + 20);
  v15 = a2;
  v3 = 0;
  do
  {
    result = (float *)*(unsigned __int16 *)v2;
    if ( !(_WORD)result )
      break;
    if ( result == (float *)32 )
    {
      do
        v2 += 2;
      while ( *(_WORD *)v2 == 32 );
    }
    if ( !*(_WORD *)v2 )
      break;
    for ( i = v2; ; i += 2 )
    {
      v6 = *(unsigned __int16 *)i;
      if ( v6 != 45 && v6 != 46 && (v6 < 0x30 || v6 > 0x39) )
        break;
    }
    v7 = ((i - v2) >> 1) + 1;
    if ( v7 > 0x3B )
    {
      v7 = 59;
LABEL_15:
      v8 = String;
      v9 = 2147483646 - v7;
      v10 = v7;
      v11 = v2 - (char *)String;
      while ( v9 + v10 )
      {
        v12 = *(wchar_t *)((char *)v8 + v11);
        if ( !v12 )
          break;
        *v8++ = v12;
        if ( !--v10 )
          goto LABEL_21;
      }
      if ( v10 )
        goto LABEL_22;
LABEL_21:
      --v8;
LABEL_22:
      *v8 = 0;
      goto LABEL_23;
    }
    if ( (i - v2) >> 1 != -1 )
      goto LABEL_15;
LABEL_23:
    v13 = wcstod(String, 0);
    v14 = v15;
    *v15 = v13;
    ++v3;
    result = v14 + 1;
    v15 = result;
    v2 = i;
  }
  while ( v3 < 1 );
  return result;
}
