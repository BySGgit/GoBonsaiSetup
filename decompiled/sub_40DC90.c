void sub_40DC90()
{
  int v0; // edi
  _DWORD *i; // ebp
  _DWORD *v2; // esi
  int v3; // ecx
  bool v4; // zf
  int v5; // eax
  float v6; // [esp+14h] [ebp-30h]
  float v7; // [esp+14h] [ebp-30h]
  float v8; // [esp+14h] [ebp-30h]
  float v9; // [esp+14h] [ebp-30h]
  float v10; // [esp+14h] [ebp-30h]
  void *v11[4]; // [esp+18h] [ebp-2Ch] BYREF
  int v12; // [esp+28h] [ebp-1Ch]
  unsigned int v13; // [esp+2Ch] [ebp-18h]
  int v14; // [esp+40h] [ebp-4h]

  v0 = dword_4D7EE8;
  if ( (dword_4DBDA4 & 1) == 0 )
  {
    dword_4DBDA4 |= 1u;
    v14 = 0;
    LOWORD(v11[0]) = 0;
    v13 = 7;
    v12 = 0;
    sub_4032D0(L"updateGrowth", (int)v11, 0xCu);
    LOBYTE(v14) = 1;
    sub_4038B0(v11, (int)&unk_4DBD80, (int)&byte_4D62DC);
    if ( v13 >= 8 )
      operator delete(v11[0]);
    atexit(sub_472110);
    v14 = -1;
  }
  if ( byte_4D62DC )
  {
    if ( (dword_4DBDA4 & 2) == 0 )
    {
      dword_4DBDA4 |= 2u;
      v14 = 2;
      v13 = 7;
      v12 = 0;
      LOWORD(v11[0]) = 0;
      sub_4032D0(L"randomAutoCuts", (int)v11, 0xEu);
      LOBYTE(v14) = 3;
      sub_4038B0(v11, (int)&unk_4DBD5C, (int)&byte_4D8CED);
      if ( v13 >= 8 )
        operator delete(v11[0]);
      atexit(sub_472100);
      v14 = -1;
    }
    if ( byte_4D8CED )
    {
      if ( (double)rand() / 32767.0 < 0.009999999776482582 )
      {
        for ( i = *(_DWORD **)dword_4D8C10; i != (_DWORD *)dword_4D8C10; i = (_DWORD *)*i )
        {
          v2 = (_DWORD *)i[3];
          if ( v2 )
          {
            if ( (dword_4D7CF8 & 1) == 0 )
            {
              dword_4D7CF8 |= 1u;
              v14 = 4;
              sub_4079C0();
              v14 = -1;
            }
            if ( byte_4D8225[11 * v2[1]] && v2[45] && (double)rand() / 32767.0 < 0.009999999776482582 )
              (*(void (__thiscall **)(_DWORD *))(*v2 + 44))(v2);
          }
        }
      }
    }
    v6 = *(float *)(v0 + 216) + 1.0;
    *(float *)(v0 + 216) = v6;
    if ( (int)(v6 / 365.0) - (int)((v6 - 1.0) / 365.0) >= 1 )
    {
      sub_408A30(*(_DWORD *)(v0 + 236));
      v3 = *(_DWORD *)(v0 + 240);
      v7 = *(float *)(v0 + 196) * 0.8999999761581421;
      *(float *)(v0 + 196) = v7 * (1.0 - flt_4D7EF4);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 40))(v3);
      *(float *)(*(_DWORD *)(v0 + 240) + 428) = 1.0;
    }
    if ( (dword_4DBDA4 & 4) == 0 )
    {
      dword_4DBDA4 |= 4u;
      v14 = 5;
      v13 = 7;
      v12 = 0;
      LOWORD(v11[0]) = 0;
      sub_4032D0(L"energyUseRate", (int)v11, 0xDu);
      LOBYTE(v14) = 6;
      sub_408600(v11, (int)&unk_4DBD38, (int)&flt_4D62E0);
      if ( v13 >= 8 )
        operator delete(v11[0]);
      atexit(sub_4720F0);
      v14 = -1;
    }
    v8 = sub_40EE60(v0);
    v9 = *(float *)(v0 + 196) * flt_4D62E0 * v8;
    *(float *)(*(_DWORD *)(v0 + 240) + 432) = v9;
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v0 + 240) + 36))(*(_DWORD *)(v0 + 240));
    v4 = (dword_4DBDA4 & 8) == 0;
    v5 = *(_DWORD *)(v0 + 240);
    v10 = *(float *)(v0 + 196) - *(float *)(v5 + 436);
    *(float *)(v0 + 196) = v10;
    *(float *)(v0 + 196) = v10 + *(float *)(v5 + 420);
    if ( v4 )
    {
      dword_4DBDA4 |= 8u;
      v14 = 7;
      LOWORD(v11[0]) = 0;
      v13 = 7;
      v12 = 0;
      sub_4032D0(L"energyLeak", (int)v11, 0xAu);
      LOBYTE(v14) = 8;
      sub_408600(v11, (int)&unk_4DBD14, (int)&flt_4D62E4);
      if ( v13 >= 8 )
        operator delete(v11[0]);
      atexit(sub_4720E0);
    }
    *(float *)(v0 + 196) = *(float *)(v0 + 196) * flt_4D62E4;
  }
}
