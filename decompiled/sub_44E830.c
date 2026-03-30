void sub_44E830()
{
  _DWORD *EngineInstance; // esi
  int v1; // esi
  _DWORD *v2; // ebx
  int v3; // ebp
  int v4; // ebx
  int **v5; // eax
  int **v6; // esi
  char *i; // edi
  int *v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int *v19; // eax
  int *v20; // eax
  int **v21; // edi
  char **v22[2]; // [esp+70h] [ebp-158h] BYREF
  char *v23; // [esp+90h] [ebp-138h] BYREF
  float v24; // [esp+94h] [ebp-134h]
  float pExceptionObject[4]; // [esp+98h] [ebp-130h] BYREF
  float v26; // [esp+A8h] [ebp-120h]
  int **v27; // [esp+ACh] [ebp-11Ch] BYREF
  int v28; // [esp+B0h] [ebp-118h]
  int v29[16]; // [esp+B8h] [ebp-110h] BYREF
  _BYTE v30[64]; // [esp+F8h] [ebp-D0h] BYREF
  _DWORD v31[16]; // [esp+138h] [ebp-90h] BYREF
  _BYTE v32[64]; // [esp+178h] [ebp-50h] BYREF
  int v33; // [esp+1C4h] [ebp-4h]

  if ( byte_4CA648 )
  {
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v1 = EngineInstance[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 27, 1);
    (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v1 + 228))(v1, 15, 0);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 19, 5);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 20, 6);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 7, 1);
    (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v1 + 228))(v1, 14, 0);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 22, 1);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 137, 1);
    pExceptionObject[0] = 0.0;
    pExceptionObject[1] = 0.0;
    pExceptionObject[2] = 0.0;
    *(float *)&dword_4CA63C = 0.0;
    pExceptionObject[3] = 1.0;
    v2 = *(_DWORD **)dword_4D8B50;
    *(float *)&dword_4CA634 = 0.0;
    *(float *)&dword_4CA638 = 0.0;
    for ( *(float *)&dword_4CA640 = 1.0; v2 != (_DWORD *)dword_4D8B50; v2 = (_DWORD *)*v2 )
    {
      v3 = v2[2];
      v23 = *(char **)v3;
      v24 = *(float *)(v3 + 4);
      v26 = *(float *)(v3 + 8);
      D3DXMatrixTranslation(v29, v23, LODWORD(v24), LODWORD(v26));
      v23 = *(char **)(v3 + 32);
      D3DXMatrixScaling(v31, v23, v23, v23);
      D3DXMatrixMultiply(v30, v31, v29);
      qmemcpy(v32, v30, sizeof(v32));
      sub_44F2A0(
        (float *)(v3 + 12),
        (int)v32,
        dword_4D8040[0],
        dword_4D7FD0,
        dword_4D7FD8,
        dword_4D7FD4,
        dword_4D7FE0,
        dword_4D7FE4);
    }
    v4 = 0;
    v28 = 0;
    v5 = (int **)operator new(0x30u);
    v6 = v5;
    if ( !v5 )
    {
      *(float *)&v23 = 0.0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v23);
      LODWORD(pExceptionObject[0]) = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
    *v5 = (int *)v5;
    v27 = v5;
    v5[1] = (int *)v5;
    v33 = 0;
    for ( i = *(char **)dword_4D8B68; i != dword_4D8B68; v28 = v4 )
    {
      v8 = (int *)*((_DWORD *)i + 2);
      v9 = v8[1];
      v29[0] = *v8;
      v10 = v8[2];
      v29[1] = v9;
      v11 = v8[3];
      v29[2] = v10;
      v12 = v8[4];
      v29[3] = v11;
      v13 = v8[5];
      v29[4] = v12;
      v14 = v8[6];
      v29[5] = v13;
      v15 = v8[7];
      v29[6] = v14;
      v16 = v8[8];
      v17 = v8[9];
      v29[7] = v15;
      v29[8] = v16;
      v18 = (int)v6[1];
      v29[9] = v17;
      v19 = sub_44ECA0((char *)v6, v18, v29);
      if ( v4 == 107374181 )
        std::_Xlength_error("list<T> too long");
      v6[1] = v19;
      *(_DWORD *)v19[1] = v19;
      i = *(char **)i;
      ++v4;
    }
    v24 = COERCE_FLOAT(v22);
    sub_44EBA0(v22, &v27);
    sub_44F510((void ***)v22[0], (int)v22[1]);
    v20 = *v6;
    *v6 = (int *)v6;
    v6[1] = (int *)v6;
    if ( v20 != (int *)v6 )
    {
      do
      {
        v21 = (int **)*v20;
        operator delete(v20);
        v20 = (int *)v21;
      }
      while ( v21 != v6 );
    }
    operator delete(v6);
  }
}
