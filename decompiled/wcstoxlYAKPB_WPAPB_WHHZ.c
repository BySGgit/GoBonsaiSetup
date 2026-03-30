int __cdecl wcstoxl(const wchar_t *a1, const wchar_t **a2, unsigned int a3, int a4)
{
  const wchar_t *v4; // edi
  unsigned __int16 v6; // si
  int v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  int v11; // eax
  const wchar_t *v12; // edi
  wint_t v13; // [esp-10h] [ebp-1Ch]
  unsigned int v14; // [esp+8h] [ebp-4h]

  v4 = a1;
  if ( a2 )
    *a2 = a1;
  if ( !a1 || a3 && ((int)a3 < 2 || (int)a3 > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v14 = 0;
  do
  {
    v6 = *v4;
    v13 = *v4++;
  }
  while ( iswctype(v13, 8u) );
  if ( v6 == 45 )
  {
    a4 |= 2u;
  }
  else if ( v6 != 43 )
  {
    goto LABEL_14;
  }
  v6 = *v4++;
LABEL_14:
  if ( a3 )
    goto LABEL_21;
  if ( !_wchartodigit(v6) )
  {
    v7 = *v4;
    if ( v7 != 120 && v7 != 88 )
    {
      a3 = 8;
      goto LABEL_26;
    }
    a3 = 16;
LABEL_21:
    if ( a3 == 16 && !_wchartodigit(v6) )
    {
      v8 = *v4;
      if ( v8 == 120 || v8 == 88 )
      {
        v6 = v4[1];
        v4 += 2;
      }
    }
    goto LABEL_26;
  }
  a3 = 10;
LABEL_26:
  v9 = 0xFFFFFFFF / a3;
  while ( 1 )
  {
    v10 = _wchartodigit(v6);
    if ( v10 != -1 )
      goto LABEL_34;
    if ( (v6 < 0x41u || v6 > 0x5Au) && (unsigned __int16)(v6 - 97) > 0x19u )
      break;
    v11 = v6;
    if ( (unsigned __int16)(v6 - 97) <= 0x19u )
      v11 = v6 - 32;
    v10 = v11 - 55;
LABEL_34:
    if ( v10 >= a3 )
      break;
    a4 |= 8u;
    if ( v14 < v9 || v14 == v9 && v10 <= 0xFFFFFFFF % a3 )
    {
      v14 = v10 + a3 * v14;
    }
    else
    {
      a4 |= 4u;
      if ( !a2 )
        break;
    }
    v6 = *v4++;
  }
  v12 = v4 - 1;
  if ( (a4 & 8) != 0 )
  {
    if ( (a4 & 4) != 0 || (a4 & 1) == 0 && ((a4 & 2) != 0 && v14 > 0x80000000 || (a4 & 2) == 0 && v14 > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (a4 & 1) != 0 )
        v14 = -1;
      else
        v14 = ((a4 & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( a2 )
      v12 = a1;
    v14 = 0;
  }
  if ( a2 )
    *a2 = v12;
  if ( (a4 & 2) != 0 )
    return -v14;
  return v14;
}
