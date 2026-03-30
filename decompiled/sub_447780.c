unsigned int __fastcall sub_447780(int *a1, int a2, int a3, _BYTE *a4, int a5, __int16 a6)
{
  struct std::locale::facet *v6; // edi
  const _Cvtvec *v7; // ebx
  __int16 Wchar; // di
  _BYTE *v9; // eax
  __int16 v10; // di
  int v11; // eax
  unsigned int v12; // ebx
  int *v13; // edi
  __int16 v14; // ax
  unsigned __int16 Byte; // di
  wchar_t v16; // di
  int v17; // ebx
  void **v18; // edi
  int v19; // ecx
  __int16 **v20; // eax
  __int16 v21; // ax
  _BYTE *v22; // esi
  void **v23; // eax
  void **v24; // eax
  void **v25; // eax
  int v26; // ecx
  __int16 **v27; // eax
  __int16 v28; // ax
  int v29; // ecx
  int *v30; // edx
  __int16 **v31; // ecx
  __int16 *v32; // eax
  __int16 v33; // ax
  void **v34; // eax
  void **v35; // edx
  unsigned int v36; // esi
  void *v37; // edi
  char v38; // cl
  void **v39; // eax
  void **v40; // eax
  _BYTE *v41; // eax
  int v43; // [esp-18h] [ebp-9Ch]
  size_t v44; // [esp-14h] [ebp-98h]
  wchar_t v45; // [esp-Ch] [ebp-90h]
  char v46[6]; // [esp+14h] [ebp-70h] BYREF
  unsigned __int8 v47; // [esp+1Ah] [ebp-6Ah]
  char v48; // [esp+1Bh] [ebp-69h]
  mbstate_t v49; // [esp+1Ch] [ebp-68h] BYREF
  mbstate_t v50; // [esp+24h] [ebp-60h] BYREF
  _BYTE *v51; // [esp+2Ch] [ebp-58h]
  _Cvtvec *v52; // [esp+30h] [ebp-54h]
  int *v53; // [esp+34h] [ebp-50h]
  int v54; // [esp+38h] [ebp-4Ch]
  void *v55[5]; // [esp+3Ch] [ebp-48h] BYREF
  unsigned int v56; // [esp+50h] [ebp-34h]
  void *v57[5]; // [esp+58h] [ebp-2Ch] BYREF
  unsigned int v58; // [esp+6Ch] [ebp-18h]
  int v59; // [esp+80h] [ebp-4h]

  v51 = a4;
  v53 = a1;
  v6 = sub_44B520(a2);
  sub_44A290((int)v6, (int)v57);
  v59 = 0;
  if ( v57[4] )
    v54 = (*(unsigned __int16 (__thiscall **)(struct std::locale::facet *))(*(_DWORD *)v6 + 8))(v6);
  else
    v54 = 0;
  v7 = (const _Cvtvec *)(a3 + 8);
  *(_DWORD *)&v49._Byte = 0;
  v49._Wchar = 0;
  v46[0] = 48;
  v52 = (_Cvtvec *)(a3 + 8);
  _Mbrtowc(&v49._Byte, v46, 1u, &v49, (const _Cvtvec *)(a3 + 8));
  *(_DWORD *)&v50._Byte = v51;
  if ( (unsigned __int8)sub_44BB00(v53, (int *)a5) )
    goto LABEL_10;
  v49._Wchar = 0;
  v50._Wchar = 0;
  v46[0] = 43;
  _Mbrtowc((wchar_t *)&v49, v46, 1u, &v50, v7);
  Wchar = v49._Wchar;
  if ( sub_44A1D0((int *)a5) == Wchar )
  {
    v9 = v51;
    *v51 = 43;
  }
  else
  {
    v49._Wchar = 0;
    v50._Wchar = 0;
    v46[0] = 45;
    _Mbrtowc((wchar_t *)&v49, v46, 1u, &v50, v7);
    v10 = v49._Wchar;
    if ( sub_44A1D0((int *)a5) != v10 )
      goto LABEL_10;
    v9 = v51;
    *v51 = 45;
  }
  *(_DWORD *)&v50._Byte = v9 + 1;
  sub_44A230(a5);
LABEL_10:
  v11 = a6 & 0xE00;
  if ( v11 == 1024 )
  {
    v12 = 8;
    v49._Wchar = 8;
  }
  else if ( v11 == 2048 )
  {
    v12 = 16;
    v49._Wchar = 16;
  }
  else
  {
    v12 = v11 != 0 ? 0xA : 0;
    v49._Wchar = v12;
  }
  v13 = v53;
  v47 = 0;
  v48 = 0;
  if ( (unsigned __int8)sub_44BB00(v53, (int *)a5) || (v14 = sub_44A1D0((int *)a5), v14 != v49._Byte) )
  {
    if ( !v12 )
      goto LABEL_28;
  }
  else
  {
    v47 = 1;
    sub_44A230(a5);
    if ( !(unsigned __int8)sub_44BB00(v13, (int *)a5) )
    {
      *(_DWORD *)&v49._Byte = 0;
      v50._Wchar = 0;
      v46[0] = 120;
      _Mbrtowc(&v49._Byte, v46, 1u, &v50, v52);
      Byte = v49._Byte;
      if ( sub_44A1D0((int *)a5) == Byte || (v16 = sub_44CC70(88, v52), sub_44A1D0((int *)a5) == v16) )
      {
        if ( !v12 || v12 == 16 )
        {
          v12 = 16;
          v49._Wchar = 16;
          v47 = 0;
          sub_44A230(a5);
LABEL_27:
          *(_DWORD *)&v49._Byte = v12 != 8 ? 22 : 8;
          goto LABEL_29;
        }
      }
    }
    if ( !v12 )
    {
      v12 = 8;
      v49._Wchar = 8;
      goto LABEL_27;
    }
  }
  if ( v12 != 10 )
    goto LABEL_27;
LABEL_28:
  *(_DWORD *)&v49._Byte = 10;
LABEL_29:
  v56 = 15;
  LOWORD(v55[0]) = v47;
  v55[4] = (void *)1;
  LOBYTE(v59) = 1;
  v17 = 0;
  if ( (unsigned __int8)sub_44BB00(v53, (int *)a5) )
    goto LABEL_82;
  do
  {
    v18 = (void **)v55[0];
    if ( !*(_BYTE *)(a5 + 4) )
    {
      v19 = *(_DWORD *)a5;
      if ( !*(_DWORD *)a5
        || ((v20 = *(__int16 ***)(v19 + 32), !*v20) || **(int **)(v19 + 48) <= 0
          ? (v21 = (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 24))(v19))
          : (v21 = **v20),
            v21 == -1) )
      {
        *(_DWORD *)a5 = 0;
      }
      else
      {
        *(_WORD *)(a5 + 6) = v21;
      }
      *(_BYTE *)(a5 + 4) = 1;
    }
    v45 = *(_WORD *)(a5 + 6);
    v46[0] = 0;
    v50._Wchar = 0;
    _Wcrtomb(v46, v45, &v50, v52);
    v22 = *(_BYTE **)&v50._Byte;
    v44 = *(_DWORD *)&v49._Byte;
    v43 = v46[0];
    **(_BYTE **)&v50._Byte = v46[0];
    if ( memchr("0123456789abcdefABCDEF", v43, v44) )
    {
      if ( (v48 || *v22 != 48) && v22 < v51 + 31 )
      {
        *(_DWORD *)&v50._Byte = v22 + 1;
        v48 = 1;
      }
      v47 = 1;
      v23 = v18;
      if ( v56 < 0x10 )
        v23 = v55;
      if ( *((_BYTE *)v23 + v17) != 127 )
      {
        v24 = v18;
        if ( v56 < 0x10 )
          v24 = v55;
        ++*((_BYTE *)v24 + v17);
      }
      goto LABEL_67;
    }
    v25 = v18;
    if ( v56 < 0x10 )
      v25 = v55;
    if ( !*((_BYTE *)v25 + v17) || !(_WORD)v54 )
      break;
    if ( !*(_BYTE *)(a5 + 4) )
    {
      v26 = *(_DWORD *)a5;
      if ( !*(_DWORD *)a5
        || ((v27 = *(__int16 ***)(v26 + 32), !*v27) || **(int **)(v26 + 48) <= 0
          ? (v28 = (*(int (__thiscall **)(int))(*(_DWORD *)v26 + 24))(v26))
          : (v28 = **v27),
            v28 == -1) )
      {
        *(_DWORD *)a5 = 0;
      }
      else
      {
        *(_WORD *)(a5 + 6) = v28;
      }
      *(_BYTE *)(a5 + 4) = 1;
    }
    if ( *(_WORD *)(a5 + 6) != (_WORD)v54 )
      break;
    sub_448EB0(v55, 1u, 0);
    ++v17;
LABEL_67:
    v29 = *(_DWORD *)a5;
    if ( !*(_DWORD *)a5
      || (!**(_DWORD **)(v29 + 32) || (v30 = *(int **)(v29 + 48), *v30 <= 0)
        ? (v33 = (*(int (__thiscall **)(int))(*(_DWORD *)v29 + 28))(v29))
        : (--*v30, v31 = *(__int16 ***)(v29 + 32), v32 = *v31, ++*v31, v33 = *v32),
          v33 == -1) )
    {
      *(_DWORD *)a5 = 0;
      *(_BYTE *)(a5 + 4) = 1;
    }
    else
    {
      *(_BYTE *)(a5 + 4) = 0;
    }
  }
  while ( !(unsigned __int8)sub_44BB00(v53, (int *)a5) );
  if ( v17 )
  {
    v34 = (void **)v55[0];
    if ( v56 < 0x10 )
      v34 = v55;
    if ( *((char *)v34 + v17) <= 0 )
      v47 = 0;
    else
      ++v17;
  }
