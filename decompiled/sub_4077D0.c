char __cdecl sub_4077D0(int a1, int a2)
{
  char *v2; // eax
  char *i; // esi
  char *v4; // eax
  int v5; // ecx
  double v6; // st7
  float *v7; // eax
  char *v9; // [esp+10h] [ebp-2Ch] BYREF
  char *v10; // [esp+14h] [ebp-28h] BYREF
  _DWORD pExceptionObject[3]; // [esp+18h] [ebp-24h] BYREF
  _DWORD v12[3]; // [esp+24h] [ebp-18h] BYREF
  int v13; // [esp+38h] [ebp-4h]

  if ( (dword_4D8E14 & 1) == 0 )
  {
    dword_4D8E14 |= 1u;
    v13 = 0;
    dword_4D8E0C = 0;
    v2 = (char *)operator new(0xCu);
    if ( !v2 )
    {
      *(float *)&v9 = 0.0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v9);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
    dword_4D8E08 = v2;
    *(_DWORD *)v2 = v2;
    *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
    atexit(sub_472020);
    v13 = -1;
  }
  for ( i = *(char **)dword_4D8E08; ; i = *(char **)i )
  {
    if ( (dword_4D8E14 & 1) == 0 )
    {
      dword_4D8E14 |= 1u;
      v13 = 1;
      dword_4D8E0C = 0;
      v4 = (char *)operator new(0xCu);
      if ( !v4 )
      {
        *(float *)&v10 = 0.0;
        std::exception::exception((std::exception *)v12, (const char *const *)&v10);
        v12[0] = &std::bad_alloc::`vftable';
        _CxxThrowException(v12, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
      }
      dword_4D8E08 = v4;
      *(_DWORD *)v4 = v4;
      *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
      atexit(sub_472020);
      v13 = -1;
    }
    if ( i == dword_4D8E08 )
      return 0;
    v5 = *((_DWORD *)i + 2);
    if ( a1 == *(_DWORD *)(v5 + 524) )
      break;
  }
  if ( *(_BYTE *)(v5 + 532) )
  {
    *(float *)&v9 = (double)*(int *)(a2 + 80) / 1000.0;
    v6 = 0.0;
    if ( *(float *)&v9 < 0.0 || (v6 = 1.0, *(float *)&v9 > 1.0) )
      *(float *)&v9 = v6;
    v7 = *(float **)v5;
    *(float *)&v10 = (*(float *)(v5 + 4) - *(float *)(v5 + 8)) * *(float *)&v9 + *(float *)(v5 + 8);
    *v7 = *(float *)&v10;
    return 1;
  }
  else
  {
    sub_436780((char **)a2, *(float **)v5);
    return 1;
  }
}
