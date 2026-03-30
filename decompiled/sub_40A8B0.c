int sub_40A8B0()
{
  _DWORD *EngineInstance; // esi
  int v1; // ebp
  int result; // eax
  _DWORD *v3; // esi
  int v4; // esi
  _DWORD *v5; // esi
  int v6; // esi
  void *v7; // [esp+78h] [ebp-48h] BYREF
  float v8; // [esp+7Ch] [ebp-44h]
  float v9; // [esp+80h] [ebp-40h]
  float v10; // [esp+84h] [ebp-3Ch]
  int v11; // [esp+88h] [ebp-38h]
  unsigned int v12; // [esp+8Ch] [ebp-34h]
  void *v13[5]; // [esp+94h] [ebp-2Ch] BYREF
  unsigned int v14; // [esp+A8h] [ebp-18h]
  int v15; // [esp+BCh] [ebp-4h]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v1 + 228))(v1, 27, 0);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 7, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 14, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 22, 3);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 137, 1);
  result = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 143, 1);
  if ( dword_4D7E98 )
  {
    if ( (dword_4DBDF0 & 1) == 0 )
    {
      dword_4DBDF0 |= 1u;
      v15 = 0;
      v11 = 0;
      LOWORD(v7) = 0;
      v12 = 7;
      sub_4032D0(L"specularBark", (int)&v7, 0xCu);
      LOBYTE(v15) = 1;
      sub_408600(&v7, (int)&unk_4DBDCC, (int)&flt_4D62B4);
      if ( v12 >= 8 )
        operator delete(v7);
      atexit(sub_472090);
      v15 = -1;
    }
    *(float *)&v7 = flt_4D62B4;
    v8 = flt_4D62B4;
    v9 = flt_4D62B4;
    dword_4CA634 = LODWORD(flt_4D62B4);
    dword_4CA638 = LODWORD(flt_4D62B4);
    v10 = 1.0;
    dword_4CA63C = LODWORD(flt_4D62B4);
    *(float *)&dword_4CA640 = 1.0;
    result = sub_44F2A0(
               flt_4D53B4,
               (int)&unk_4D8BA8,
               dword_4D8084,
               dword_4D7E90,
               dword_4D7E98,
               dword_4D7E94,
               dword_4D7EA0,
               dword_4D7EA4);
  }
  if ( dword_4D8644 != 1 )
  {
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 24, 136);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 25, 7);
    (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v1 + 228))(v1, 15, 1);
    result = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v1 + 228))(v1, 27, 0);
    if ( dword_4D7EB0 )
    {
      if ( (dword_4DBDF0 & 2) == 0 )
      {
        dword_4DBDF0 |= 2u;
        v15 = 2;
        sub_4033D0(L"specularLeaf", (int)v13);
        LOBYTE(v15) = 3;
        sub_408600(v13, (int)&unk_4DBDA8, (int)&flt_4D62B8);
        if ( v14 >= 8 )
          operator delete(v13[0]);
        v14 = 7;
        v13[4] = 0;
        LOWORD(v13[0]) = 0;
        atexit(sub_472080);
        v15 = -1;
      }
      *(float *)&v7 = flt_4D62B8;
      v8 = flt_4D62B8;
      v9 = flt_4D62B8;
      dword_4CA634 = LODWORD(flt_4D62B8);
      v10 = 1.0;
      dword_4CA638 = LODWORD(flt_4D62B8);
      dword_4CA63C = LODWORD(flt_4D62B8);
      *(float *)&dword_4CA640 = 1.0;
      v3 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v4 = v3[1];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v4 + 212))(v4, 1, 1);
      sub_44F2A0(
        flt_4D53B4,
        (int)&unk_4D8BA8,
        dword_4D80C8,
        dword_4D7EA8,
        dword_4D7EB0,
        dword_4D7EAC,
        dword_4D7EB8,
        dword_4D7EBC);
      v5 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v6 = v5[1];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      return (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v6 + 212))(v6, 1, 0);
    }
  }
  return result;
}