LABEL_82:
  v35 = (void **)v57[0];
  if ( v58 < 0x10 )
    v35 = v57;
  v36 = v56;
  v37 = v55[0];
  if ( v47 )
  {
    while ( v17 )
    {
      v38 = *(_BYTE *)v35;
      if ( *(_BYTE *)v35 == 127 )
        break;
      if ( --v17 )
      {
        v39 = (void **)v55[0];
        if ( v56 < 0x10 )
          v39 = v55;
        if ( v38 != *((_BYTE *)v39 + v17) )
          goto LABEL_99;
      }
      if ( !v17 )
      {
        v40 = (void **)v55[0];
        if ( v56 < 0x10 )
          v40 = v55;
        if ( v38 < *(char *)v40 )
          goto LABEL_99;
      }
      if ( *((char *)v35 + 1) > 0 )
        v35 = (void **)((char *)v35 + 1);
    }
    v41 = *(_BYTE **)&v50._Byte;
    if ( !v48 )
    {
      **(_BYTE **)&v50._Byte = 48;
      ++v41;
    }
  }
  else
  {
LABEL_99:
    v41 = v51;
  }
  *v41 = 0;
  if ( v36 >= 0x10 )
    operator delete(v37);
  if ( v58 >= 0x10 )
    operator delete(v57[0]);
  return v49._Wchar;
}
