void __stdcall sub_412120(_DWORD *a1)
{
  _DWORD *v1; // esi
  void *v2; // eax
  int v3; // ebx
  int v4; // edi
  _DWORD *v5; // eax
  int v6; // ecx
  void *v7; // eax
  int v8; // ebx
  int v9; // edi
  _DWORD *v10; // eax
  int v11; // ecx
  void *v12; // eax
  int v13; // ebx
  int v14; // edi
  _DWORD *v15; // eax
  int v16; // ecx
  bool v17; // zf
  _DWORD *EngineInstance; // esi
  int v19; // esi
  int v20; // [esp+8h] [ebp-38h]
  int v21; // [esp+8h] [ebp-38h]
  int v22; // [esp+8h] [ebp-38h]
  int v23; // [esp+24h] [ebp-1Ch] BYREF
  float v24[3]; // [esp+28h] [ebp-18h] BYREF
  int v25; // [esp+3Ch] [ebp-4h]

  a1[64] = dword_4D7F94 - (int)(0.0 * 1000.0);
  v1 = a1 + 8;
  dword_4D7EE4 = (int)(a1 + 8);
  v2 = operator new(0xA40u);
  v23 = (int)v2;
  v3 = 0;
  v25 = 0;
  if ( v2 )
    v3 = sub_4100E0((int)v2);
  v25 = -1;
  v4 = a1[50];
  v20 = *(_DWORD *)(v4 + 4);
  dword_4D7EF0 = v3;
  v23 = v3;
  v5 = sub_40FD70((char *)v4, v20, &v23);
  v6 = a1[51];
  if ( v6 == 1073741822 )
    std::_Xlength_error("list<T> too long");
  a1[51] = v6 + 1;
  *(_DWORD *)(v4 + 4) = v5;
  *(_DWORD *)v5[1] = v5;
  *(_DWORD *)(v3 + 180) = v1;
  v7 = operator new(0x100u);
  v23 = (int)v7;
  v25 = 1;
  if ( v7 )
    v8 = sub_40D6F0((int)v7);
  else
    v8 = 0;
  v25 = -1;
  v9 = a1[50];
  v21 = *(_DWORD *)(v9 + 4);
  dword_4D7EE8 = v8;
  v23 = v8;
  v10 = sub_40FD70((char *)v9, v21, &v23);
  v11 = a1[51];
  if ( v11 == 1073741822 )
    std::_Xlength_error("list<T> too long");
  a1[51] = v11 + 1;
  *(_DWORD *)(v9 + 4) = v10;
  *(_DWORD *)v10[1] = v10;
  *(_DWORD *)(v8 + 180) = v1;
  v12 = operator new(0x1C0u);
  v23 = (int)v12;
  v25 = 2;
  if ( v12 )
    v13 = sub_401E70((int)v12, 0.78539819, 1.0, 1.0, 10000.0);
  else
    v13 = 0;
  v25 = -1;
  v14 = a1[50];
  v22 = *(_DWORD *)(v14 + 4);
  dword_4D7EEC = v13;
  v23 = v13;
  v15 = sub_40FD70((char *)v14, v22, &v23);
  v16 = a1[51];
  if ( v16 == 1073741822 )
    std::_Xlength_error("list<T> too long");
  v17 = (dword_4D8EB8 & 1) == 0;
  v24[0] = 0.0;
  a1[51] = v16 + 1;
  *(_DWORD *)(v14 + 4) = v15;
  v24[1] = -1.0;
  *(_DWORD *)v15[1] = v15;
  v24[2] = 0.0;
  *(_DWORD *)(v13 + 180) = v1;
  if ( v17 )
  {
    dword_4D8EB8 |= 1u;
    flt_4D8EA8 = 1.0;
    flt_4D8EAC = 1.0;
    flt_4D8EB0 = 1.0;
    flt_4D8EB4 = 1.0;
  }
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v19 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v19 )
    sub_40D230((int)v24);
  sub_40D1A0((int)&dword_4D82D4);
  sub_4123C0((int)a1);
}
