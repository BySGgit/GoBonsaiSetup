_DWORD *__fastcall sub_446C70(
        size_t a1,
        unsigned int a2,
        int a3,
        _DWORD *a4,
        int a5,
        __int16 a6,
        char *Buf,
        int a8,
        size_t MaxCount,
        int a10,
        _DWORD *a11)
{
  char *v11; // ebp
  size_t v12; // ebx
  _DWORD *v13; // eax
  struct std::locale::facet *v14; // edi
  int v15; // esi
  int v16; // eax
  int v17; // esi
  void (__thiscall ***v18)(_DWORD, int); // esi
  char v19; // al
  _BYTE *v20; // esi
  _BYTE *v21; // edi
  void **v22; // eax
  void **v23; // ecx
  size_t v24; // ebx
  void **v25; // ebx
  const char *v26; // eax
  size_t v27; // esi
  int v28; // eax
  int v29; // edi
  unsigned int v30; // ecx
  size_t v31; // eax
  int v32; // esi
  int v33; // eax
  int *v34; // eax
  int *v35; // eax
  _DWORD *v36; // edx
  _BYTE *v37; // eax
  size_t v38; // eax
  size_t v39; // edi
  int *v40; // eax
  int *v41; // eax
  __int16 v42; // ax
  int *v43; // eax
  int *v44; // eax
  _BYTE *v45; // eax
  size_t v46; // eax
  size_t v47; // edi
  int *v48; // eax
  int *v49; // eax
  char *v50; // ecx
  int *v51; // eax
  int *v52; // eax
  int *v53; // eax
  int v54; // ecx
  _DWORD *v56; // [esp-4h] [ebp-A4h]
  size_t Size; // [esp+14h] [ebp-8Ch]
  mbstate_t v58; // [esp+18h] [ebp-88h] BYREF
  char Control; // [esp+20h] [ebp-80h] BYREF
  __int16 v60; // [esp+21h] [ebp-7Fh]
  char v61[4]; // [esp+24h] [ebp-7Ch] BYREF
  int v62; // [esp+28h] [ebp-78h]
  size_t v63; // [esp+2Ch] [ebp-74h]
  int v64; // [esp+30h] [ebp-70h]
  wchar_t v65[2]; // [esp+34h] [ebp-6Ch] BYREF
  unsigned int v66; // [esp+38h] [ebp-68h]
  int v67; // [esp+3Ch] [ebp-64h]
  int v68[2]; // [esp+40h] [ebp-60h] BYREF
  int v69[2]; // [esp+48h] [ebp-58h] BYREF
  int v70; // [esp+50h] [ebp-50h] BYREF
  char *Str[4]; // [esp+54h] [ebp-4Ch] BYREF
  size_t v72; // [esp+64h] [ebp-3Ch]
  unsigned int v73; // [esp+68h] [ebp-38h]
  void *v74[5]; // [esp+70h] [ebp-30h] BYREF
  unsigned int v75; // [esp+84h] [ebp-1Ch]
  int v76; // [esp+9Ch] [ebp-4h]
  int v77; // [esp+C0h] [ebp+20h]
  _DWORD *v78; // [esp+C4h] [ebp+24h]

  v11 = Buf;
  v12 = MaxCount;
  v62 = a3;
  v63 = a1;
  v67 = a5;
  v66 = a2;
  Size = a8;
  v13 = sub_44DB70(a5, a8, &v70);
  v76 = 0;
  v14 = sub_44B520((int)v13);
  v76 = -1;
  v68[0] = (int)v14;
  if ( v70 )
  {
    v15 = v70;
    v64 = v70;
    std::_Lockit::_Lockit((std::_Lockit *)&v58, 0);
    v16 = *(_DWORD *)(v15 + 4);
    if ( v16 && v16 != -1 )
      *(_DWORD *)(v15 + 4) = v16 - 1;
    v17 = -(*(_DWORD *)(v15 + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)&v58);
    v18 = (void (__thiscall ***)(_DWORD, int))(v64 & v17);
    if ( v18 )
      (**v18)(v18, 1);
  }
  sub_44A290((int)v14, (int)v74);
  v76 = 1;
  v64 = (*(unsigned __int16 (__thiscall **)(struct std::locale::facet *))(*(_DWORD *)v14 + 8))(v14);
  v73 = 15;
  v72 = 0;
  LOBYTE(Str[0]) = 0;
  LOBYTE(v76) = 2;
  v61[0] = 48;
  *(_DWORD *)v65 = 0;
  v58._Wchar = 0;
  _Mbrtowc(v65, v61, 1u, &v58, (const _Cvtvec *)(v62 + 8));
  v19 = *Buf;
  if ( *Buf == 43 || (v58._Wchar = 0, v19 == 45) )
    v58._Wchar = 1;
  Control = *localeconv()->decimal_point;
  v60 = 101;
  v20 = memchr(Buf, 101, MaxCount);
  *(_DWORD *)&v58._Byte = v20;
  v21 = memchr(Buf, Control, MaxCount);
  v69[0] = (int)v21;
  if ( !v21 )
    Size = 0;
  v22 = (void **)v74[0];
  v23 = (void **)v74[0];
  if ( v75 < 0x10 )
    v23 = v74;
  if ( *(_BYTE *)v23 != 127 )
  {
    if ( v75 < 0x10 )
      v22 = v74;
    if ( *(char *)v22 > 0 )
    {
      sub_448DA0(Str, Buf, MaxCount);
      if ( v20 )
      {
        if ( v21 )
        {
          v24 = v63;
        }
        else
        {
          sub_448EB0(Str, v63, 48);
          v20 = *(_BYTE **)&v58._Byte;
          v24 = 0;
        }
        sub_44CB90(v20 - Buf, (int *)Str, Size, 48);
        v21 = (_BYTE *)v69[0];
      }
      else
      {
        sub_448EB0(Str, Size, 48);
        v24 = v63;
      }
      if ( v21 )
      {
        sub_44CB90(v21 - Buf + 1, (int *)Str, v66, 48);
        sub_44CB90(v21 - Buf, (int *)Str, v24, 48);
        v66 = 0;
      }
      else
      {
        sub_448EB0(Str, v24, 48);
      }
      v25 = (void **)v74[0];
      v63 = 0;
      if ( v75 < 0x10 )
        v25 = v74;
      v26 = Str[0];
      if ( v73 < 0x10 )
        v26 = (const char *)Str;
      v27 = strcspn(v26, &Control);
      for ( LOBYTE(v28) = *(_BYTE *)v25; *(_BYTE *)v25 != 127; LOBYTE(v28) = *(_BYTE *)v25 )
      {
        if ( (char)v28 <= 0 )
          break;
        v28 = (char)v28;
        if ( (char)v28 >= v27 - v58._Wchar )
          break;
        v27 -= v28;
        sub_44CB90(v27, (int *)Str, 1u, 0);
        if ( *((char *)v25 + 1) > 0 )
          v25 = (void **)((char *)v25 + 1);
      }
      v11 = Str[0];
      if ( v73 < 0x10 )
        v11 = (char *)Str;
      v12 = v72;
      Size = 0;
    }
  }
  v29 = v67;
  v30 = *(_DWORD *)(v67 + 32);
  v31 = v63 + v66 + v12 + Size;
  if ( *(__int64 *)(v67 + 32) <= 0 || v30 <= v31 )
  {
    *(_DWORD *)&v58._Byte = 0;
    v32 = 0;
  }
  else
  {
    v32 = v30 - v31;
    *(_DWORD *)&v58._Byte = v30 - v31;
  }
  v33 = *(_DWORD *)(v67 + 20) & 0x1C0;
  if ( v33 != 64 )
  {
    if ( v33 == 256 && v58._Wchar )
    {
      v34 = sub_448FF0(v11, v62, v69, a10, a11, 1);
      a10 = *v34;
      ++v11;
      a11 = (_DWORD *)v34[1];
      --v12;
    }
    v35 = sub_447710(v32, a6, v69, a10, a11);
    a10 = *v35;
    v36 = (_DWORD *)v35[1];
    *(_DWORD *)&v58._Byte = 0;
    a11 = v36;
  }
  v37 = memchr(v11, Control, v12);
  if ( v37 )
  {
    v38 = v37 - v11;
    v39 = v38 + 1;
    v40 = sub_4490D0(v64, v62, v69, v11, v38, a10, a11);
    v41 = sub_447710(v63, v65[0], v69, *v40, (_DWORD *)v40[1]);
    v77 = *v41;
    v78 = (_DWORD *)v41[1];
    v42 = (*(int (__thiscall **)(int))(*(_DWORD *)v68[0] + 4))(v68[0]);
    v43 = sub_447710(1, v42, v68, v77, v78);
    v44 = sub_447710(v66, v65[0], v68, *v43, (_DWORD *)v43[1]);
    a10 = *v44;
    v11 += v39;
    v12 -= v39;
    v29 = v67;
    a11 = (_DWORD *)v44[1];
  }
  v45 = memchr(v11, 101, v12);
  if ( v45 )
  {
    v46 = v45 - v11;
    v47 = v46 + 1;
    v48 = sub_4490D0(v64, v62, v68, v11, v46, a10, a11);
    v49 = sub_447710(Size, v65[0], v68, *v48, (_DWORD *)v48[1]);
    Size = 0;
    v50 = "E";
    if ( (*(_BYTE *)(v67 + 20) & 4) == 0 )
      v50 = "e";
    v51 = sub_448FF0(v50, v62, v68, *v49, (_DWORD *)v49[1], 1);
    a10 = *v51;
    v11 += v47;
    v12 -= v47;
    v29 = v67;
    a11 = (_DWORD *)v51[1];
  }
  v52 = sub_4490D0(v64, v62, v68, v11, v12, a10, a11);
  v53 = sub_447710(Size, v65[0], v68, *v52, (_DWORD *)v52[1]);
  v54 = *v53;
  v56 = (_DWORD *)v53[1];
  *(_DWORD *)(v29 + 32) = 0;
  *(_DWORD *)(v29 + 36) = 0;
  sub_447710(*(int *)&v58._Byte, a6, a4, v54, v56);
  if ( v73 >= 0x10 )
    operator delete(Str[0]);
  v73 = 15;
  v72 = 0;
  LOBYTE(Str[0]) = 0;
  if ( v75 >= 0x10 )
    operator delete(v74[0]);
  return a4;
}
