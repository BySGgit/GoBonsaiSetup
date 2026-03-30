int __thiscall sub_409130(int this)
{
  _DWORD *EngineInstance; // esi
  int v3; // ebx
  int v4; // esi
  void *v6; // [esp+40h] [ebp-30h] BYREF
  float v7; // [esp+44h] [ebp-2Ch]
  float v8; // [esp+48h] [ebp-28h]
  float v9; // [esp+4Ch] [ebp-24h]
  int v10; // [esp+50h] [ebp-20h]
  unsigned int v11; // [esp+54h] [ebp-1Ch]
  int v12; // [esp+6Ch] [ebp-4h]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v3 + 228))(v3, 27, 0);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v3 + 228))(v3, 7, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v3 + 228))(v3, 14, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v3 + 228))(v3, 22, 3);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v3 + 228))(v3, 143, 1);
  v4 = this + 104;
  v6 = *(void **)(this + 268);
  v7 = *(float *)&v6;
  v8 = *(float *)&v6;
  dword_4CA634 = (int)v6;
  dword_4CA638 = (int)v6;
  v9 = 1.0;
  dword_4CA63C = (int)v6;
  *(float *)&dword_4CA640 = 1.0;
  sub_44F2A0(
    (float *)(this + 236),
    this + 104,
    dword_4D8150,
    dword_4D7E58,
    dword_4D7E60,
    dword_4D7E5C,
    dword_4D7E68,
    dword_4D7E6C);
  if ( (dword_4DBE18 & 1) == 0 )
  {
    dword_4DBE18 |= 1u;
    v12 = 0;
    v10 = 0;
    v11 = 7;
    LOWORD(v6) = 0;
    sub_4032D0(L"specularSoil", (int)&v6, 0xCu);
    LOBYTE(v12) = 1;
    sub_408600(&v6, (int)&unk_4DBDF4, (int)&flt_4D62B0);
    if ( v11 >= 8 )
      operator delete(v6);
    atexit(sub_472040);
    v4 = this + 104;
    v12 = -1;
  }
  dword_4CA634 = LODWORD(flt_4D62B0);
  v9 = 1.0;
  dword_4CA638 = LODWORD(flt_4D62B0);
  *(float *)&v6 = flt_4D63B0;
  v7 = flt_4D63B0;
  v8 = flt_4D63B0;
  dword_4CA63C = LODWORD(flt_4D62B0);
  *(float *)&dword_4CA640 = 1.0;
  sub_44F2A0((float *)&v6, v4, dword_4D8194, dword_4D7E70, dword_4D7E78, dword_4D7E74, dword_4D7E80, dword_4D7E84);
  return (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v3 + 228))(v3, 143, 0);
}
