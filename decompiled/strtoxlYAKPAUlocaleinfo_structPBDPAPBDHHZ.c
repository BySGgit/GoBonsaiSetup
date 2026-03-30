unsigned int __cdecl strtoxl(struct localeinfo_struct *a1, const char *a2, const char **a3, unsigned int a4, int a5)
{
  struct __crt_locale_data *locinfo; // ecx
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  int v11; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  __crt_locale_pointers Locale; // [esp+4h] [ebp-1Ch] BYREF
  int v16; // [esp+Ch] [ebp-14h]
  char v17; // [esp+10h] [ebp-10h]
  unsigned int v18; // [esp+18h] [ebp-8h]
  unsigned int v19; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&Locale, a1);
  if ( a3 )
    *a3 = a2;
  if ( !a2 || a4 && ((int)a4 < 2 || (int)a4 > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( v17 )
      *(_DWORD *)(v16 + 112) &= ~2u;
    return 0;
  }
  v19 = 0;
  locinfo = Locale.locinfo;
  v7 = *a2;
  for ( i = a2 + 1; ; ++i )
  {
    if ( *((int *)locinfo + 43) <= 1 )
    {
      v9 = *(_WORD *)(*((_DWORD *)locinfo + 50) + 2 * v7) & 8;
    }
    else
    {
      v9 = _isctype_l(v7, 8, &Locale);
      locinfo = Locale.locinfo;
    }
    if ( !v9 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    a5 |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( a4 )
  {
    if ( a4 != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      a4 = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      a4 = 8;
      goto LABEL_32;
    }
    a4 = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / a4;
  v11 = *((_DWORD *)locinfo + 50);
  v18 = 0xFFFFFFFF % a4;
  while ( 1 )
  {
    if ( (*(_WORD *)(v11 + 2 * v7) & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (*(_WORD *)(v11 + 2 * v7) & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= a4 )
      break;
    a5 |= 8u;
    if ( v19 < v10 || v19 == v10 && v12 <= v18 )
    {
      v19 = v12 + a4 * v19;
    }
    else
    {
      a5 |= 4u;
      if ( !a3 )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
  if ( (a5 & 8) != 0 )
  {
    if ( (a5 & 4) != 0 || (a5 & 1) == 0 && ((a5 & 2) != 0 && v19 > 0x80000000 || (a5 & 2) == 0 && v19 > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (a5 & 1) != 0 )
        v19 = -1;
      else
        v19 = ((a5 & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( a3 )
      v14 = a2;
    v19 = 0;
  }
  if ( a3 )
    *a3 = v14;
  if ( (a5 & 2) != 0 )
    v19 = -v19;
  if ( v17 )
    *(_DWORD *)(v16 + 112) &= ~2u;
  return v19;
}
