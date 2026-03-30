int __stdcall sub_44BE10(int a1)
{
  int v1; // esi
  char *v2; // edi
  _BYTE *v3; // eax
  _BYTE *v4; // ecx
  char v5; // dl
  int v6; // edx
  int v7; // edx
  _Cvtvec *v8; // eax
  int v9; // edi
  int v10; // edx
  _BYTE *v11; // edx
  _BYTE *v12; // eax
  int v13; // edx
  _Cvtvec *v14; // eax
  int v15; // edx
  unsigned int v16; // edx
  int result; // eax
  _Cvtvec *v18; // [esp+0h] [ebp-44h] BYREF
  _Cvtvec v19; // [esp+14h] [ebp-30h] BYREF
  int v20; // [esp+40h] [ebp-4h]

  *(_DWORD *)&v19._Isleadbyte[20] = &v18;
  v1 = a1;
  *(_DWORD *)&v19._Isleadbyte[4] = localeconv();
  *(_DWORD *)(v1 + 8) = 0;
  *(_DWORD *)(v1 + 16) = 0;
  *(_DWORD *)(v1 + 20) = 0;
  v20 = 0;
  v2 = (char *)&unk_4BC05D;
  _Getcvt(v18);
  *(_DWORD *)&v19._Isleadbyte[12] = 1;
  v3 = operator new[](1u);
  v4 = v3;
  while ( *(_DWORD *)&v19._Isleadbyte[12] )
  {
    v5 = *v2;
    --*(_DWORD *)&v19._Isleadbyte[12];
    *v4++ = v5;
    ++v2;
  }
  *(_DWORD *)(v1 + 8) = v3;
  *(_DWORD *)&v19._Isleadbyte[8] = _Getcvt(v18);
  *(_DWORD *)&v19._Isleadbyte[12] = v6;
  *(_DWORD *)(v1 + 16) = sub_44C590("false", (_Cvtvec *)&v19._Isleadbyte[8]);
  *(_DWORD *)&v19._Isleadbyte[8] = _Getcvt(v18);
  *(_DWORD *)&v19._Isleadbyte[12] = v7;
  *(_DWORD *)(v1 + 20) = sub_44C590("true", (_Cvtvec *)&v19._Isleadbyte[8]);
  v8 = _Getcvt(v18);
  v9 = *(_DWORD *)&v19._Isleadbyte[4];
  *(_DWORD *)v19._Isleadbyte = v10;
  v11 = **(_BYTE ***)&v19._Isleadbyte[4];
  v19._Isclocale = (int)v8;
  LOBYTE(a1) = *v11;
  *(_DWORD *)&v19._Isleadbyte[12] = 0;
  *(_DWORD *)&v19._Isleadbyte[4] = 0;
  _Mbrtowc(
    (wchar_t *)&v19._Isleadbyte[12],
    (const char *)&a1,
    1u,
    (mbstate_t *)&v19._Isleadbyte[4],
    (const _Cvtvec *)&v19._Isclocale);
  *(_WORD *)(v1 + 12) = *(_WORD *)&v19._Isleadbyte[12];
  v19._Isclocale = (int)_Getcvt(v18);
  v12 = *(_BYTE **)(v9 + 4);
  *(_DWORD *)v19._Isleadbyte = v13;
  LOBYTE(a1) = *v12;
  *(_DWORD *)&v19._Isleadbyte[12] = 0;
  *(_DWORD *)&v19._Isleadbyte[4] = 0;
  _Mbrtowc(
    (wchar_t *)&v19._Isleadbyte[12],
    (const char *)&a1,
    1u,
    (mbstate_t *)&v19._Isleadbyte[4],
    (const _Cvtvec *)&v19._Isclocale);
  *(_WORD *)(v1 + 14) = *(_WORD *)&v19._Isleadbyte[12];
  v14 = _Getcvt(v18);
  *(_DWORD *)v19._Isleadbyte = v15;
  v19._Isclocale = (int)v14;
  LOBYTE(a1) = 46;
  *(_DWORD *)&v19._Isleadbyte[12] = 0;
  *(_DWORD *)&v19._Isleadbyte[4] = 0;
  _Mbrtowc(
    (wchar_t *)&v19._Isleadbyte[12],
    (const char *)&a1,
    1u,
    (mbstate_t *)&v19._Isleadbyte[4],
    (const _Cvtvec *)&v19._Isclocale);
  *(_WORD *)(v1 + 12) = *(_WORD *)&v19._Isleadbyte[12];
  v19._Page = (unsigned int)_Getcvt(v18);
  v19._Mbcurmax = v16;
  LOBYTE(a1) = 44;
  *(_DWORD *)&v19._Isleadbyte[4] = 0;
  *(_DWORD *)v19._Isleadbyte = 0;
  result = _Mbrtowc((wchar_t *)&v19._Isleadbyte[4], (const char *)&a1, 1u, (mbstate_t *)v19._Isleadbyte, &v19);
  *(_WORD *)(v1 + 14) = *(_WORD *)&v19._Isleadbyte[4];
  return result;
}
