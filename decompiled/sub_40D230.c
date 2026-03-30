int __usercall sub_40D230@<eax>(int a1@<eax>)
{
  int *v2; // eax
  int *v3; // eax
  float v4; // eax
  _DWORD *EngineInstance; // esi
  int v6; // esi
  _DWORD *v7; // esi
  int v8; // esi
  int *v9; // eax
  int v10; // eax
  _DWORD *v11; // esi
  int v12; // esi
  _DWORD *v13; // esi
  int v14; // esi
  int v16; // [esp+18h] [ebp-10h] BYREF
  int v17; // [esp+1Ch] [ebp-Ch]
  int v18; // [esp+20h] [ebp-8h]
  float v19; // [esp+24h] [ebp-4h]

  v2 = (int *)sub_408470((float *)&v16, (float *)a1);
  dword_4D5320 = *v2;
  dword_4D5324 = v2[1];
  dword_4D5328 = v2[2];
  v3 = (int *)sub_408590((float *)&dword_4D5320, (float *)&v16);
  dword_4D532C = *v3;
  dword_4D5330 = v3[1];
  dword_4D5334 = v3[2];
  sub_40CF00((float *)&dword_4D532C);
  memset(&dword_4D7D68, 0, 0x68u);
  dword_4D7D68 = 3;
  *(float *)&dword_4D7D6C = 1.0;
  *(float *)&dword_4D7D70 = 1.0;
  *(float *)&dword_4D7D74 = 1.0;
  v19 = 1.0;
  *(float *)&dword_4D7D78 = 1.0;
  *(float *)&v16 = 1.0;
  *(float *)&v17 = 1.0;
  *(float *)&dword_4D7D8C = 0.30000001;
  *(float *)&v18 = 1.0;
  *(float *)&dword_4D7D90 = 0.30000001;
  *(float *)&dword_4D7D94 = 0.30000001;
  *(float *)&dword_4D7D98 = 1.0;
  *(float *)&dword_4D7D7C = 1.0;
  *(float *)&dword_4D7D80 = 1.0;
  *(float *)&dword_4D7D84 = 1.0;
  *(float *)&dword_4D7D88 = 1.0;
  dword_4D7DA8 = *(_DWORD *)a1;
  dword_4D7DAC = *(_DWORD *)(a1 + 4);
  v4 = *(float *)(a1 + 8);
  *(float *)&v16 = *(float *)&dword_4D7DA8 * -1000.0;
  dword_4D7DB0 = LODWORD(v4);
  *(float *)&v17 = *(float *)&dword_4D7DAC * -1000.0;
  dword_4D7D9C = v16;
  *(float *)&v18 = -1000.0 * v4;
  dword_4D7DA0 = v17;
  flt_4D7DB4 = 10000.0;
  dword_4D7DA4 = v18;
  flt_4D7DC8 = flt_4CA5E8;
  flt_4D7DCC = flt_4CA5E8;
  flt_4D7DBC = 1.0;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, _DWORD, int *))(*(_DWORD *)v6 + 204))(v6, 0, &dword_4D7D68);
  v7 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v8 = v7[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, _DWORD, int))(*(_DWORD *)v8 + 212))(v8, 0, 1);
  memset(&dword_4D7D00, 0, 0x68u);
  *(float *)&dword_4D7D04 = 0.69999999;
  v19 = 1.0;
  *(float *)&dword_4D7D08 = 0.69999999;
  *(float *)&v16 = flt_4CA5E8;
  *(float *)&dword_4D7D0C = 0.69999999;
  *(float *)&v17 = flt_4CA5E8;
  *(float *)&v18 = flt_4CA5E8;
  *(float *)&dword_4D7D10 = 1.0;
  dword_4D7D24 = LODWORD(flt_4CA5E8);
  dword_4D7D28 = LODWORD(flt_4CA5E8);
  dword_4D7D00 = 3;
  dword_4D7D2C = LODWORD(flt_4CA5E8);
  *(float *)&dword_4D7D30 = 1.0;
  v9 = (int *)sub_408590((float *)a1, (float *)&v16);
  dword_4D7D40 = *v9;
  dword_4D7D44 = v9[1];
  v10 = v9[2];
  *(float *)&v16 = *(float *)&dword_4D7DA8 * -1000.0;
  dword_4D7D48 = v10;
  dword_4D7D34 = v16;
  *(float *)&v17 = *(float *)&dword_4D7DAC * -1000.0;
  dword_4D7D38 = v17;
  *(float *)&v18 = -1000.0 * *(float *)&dword_4D7DB0;
  dword_4D7D3C = v18;
  flt_4D7D4C = 10000.0;
  flt_4D7D60 = flt_4CA5E8;
  flt_4D7D64 = flt_4CA5E8;
  flt_4D7D54 = 1.0;
  v11 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v12 = v11[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, int, int *))(*(_DWORD *)v12 + 204))(v12, 1, &dword_4D7D00);
  v13 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v14 = v13[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v14 + 212))(v14, 1, 0);
}
