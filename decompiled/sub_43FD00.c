char **__cdecl sub_43FD00()
{
  char *v0; // eax
  _DWORD *v1; // eax
  _DWORD *v2; // eax
  float v4; // [esp+18h] [ebp-8Ch] BYREF
  float v5; // [esp+1Ch] [ebp-88h]
  float v6; // [esp+20h] [ebp-84h]
  float v7; // [esp+24h] [ebp-80h]
  char *v8; // [esp+28h] [ebp-7Ch] BYREF
  _DWORD pExceptionObject[3]; // [esp+2Ch] [ebp-78h] BYREF
  char *v10[2]; // [esp+38h] [ebp-6Ch] BYREF
  void *v11[4]; // [esp+40h] [ebp-64h] BYREF
  int v12; // [esp+50h] [ebp-54h]
  unsigned int v13; // [esp+54h] [ebp-50h]
  void *v14[4]; // [esp+5Ch] [ebp-48h] BYREF
  int v15; // [esp+6Ch] [ebp-38h]
  unsigned int v16; // [esp+70h] [ebp-34h]
  void *v17[7]; // [esp+78h] [ebp-2Ch] BYREF
  int v18; // [esp+A0h] [ebp-4h]

  v10[1] = (char *)&dword_4D8E20;
  dword_4D8E24 = 0;
  v0 = (char *)operator new(0xCu);
  if ( !v0 )
  {
    v8 = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v8);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  dword_4D8E20 = v0;
  *(_DWORD *)v0 = v0;
  *((_DWORD *)dword_4D8E20 + 1) = dword_4D8E20;
  v18 = 0;
  dword_4D8E2C = 0;
  v1 = operator new(8u);
  if ( !v1 )
  {
    v10[0] = 0;
    std::exception::exception((std::exception *)&v4, (const char *const *)v10);
    v4 = COERCE_FLOAT(&std::bad_alloc::`vftable');
    _CxxThrowException(&v4, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  dword_4D8E2C = v1;
  v1[1] = 0;
  *v1 = 0;
  *(_DWORD *)dword_4D8E2C = &dword_4D8E2C;
  dword_4D8E30 = 0;
  dword_4D8E34 = 0;
  dword_4D8E38 = 0;
  dword_4D8E3C = 0;
  LOBYTE(v18) = 1;
  dword_4D8E48 = 0;
  v2 = operator new(0x34u);
  if ( !v2 )
  {
    v8 = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v8);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  dword_4D8E44 = v2;
  *v2 = v2;
  *((_DWORD *)dword_4D8E44 + 1) = dword_4D8E44;
  dword_4D8E64 = 7;
  dword_4D8E60 = 0;
  LOWORD(dword_4D8E50) = 0;
  dword_4D8E6C = 0;
  dword_4D8E70 = 0;
  dword_4D8E74 = 0;
  dword_4D8E7C = 0;
  dword_4D8E80 = 0;
  dword_4D8E84 = 0;
  LOBYTE(v18) = 5;
  flt_4D8E94 = 0.0;
  dword_4D8E8C = 0;
  byte_4D8E90 = 0;
  v16 = 7;
  v15 = 0;
  LOWORD(v14[0]) = 0;
  sub_4032D0(L"GoBonsai ", (int)v14, 9u);
  LOBYTE(v18) = 6;
  sub_44A600((char *)v14, (int)v17);
  LOBYTE(v18) = 8;
  if ( v16 >= 8 )
    operator delete(v14[0]);
  v4 = 1.0;
  v5 = 1.0;
  LOWORD(v14[0]) = 0;
  v6 = flt_4D63B0;
  v16 = 7;
  v15 = 0;
  v7 = 1.0;
  sub_441E00((int *)&v4, (int)&dword_4D8E20, v17);
  sub_4032D0(&unk_4B6DD8, (int)v17, 0x12u);
  v4 = 1.0;
  v5 = 1.0;
  v6 = flt_4D63B0;
  v7 = 1.0;
  sub_441E00((int *)&v4, (int)&dword_4D8E20, v17);
  v13 = 7;
  v12 = 0;
  LOWORD(v11[0]) = 0;
  sub_4032D0(&word_4B765C, (int)v11, 0);
  LOBYTE(v18) = 9;
  v4 = 1.0;
  v5 = 1.0;
  v6 = 1.0;
  v7 = 1.0;
  sub_441E00((int *)&v4, (int)&dword_4D8E20, v11);
  LOBYTE(v18) = 8;
  if ( v13 >= 8 )
    operator delete(v11[0]);
  v13 = 7;
  v12 = 0;
  LOWORD(v11[0]) = 0;
  sub_4032D0(L"Type \"help\" for info about the debug console.", (int)v11, 0x2Du);
  LOBYTE(v18) = 10;
  v4 = 1.0;
  v5 = 1.0;
  v6 = 1.0;
  v7 = 1.0;
  sub_441E00((int *)&v4, (int)&dword_4D8E20, v11);
  LOBYTE(v18) = 8;
  if ( v13 >= 8 )
    operator delete(v11[0]);
  v13 = 7;
  v12 = 0;
  LOWORD(v11[0]) = 0;
  sub_4032D0(&word_4B765C, (int)v11, 0);
  LOBYTE(v18) = 11;
  v4 = 1.0;
  v5 = 1.0;
  v6 = 1.0;
  v7 = 1.0;
  sub_441E00((int *)&v4, (int)&dword_4D8E20, v11);
  if ( v13 >= 8 )
    operator delete(v11[0]);
  if ( v17[5] >= (void *)8 )
    operator delete(v17[0]);
  return &dword_4D8E20;
}
