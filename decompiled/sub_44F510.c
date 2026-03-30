void __cdecl sub_44F510(void ***a1, int a2)
{
  void **v2; // eax
  void ***v3; // ecx
  void **v4; // esi
  _DWORD *EngineInstance; // esi
  int v6; // esi
  int v7; // edi
  void **v8; // esi
  double v9; // st7
  _DWORD *v10; // ecx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  _DWORD *v14; // ecx
  int v15; // edx
  int v16; // edx
  int v17; // edx
  void *v18; // esi
  _DWORD *v19; // esi
  int v20; // esi
  void **v21; // eax
  void **v22; // esi
  int v23; // [esp+3Ch] [ebp-18h] BYREF
  __int64 v24; // [esp+40h] [ebp-14h]
  int v25; // [esp+50h] [ebp-4h]

  v25 = 0;
  if ( a2 )
  {
    EngineInstance = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v6 = EngineInstance[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v6 + 228))(v6, 137, 0);
    v7 = -1;
    if ( (*(int (__stdcall **)(int, _DWORD, _DWORD, int *, int))(*(_DWORD *)dword_4D7FE8 + 44))(
           dword_4D7FE8,
           0,
           0,
           &v23,
           0x2000) >= 0 )
    {
      v8 = *a1;
      if ( *a1 != (void **)a1 )
      {
        v9 = 255.0;
        do
        {
          v10 = (_DWORD *)(v23 + 16 * (v7 + 1));
          v7 += 2;
          *v10 = v8[2];
          v10[1] = v8[3];
          v10[2] = v8[4];
          v24 = (__int64)(*((float *)v8 + 8) * v9);
          v11 = (unsigned __int8)v24;
          v24 = (__int64)(*((float *)v8 + 11) * v9);
          v12 = (((_DWORD)v24 << 8) | v11) << 8;
          v24 = (__int64)(*((float *)v8 + 9) * v9);
          v13 = ((unsigned __int8)v24 | v12) << 8;
          v24 = (__int64)(*((float *)v8 + 10) * v9);
          v10[3] = (unsigned __int8)v24 | v13;
          v14 = (_DWORD *)(v23 + 16 * v7);
          *v14 = v8[5];
          v14[1] = v8[6];
          v14[2] = v8[7];
          v24 = (__int64)(*((float *)v8 + 8) * v9);
          v15 = (unsigned __int8)v24;
          v24 = (__int64)(*((float *)v8 + 11) * v9);
          v16 = (((_DWORD)v24 << 8) | v15) << 8;
          v24 = (__int64)(*((float *)v8 + 9) * v9);
          v17 = ((unsigned __int8)v24 | v16) << 8;
          v24 = (__int64)(*((float *)v8 + 10) * v9);
          v14[3] = (unsigned __int8)v24 | v17;
          if ( v7 + 1 >= dword_4D7FF4 )
          {
            (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D7FE8 + 48))(dword_4D7FE8);
            dword_4D7FF0 = (unsigned int)dword_4D7FF4 >> 1;
            sub_44F2A0(
              flt_4D53B4,
              (int)&unk_4D8BA8,
              dword_4D8040[0],
              dword_4D7FE8,
              (unsigned int)dword_4D7FF4 >> 1,
              dword_4D7FEC,
              dword_4D7FF8,
              dword_4D7FFC);
            v7 = -1;
            if ( (*(int (__stdcall **)(int, _DWORD, _DWORD, int *, int))(*(_DWORD *)dword_4D7FE8 + 44))(
                   dword_4D7FE8,
                   0,
                   0,
                   &v23,
                   0x2000) < 0 )
              break;
            v9 = 255.0;
          }
          v8 = (void **)*v8;
        }
        while ( v8 != (void **)a1 );
      }
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D7FE8 + 48))(dword_4D7FE8);
    }
    dword_4D7FF0 = (v7 + 1) / 2;
    sub_44F2A0(
      flt_4D53B4,
      (int)&unk_4D8BA8,
      dword_4D8040[0],
      dword_4D7FE8,
      (v7 + 1) / 2,
      dword_4D7FEC,
      dword_4D7FF8,
      dword_4D7FFC);
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      LOBYTE(v25) = 1;
      if ( !dword_4D7F04 )
      {
        v18 = operator new(0x1E80u);
        if ( v18 )
          sub_419430((int)v18);
        else
          v18 = 0;
        dword_4D7F04 = v18;
      }
      atexit(sub_4724C0);
      LOBYTE(v25) = 0;
    }
    v19 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v20 = v19[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v20 + 228))(v20, 137, 1);
    v21 = *a1;
    *a1 = (void **)a1;
    a1[1] = (void **)a1;
    v3 = a1;
    if ( v21 != (void **)a1 )
    {
      do
      {
        v22 = (void **)*v21;
        operator delete(v21);
        v3 = a1;
        v21 = v22;
      }
      while ( v22 != (void **)a1 );
    }
  }
  else
  {
    v2 = *a1;
    *a1 = (void **)a1;
    a1[1] = (void **)a1;
    v3 = a1;
    if ( v2 != (void **)a1 )
    {
      do
      {
        v4 = (void **)*v2;
        operator delete(v2);
        v3 = a1;
        v2 = v4;
      }
      while ( v4 != (void **)a1 );
    }
  }
  operator delete(v3);
}
