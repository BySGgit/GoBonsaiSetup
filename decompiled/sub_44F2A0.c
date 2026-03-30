int __usercall sub_44F2A0@<eax>(float *a1@<edi>, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *EngineInstance; // esi
  int v9; // esi
  double v10; // st7
  double v11; // st7
  float v13[17]; // [esp+24h] [ebp-48h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v9 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v9 + 176))(v9, 256, a2);
  (*(void (__stdcall **)(int, _DWORD, int))(*(_DWORD *)v9 + 260))(v9, 0, a3);
  v13[0] = *a1;
  v13[1] = a1[1];
  v10 = a1[2];
  LODWORD(v13[8]) = dword_4CA634;
  v13[2] = v10;
  v11 = a1[3];
  LODWORD(v13[10]) = dword_4CA63C;
  v13[3] = v11;
  LODWORD(v13[11]) = dword_4CA640;
  v13[4] = *a1;
  LODWORD(v13[9]) = dword_4CA638;
  v13[5] = a1[1];
  v13[6] = a1[2];
  v13[7] = 1.0;
  v13[12] = 0.0;
  v13[13] = 0.0;
  v13[14] = 0.0;
  v13[15] = 0.0;
  v13[16] = flt_4CA644;
  (*(void (__stdcall **)(int, float *))(*(_DWORD *)v9 + 196))(v9, v13);
  (*(void (__stdcall **)(int, _DWORD, int, _DWORD, int))(*(_DWORD *)v9 + 400))(v9, 0, a4, 0, a7);
  (*(void (__stdcall **)(int, int))(*(_DWORD *)v9 + 356))(v9, a8);
  return (*(int (__stdcall **)(int, int, _DWORD, int))(*(_DWORD *)v9 + 324))(v9, a6, 0, a5);
}
