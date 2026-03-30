float *sub_44E0E0()
{
  _DWORD *v0; // eax
  char *v1; // eax
  char *v2; // eax
  char *v3; // eax
  int i; // edi
  char *v5; // eax
  char *v6; // esi
  int v7; // ecx
  _DWORD *v8; // eax
  int j; // edi
  char *v10; // eax
  char *v11; // esi
  _DWORD *v12; // eax
  char *v14; // [esp+10h] [ebp-30h] BYREF
  char *v15[2]; // [esp+14h] [ebp-2Ch] BYREF
  _DWORD pExceptionObject[3]; // [esp+1Ch] [ebp-24h] BYREF
  _DWORD v17[3]; // [esp+28h] [ebp-18h] BYREF
  int v18; // [esp+3Ch] [ebp-4h]

  v15[1] = (char *)&flt_4D8B4C;
  dword_4D8B54 = 0;
  v0 = operator new(0xCu);
  if ( !v0 )
  {
    v14 = 0;
    std::exception::exception((std::exception *)v17, (const char *const *)&v14);
    v17[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(v17, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  dword_4D8B50 = (int)v0;
  *v0 = v0;
  *(_DWORD *)(dword_4D8B50 + 4) = dword_4D8B50;
  v18 = 0;
  dword_4D8B60 = 0;
  v1 = (char *)operator new(0xCu);
  if ( !v1 )
  {
    v15[0] = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)v15);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  dword_4D8B5C = v1;
  *(_DWORD *)v1 = v1;
  *((_DWORD *)dword_4D8B5C + 1) = dword_4D8B5C;
  LOBYTE(v18) = 1;
  dword_4D8B6C = 0;
  v2 = (char *)operator new(0xCu);
  if ( !v2 )
  {
    v14 = 0;
    std::exception::exception((std::exception *)v17, (const char *const *)&v14);
    v17[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(v17, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  dword_4D8B68 = v2;
  *(_DWORD *)v2 = v2;
  *((_DWORD *)dword_4D8B68 + 1) = dword_4D8B68;
  LOBYTE(v18) = 2;
  dword_4D8B78 = 0;
  v3 = (char *)operator new(0xCu);
  if ( !v3 )
  {
    v15[0] = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)v15);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  dword_4D8B74 = v3;
  *(_DWORD *)v3 = v3;
  *((_DWORD *)dword_4D8B74 + 1) = dword_4D8B74;
  LOBYTE(v18) = 3;
  for ( i = 0; i < 3000; ++i )
  {
    v5 = (char *)operator new(0x24u);
    v6 = dword_4D8B5C;
    v7 = *((_DWORD *)dword_4D8B5C + 1);
    v14 = v5;
    v8 = sub_40FD70(dword_4D8B5C, v7, &v14);
    if ( dword_4D8B60 == 1073741822 )
LABEL_12:
      std::_Xlength_error("list<T> too long");
    ++dword_4D8B60;
    *((_DWORD *)v6 + 1) = v8;
    *(_DWORD *)v8[1] = v8;
  }
  for ( j = 0; j < 3000; ++j )
  {
    v10 = (char *)operator new(0x2Cu);
    v11 = dword_4D8B74;
    v14 = v10;
    v12 = sub_40FD70(dword_4D8B74, *((_DWORD *)dword_4D8B74 + 1), &v14);
    if ( dword_4D8B78 == 1073741822 )
      goto LABEL_12;
    ++dword_4D8B78;
    *((_DWORD *)v11 + 1) = v12;
    *(_DWORD *)v12[1] = v12;
  }
  flt_4D8B4C = 0.0;
  return &flt_4D8B4C;
}
