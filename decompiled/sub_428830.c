int __stdcall sub_428830(int a1, int a2)
{
  int *EngineInstance; // esi
  int v3; // esi
  int v4; // ebx
  int *v5; // esi
  int v6; // esi
  _DWORD *v8; // ebp
  int (__stdcall *v9)(int); // ecx
  int v10; // edi
  _DWORD *v11; // eax
  int v12; // esi
  int (__stdcall *v13)(int, int, int); // ecx
  _DWORD *v14; // ecx
  unsigned int *v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int *v20; // esi
  int v21; // ebp
  int v22; // edi
  int v23; // ebp
  int v24; // esi
  const char *v25; // ebx
  int k; // ebx
  int v27; // esi
  int v28; // eax
  _WORD *v29; // ecx
  int v30; // edx
  bool v31; // zf
  int v32; // ecx
  char *v33; // eax
  int v34; // esi
  int v35; // edi
  __int16 v36; // dx
  char v37; // [esp+41h] [ebp-135h]
  _DWORD *v38; // [esp+42h] [ebp-134h]
  void *Block; // [esp+46h] [ebp-130h] BYREF
  int v40; // [esp+4Ah] [ebp-12Ch]
  int v41; // [esp+4Eh] [ebp-128h]
  int v42; // [esp+52h] [ebp-124h]
  void *v43; // [esp+56h] [ebp-120h]
  unsigned int i; // [esp+5Ah] [ebp-11Ch]
  unsigned int j; // [esp+5Eh] [ebp-118h]
  int v46; // [esp+62h] [ebp-114h]
  unsigned int v47; // [esp+66h] [ebp-110h]
  unsigned int v48; // [esp+6Ah] [ebp-10Ch]
  unsigned int v49; // [esp+6Eh] [ebp-108h] BYREF
  unsigned int v50; // [esp+72h] [ebp-104h]
  unsigned int v51; // [esp+76h] [ebp-100h]
  unsigned int v52; // [esp+7Ah] [ebp-FCh]
  char v53[12]; // [esp+7Eh] [ebp-F8h] BYREF
  int v54; // [esp+8Ah] [ebp-ECh]
  _DWORD v55[4]; // [esp+8Eh] [ebp-E8h]
  wchar_t Buffer[100]; // [esp+9Eh] [ebp-D8h] BYREF
  int v57; // [esp+172h] [ebp-4h]

  v38 = dword_4D7F18;
  sub_41F750();
  EngineInstance = (int *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = *EngineInstance;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v4 = v3;
  if ( v3 )
    goto LABEL_12;
  sub_41F750();
  v5 = (int *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = *v5;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v4 = v6;
  if ( !v6 )
    return -2147219199;
LABEL_12:
  v8 = v38;
  *(_BYTE *)v38 = 1;
  v38[1] = v4;
  v38[2] = a1;
  v38[3] = a2;
  sub_429560((int)v38);
  Block = 0;
  v40 = 0;
  v41 = 0;
  v57 = 0;
  v9 = *(int (__stdcall **)(int))(*(_DWORD *)v4 + 16);
  v55[0] = 22;
  v55[1] = 24;
  v55[2] = 23;
  v55[3] = 35;
  v47 = v9(v4);
  v42 = 0;
  if ( v47 )
  {
    while ( 1 )
    {
      v10 = v42;
      v11 = operator new(0x668u);
      v43 = v11;
      if ( !v11 )
        break;
      v11[404] = 0;
      v11[405] = 0;
      v11[406] = 0;
      v11[407] = 0;
      v11[408] = 0;
      v11[409] = 0;
      *v11 = v10;
      (*(void (__stdcall **)(int, int, _DWORD, _DWORD *))(*(_DWORD *)v4 + 20))(v4, v10, 0, v11 + 1);
      if ( Block )
      {
        free(Block);
        Block = 0;
      }
      v12 = 0;
      v41 = 0;
      v40 = 0;
      for ( i = 0; i < 4; ++i )
      {
        v13 = *(int (__stdcall **)(int, int, int))(*(_DWORD *)v4 + 24);
        v46 = v55[i];
        v48 = v13(v4, v42, v46);
        for ( j = 0; j < v48; ++j )
        {
          (*(void (__stdcall **)(int, int, int, unsigned int, unsigned int *))(*(_DWORD *)v4 + 28))(
            v4,
            v42,
            v46,
            j,
            &v49);
          if ( v49 >= v8[15] && v50 >= v8[17] && v49 <= v8[16] && v50 <= v8[18] && v51 >= v8[19] && v51 <= v8[20] )
          {
            if ( sub_42DA40(*((_DWORD *)v43 + 405) + 1, (int)v43 + 1616) >= 0 )
            {
              v14 = v43;
              v15 = (unsigned int *)(*((_DWORD *)v43 + 404) + 16 * *((_DWORD *)v43 + 405));
              *v15 = v49;
              v15[1] = v50;
              v15[2] = v51;
              v15[3] = v52;
              ++v14[405];
            }
            if ( v12 <= 0 )
              goto LABEL_32;
            v16 = 0;
            while ( v52 != *((_DWORD *)Block + v16) )
            {
              if ( ++v16 >= v12 )
                goto LABEL_32;
            }
            if ( v16 == -1 )
            {
LABEL_32:
              v17 = sub_42DBC0(v12 + 1, (int)&Block);
              v12 = v40;
              if ( v17 >= 0 )
              {
                *((_DWORD *)Block + v40) = v52;
                v40 = ++v12;
              }
            }
          }
        }
      }
      (*(void (__stdcall **)(int, int, char *))(*(_DWORD *)v4 + 32))(v4, v42, v53);
      if ( v12 <= 0 )
        goto LABEL_42;
      v18 = 0;
      while ( v54 != *((_DWORD *)Block + v18) )
      {
        if ( ++v18 >= v12 )
          goto LABEL_42;
      }
      if ( v18 == -1 )
      {
LABEL_42:
        if ( sub_42DBC0(v12 + 1, (int)&Block) >= 0 )
        {
          v19 = v40;
          *((_DWORD *)Block + v40) = v54;
          v40 = v19 + 1;
        }
      }
      v20 = (int *)v43;
      qsort(
        *((void **)v43 + 404),
        *((_DWORD *)v43 + 405),
        0x10u,
        (_CoreCrtNonSecureSearchSortCompareFunction)CompareFunction);
      if ( sub_428DD0((unsigned int)v8, v20, &Block) < 0 || v20[408] <= 0 )
      {
        sub_4296C0((int)v20);
        operator delete(v20);
      }
      else
      {
        v21 = sub_42DBC0(v38[23] + 1, (int)(v38 + 22));
        if ( v21 < 0 )
        {
          if ( (v40 <= 0 || Block) && Block )
            free(Block);
          return v21;
        }
        v8 = v38;
        *(_DWORD *)(v38[22] + 4 * v38[23]++) = v20;
      }
      if ( ++v42 >= v47 )
        goto LABEL_50;
    }
    if ( (v40 <= 0 || Block) && Block )
      free(Block);
    return -2147024882;
  }
  else
  {
LABEL_50:
    v22 = 0;
    v37 = 1;
    if ( (int)v8[23] > 0 )
    {
      v23 = 1;
      while ( 1 )
      {
        v24 = v23;
        if ( v23 < v38[23] )
          break;
LABEL_56:
        ++v22;
        ++v23;
        if ( v22 >= v38[23] )
          goto LABEL_69;
      }
      v25 = (const char *)(*(_DWORD *)(v38[22] + 4 * v22) + 516);
      while ( _stricmp(v25, (const char *)(*(_DWORD *)(v38[22] + 4 * v24) + 516)) )
      {
        if ( ++v24 >= v38[23] )
          goto LABEL_56;
      }
      v37 = 0;
    }
LABEL_69:
    for ( k = 0; k < v38[23]; ++k )
    {
      v27 = *(_DWORD *)(v38[22] + 4 * k);
      MultiByteToWideChar(0, 0, (LPCCH)(v27 + 516), -1, (LPWSTR)(v27 + 1104), 100);
      *(_WORD *)(v27 + 1304) = 0;
      if ( !v37 )
      {
        sub_419310(Buffer, (wchar_t *)L" (#%d)", *(_DWORD *)v27);
        v28 = 256;
        v29 = (_WORD *)(v27 + 1104);
        while ( *v29 )
        {
          ++v29;
          if ( !--v28 )
            goto LABEL_84;
        }
        v30 = 256 - v28;
        v32 = v28;
        v31 = v28 == 0;
        v33 = (char *)(v27 + 1104 + 2 * (256 - v28));
        if ( v31 )
        {
LABEL_82:
          v33 -= 2;
        }
        else
        {
          v34 = v32 + v30 + 2147483391;
          v35 = (char *)Buffer - v33;
          while ( v34 )
          {
            v36 = *(_WORD *)&v33[v35];
            if ( !v36 )
              break;
            *(_WORD *)v33 = v36;
            v33 += 2;
            --v34;
            if ( !--v32 )
              goto LABEL_82;
          }
        }
        *(_WORD *)v33 = 0;
      }
LABEL_84:
      ;
    }
    if ( v40 <= 0 || Block )
    {
      if ( Block )
        free(Block);
    }
    return 0;
  }
}
