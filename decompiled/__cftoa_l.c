int __cdecl _cftoa_l(_DWORD *a1, _BYTE *a2, unsigned int a3, int Size, int a5, struct localeinfo_struct *a6)
{
  _BYTE *v6; // esi
  int *v7; // eax
  int result; // eax
  unsigned int v9; // eax
  bool v10; // zf
  char *v11; // eax
  _BYTE *v12; // esi
  _BYTE *v13; // eax
  _BYTE *v14; // esi
  int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  _BYTE *i; // eax
  __int64 v19; // rax
  __int64 v20; // rcx
  _BYTE *v21; // esi
  _BYTE *v22; // edi
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rcx
  __int64 v28; // [esp-Ch] [ebp-38h]
  int v29; // [esp-4h] [ebp-30h]
  int v30; // [esp+8h] [ebp-24h] BYREF
  int v31; // [esp+10h] [ebp-1Ch]
  char v32; // [esp+14h] [ebp-18h]
  int v33; // [esp+18h] [ebp-14h]
  int v34; // [esp+1Ch] [ebp-10h]
  unsigned __int64 v35; // [esp+20h] [ebp-Ch]
  int v36; // [esp+28h] [ebp-4h]
  _BYTE *v37; // [esp+38h] [ebp+Ch]

  v33 = 1023;
  v36 = 48;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v30, a6);
  if ( Size < 0 )
    Size = 0;
  v6 = a2;
  if ( !a2 || !a3 )
  {
    v7 = _errno();
    v29 = 22;
LABEL_5:
    *v7 = v29;
    _invalid_parameter_noinfo();
    if ( v32 )
      *(_DWORD *)(v31 + 112) &= ~2u;
    return v29;
  }
  *a2 = 0;
  if ( a3 <= Size + 11 )
  {
    v7 = _errno();
    v29 = 34;
    goto LABEL_5;
  }
  LODWORD(v35) = *a1;
  if ( ((a1[1] >> 20) & 0x7FF) == 0x7FF )
  {
    v9 = a3;
    if ( a3 != -1 )
      v9 = a3 - 2;
    result = _cftoe(a1, a2 + 2, v9, Size, 0);
    if ( result )
    {
      v10 = v32 == 0;
      *a2 = 0;
      if ( !v10 )
        *(_DWORD *)(v31 + 112) &= ~2u;
      return result;
    }
    if ( a2[2] == 45 )
    {
      *a2 = 45;
      v6 = a2 + 1;
    }
    *v6 = 48;
    v6[1] = a5 == 0 ? 120 : 88;
    v11 = strrchr(v6 + 2, 101);
    if ( v11 )
    {
      *v11 = a5 == 0 ? 112 : 80;
      v11[3] = 0;
    }
  }
  else
  {
    if ( (a1[1] & 0x80000000) != 0 )
    {
      *a2 = 45;
      v6 = a2 + 1;
    }
    *v6 = 48;
    v6[1] = a5 == 0 ? 120 : 88;
    if ( (a1[1] & 0x7FF00000) != 0 )
    {
      v6[2] = 49;
      v12 = v6 + 3;
    }
    else
    {
      v6[2] = 48;
      v12 = v6 + 3;
      if ( a1[1] & 0xFFFFF | *a1 )
        v33 = 1022;
      else
        v33 = 0;
    }
    v13 = v12;
    v14 = v12 + 1;
    v37 = v13;
    if ( Size )
      *v13 = ***(_BYTE ***)(v30 + 188);
    else
      *v13 = 0;
    v15 = *a1;
    HIDWORD(v35) = a1[1] & 0xFFFFF;
    if ( HIDWORD(v35) || v15 )
    {
      v35 = 0xF000000000000LL;
      do
      {
        if ( Size <= 0 )
          break;
        v16 = (unsigned __int16)(((v35 & *(_QWORD *)a1 & 0xFFFFFFFFFFFFFLL) >> v36) + 48);
        if ( v16 > 0x39 )
          LOBYTE(v16) = (a5 != 0 ? 7 : 39) + ((v35 & *(_QWORD *)a1 & 0xFFFFFFFFFFFFFLL) >> v36) + 48;
        v17 = HIDWORD(v35);
        v36 -= 4;
        *v14++ = v16;
        --Size;
        v35 = __PAIR64__(v17, v35) >> 4;
      }
      while ( (v36 & 0x8000u) == 0 );
      if ( (v36 & 0x8000u) == 0 && (unsigned __int16)((v35 & *(_QWORD *)a1 & 0xFFFFFFFFFFFFFLL) >> v36) > 8u )
      {
        for ( i = v14 - 1; *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == v37 )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = a5 != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( Size > 0 )
    {
      memset(v14, 48, Size);
      v14 += Size;
    }
    if ( !*v37 )
      v14 = v37;
    *v14 = a5 == 0 ? 112 : 80;
    HIDWORD(v20) = 0;
    v19 = ((*(_QWORD *)a1 >> 52) & 0x7FFLL) - (unsigned int)v33;
    if ( v19 < 0 )
    {
      v14[1] = 45;
      v21 = v14 + 2;
      v19 = -v19;
    }
    else
    {
      v14[1] = 43;
      v21 = v14 + 2;
    }
    v22 = v21;
    *v21 = 48;
    if ( v19 >= 0 )
    {
      LODWORD(v20) = 1000;
      if ( v19 >= 1000 )
      {
        v28 = v20;
        v24 = v19 % v20;
        v23 = v19 / v28;
        *v21++ = v23 + 48;
        v34 = HIDWORD(v23);
        v19 = v24;
        if ( v21 != v22 )
          goto LABEL_60;
      }
    }
    if ( v19 >= 100 )
    {
LABEL_60:
      v26 = v19 % 100;
      v25 = v19 / 100;
      *v21 = v25 + 48;
      v34 = HIDWORD(v25);
      ++v21;
      v19 = v26;
    }
    if ( v21 != v22 || v19 >= 10 )
    {
      v27 = v19 % 10;
      *v21++ = v19 / 10 + 48;
      LOBYTE(v19) = v19 % 10;
      v34 = HIDWORD(v27);
    }
    *v21 = v19 + 48;
    v21[1] = 0;
  }
  if ( v32 )
    *(_DWORD *)(v31 + 112) &= ~2u;
  return 0;
}
