char **__cdecl sub_406D10(int a1)
{
  char *v1; // eax
  char *v2; // esi
  char *v3; // eax
  int v4; // ebp
  int v5; // edx
  int v6; // eax
  int *v7; // ecx
  int v8; // esi
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  _DWORD *v12; // ecx
  void (*v13)(void); // eax
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  _DWORD *v17; // ecx
  void (*v18)(void); // eax
  int v19; // ebx
  int v20; // edi
  void *v21; // esi
  _DWORD *v22; // eax
  int v23; // esi
  int v24; // eax
  _DWORD *v25; // edi
  void (__thiscall *v26)(int); // edx
  void (__thiscall *v27)(int); // edx
  char *i; // [esp+18h] [ebp-30h]
  char *v30; // [esp+1Ch] [ebp-2Ch] BYREF
  char *v31; // [esp+20h] [ebp-28h] BYREF
  _DWORD pExceptionObject[3]; // [esp+24h] [ebp-24h] BYREF
  _DWORD v33[3]; // [esp+30h] [ebp-18h] BYREF
  int v34; // [esp+44h] [ebp-4h]
  float v35; // [esp+4Ch] [ebp+4h]

  dword_4D7E54 = a1;
  if ( (dword_4D8E14 & 1) == 0 )
  {
    dword_4D8E14 |= 1u;
    v34 = 0;
    dword_4D8E0C = 0;
    v1 = (char *)operator new(0xCu);
    if ( !v1 )
    {
      v30 = 0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v30);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
    dword_4D8E08 = v1;
    *(_DWORD *)v1 = v1;
    *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
    atexit(sub_472020);
    v34 = -1;
  }
  v2 = *(char **)dword_4D8E08;
  for ( i = *(char **)dword_4D8E08; ; v2 = i )
  {
    if ( (dword_4D8E14 & 1) == 0 )
    {
      dword_4D8E14 |= 1u;
      v34 = 1;
      dword_4D8E0C = 0;
      v3 = (char *)operator new(0xCu);
      if ( !v3 )
      {
        v31 = 0;
        std::exception::exception((std::exception *)v33, (const char *const *)&v31);
        v33[0] = &std::bad_alloc::`vftable';
        _CxxThrowException(v33, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
      }
      dword_4D8E08 = v3;
      *(_DWORD *)v3 = v3;
      *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
      atexit(sub_472020);
      v34 = -1;
    }
    if ( v2 == dword_4D8E08 )
      break;
    v4 = *((_DWORD *)v2 + 2);
    if ( *(_BYTE *)(v4 + 532) )
    {
      v35 = (**(float **)v4 - *(float *)(v4 + 8)) / (*(float *)(v4 + 4) - *(float *)(v4 + 8));
      if ( v35 >= 0.0 )
      {
        if ( v35 > 1.0 )
          v35 = 1.0;
      }
      else
      {
        v35 = 0.0;
      }
      sub_42FF00(*(_DWORD *)(v4 + 524), (int)(v35 * 1000.0));
    }
    else
    {
      sub_42FFB0(*(_DWORD *)(v4 + 524));
      v5 = *(_DWORD *)(dword_4D7E54 + 612);
      v6 = 0;
      if ( v5 <= 0 )
      {
LABEL_20:
        v8 = 0;
      }
      else
      {
        v7 = *(int **)(dword_4D7E54 + 608);
        while ( 1 )
        {
          v8 = *v7;
          if ( *(_DWORD *)(*v7 + 44) == *(_DWORD *)(v4 + 524) )
            break;
          ++v6;
          ++v7;
          if ( v6 >= v5 )
            goto LABEL_20;
        }
      }
      sub_436890(*(float **)v4, v8);
      v9 = *(_DWORD *)(dword_4D7E54 + 612);
      v10 = 0;
      if ( v9 <= 0 )
      {
LABEL_25:
        v12 = 0;
      }
      else
      {
        v11 = *(_DWORD *)(dword_4D7E54 + 608);
        while ( *(_DWORD *)(*(_DWORD *)v11 + 44) != *(_DWORD *)(v4 + 524) )
        {
          ++v10;
          v11 += 4;
          if ( v10 >= v9 )
            goto LABEL_25;
        }
        v12 = *(_DWORD **)v11;
      }
      v13 = *(void (**)(void))(*v12 + 76);
      v12[25] = 0;
      v13();
      v14 = *(_DWORD *)(dword_4D7E54 + 612);
      v15 = 0;
      if ( v14 <= 0 )
      {
LABEL_30:
        v17 = 0;
      }
      else
      {
        v16 = *(_DWORD *)(dword_4D7E54 + 608);
        while ( *(_DWORD *)(*(_DWORD *)v16 + 44) != *(_DWORD *)(v4 + 524) )
        {
          ++v15;
          v16 += 4;
          if ( v15 >= v14 )
            goto LABEL_30;
        }
        v17 = *(_DWORD **)v16;
      }
      v18 = *(void (**)(void))(*v17 + 76);
      v17[26] = 0;
      v18();
    }
    v19 = *(_DWORD *)(v4 + 528);
    v20 = dword_4D7E54;
    v21 = operator new(0x258u);
    if ( v21 )
    {
      v22 = (_DWORD *)sub_432780(v20, (int)v21);
      v23 = (int)v22;
      if ( v22 )
      {
        if ( sub_4300A0(v20, v22) >= 0 )
        {
          v24 = *(_DWORD *)(v20 + 612);
          v25 = (_DWORD *)(v20 + 608);
          if ( sub_42DBC0(v24 + 1, (int)v25) >= 0 )
          {
            *(_DWORD *)(*v25 + 4 * v25[1]++) = v23;
            *(_DWORD *)(v23 + 44) = v19;
            sub_4328A0(v23, v4 + 12);
            v26 = *(void (__thiscall **)(int))(*(_DWORD *)v23 + 76);
            *(_DWORD *)(v23 + 8) = 0;
            *(_DWORD *)(v23 + 12) = 0;
            v26(v23);
            v27 = *(void (__thiscall **)(int))(*(_DWORD *)v23 + 76);
            *(_DWORD *)(v23 + 16) = 0;
            *(_DWORD *)(v23 + 20) = 0;
            v27(v23);
            *(_BYTE *)(v23 + 7) = 0;
          }
        }
      }
    }
    i = *(char **)i;
  }
  sub_407060();
  return sub_4075C0(0);
}
