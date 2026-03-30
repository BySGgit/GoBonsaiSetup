char **__cdecl sub_4075C0(int a1)
{
  char *v1; // eax
  char *v2; // eax
  char **result; // eax
  int v4; // ebp
  int v5; // esi
  int v6; // ecx
  int *v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  int *v11; // ecx
  int v12; // ecx
  char *i; // [esp+14h] [ebp-30h]
  char *v14; // [esp+18h] [ebp-2Ch] BYREF
  char *v15; // [esp+1Ch] [ebp-28h] BYREF
  _DWORD pExceptionObject[3]; // [esp+20h] [ebp-24h] BYREF
  _DWORD v17[3]; // [esp+2Ch] [ebp-18h] BYREF
  int v18; // [esp+40h] [ebp-4h]

  if ( (dword_4D8E14 & 1) == 0 )
  {
    dword_4D8E14 |= 1u;
    v18 = 0;
    dword_4D8E0C = 0;
    v1 = (char *)operator new(0xCu);
    if ( !v1 )
    {
      v14 = 0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v14);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
    dword_4D8E08 = v1;
    *(_DWORD *)v1 = v1;
    *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
    atexit(sub_472020);
    v18 = -1;
  }
  for ( i = *(char **)dword_4D8E08; ; i = *result )
  {
    if ( (dword_4D8E14 & 1) == 0 )
    {
      dword_4D8E14 |= 1u;
      v18 = 1;
      dword_4D8E0C = 0;
      v2 = (char *)operator new(0xCu);
      if ( !v2 )
      {
        v15 = 0;
        std::exception::exception((std::exception *)v17, (const char *const *)&v15);
        v17[0] = &std::bad_alloc::`vftable';
        _CxxThrowException(v17, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
      }
      dword_4D8E08 = v2;
      *(_DWORD *)v2 = v2;
      *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
      atexit(sub_472020);
      v18 = -1;
    }
    result = (char **)i;
    if ( i == dword_4D8E08 )
      break;
    v4 = *((_DWORD *)i + 2);
    if ( *(_BYTE *)(v4 + 533) )
    {
      v5 = *(_DWORD *)(dword_4D7E54 + 612);
      v6 = 0;
      if ( v5 <= 0 )
      {
LABEL_14:
        v8 = 0;
      }
      else
      {
        v7 = *(int **)(dword_4D7E54 + 608);
        while ( *(_DWORD *)(*v7 + 44) != *(_DWORD *)(v4 + 524) )
        {
          ++v6;
          ++v7;
          if ( v6 >= v5 )
            goto LABEL_14;
        }
        v8 = *v7;
      }
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 64))(v8, a1);
      v9 = *(_DWORD *)(dword_4D7E54 + 612);
      v10 = 0;
      if ( v9 <= 0 )
      {
LABEL_19:
        v12 = 0;
      }
      else
      {
        v11 = *(int **)(dword_4D7E54 + 608);
        while ( *(_DWORD *)(*v11 + 44) != *(_DWORD *)(v4 + 528) )
        {
          ++v10;
          ++v11;
          if ( v10 >= v9 )
            goto LABEL_19;
        }
        v12 = *v11;
      }
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v12 + 64))(v12, a1);
      result = (char **)i;
    }
  }
  return result;
}
