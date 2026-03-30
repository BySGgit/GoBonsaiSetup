int __thiscall sub_40EA30(_DWORD **this)
{
  _DWORD *EngineInstance; // esi
  int v2; // edi
  _DWORD *v3; // esi
  int v4; // esi
  unsigned int v5; // ebx
  _DWORD *v6; // esi
  int v7; // esi
  _DWORD *v8; // esi
  int v9; // esi
  _DWORD *v10; // esi
  int v11; // esi
  _DWORD *v12; // esi
  int v13; // esi
  void *v16[4]; // [esp+A8h] [ebp-4Ch] BYREF
  int v17; // [esp+B8h] [ebp-3Ch]
  unsigned int v18; // [esp+BCh] [ebp-38h]
  void *v19[5]; // [esp+C4h] [ebp-30h] BYREF
  unsigned int v20; // [esp+D8h] [ebp-1Ch]
  int v21; // [esp+F0h] [ebp-4h]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = EngineInstance[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 143, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 137, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 19, 5);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 20, 6);
  if ( (dword_4DBE98 & 1) == 0 )
  {
    dword_4DBE98 |= 1u;
    v21 = 0;
    v19[4] = 0;
    v20 = 7;
    LOWORD(v19[0]) = 0;
    sub_4032D0(L"lightDirectStrength", (int)v19, 0x13u);
    LOBYTE(v21) = 1;
    sub_408600(v19, (int)&unk_4DBE74, (int)&unk_4D62F0);
    if ( v20 >= 8 )
      operator delete(v19[0]);
    atexit(sub_4721B0);
    v21 = -1;
  }
  if ( (dword_4DBE98 & 2) == 0 )
  {
    dword_4DBE98 |= 2u;
    v21 = 2;
    v18 = 7;
    v17 = 0;
    LOWORD(v16[0]) = 0;
    sub_4032D0(L"lightAmbientStrength", (int)v16, 0x14u);
    LOBYTE(v21) = 3;
    sub_408600(v16, (int)&unk_4DBE50, (int)&flt_4D8CF4);
    if ( v18 >= 8 )
      operator delete(v16[0]);
    v18 = 7;
    v17 = 0;
    LOWORD(v16[0]) = 0;
    atexit(sub_4721A0);
    v21 = -1;
  }
  if ( (dword_4DBE98 & 4) == 0 )
  {
    dword_4DBE98 |= 4u;
    flt_4DBE44 = 1.0;
    flt_4DBE48 = -1.0;
    flt_4DBE4C = flt_4D63B0;
    atexit(nullsub_2);
  }
  D3DXVec3Normalize(&flt_4DBE44, &flt_4DBE44);
  v3 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = v3[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v4 )
    sub_40D230((int)&flt_4DBE44);
  v5 = (unsigned __int8)(__int64)(flt_4D8CF4 * 255.0)
     | (((unsigned __int8)(__int64)(flt_4D8CF4 * 255.0)
       | (((unsigned __int8)(__int64)(flt_4D8CF4 * 255.0) | 0xFFFFFF00) << 8)) << 8);
  v6 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = v6[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, int, unsigned int))(*(_DWORD *)v7 + 228))(v7, 139, v5);
  (*(void (__thiscall **)(_DWORD))(**(this + 59) + 20))(*(this + 59));
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 7, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 14, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 22, 1);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v2 + 228))(v2, 27, 1);
  if ( (unsigned int)dword_4D8644 < 2 )
    return sub_40A8B0();
  v8 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v9 = v8[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v9 + 228))(v9, 139, -1);
  v10 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v11 = v10[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)v11 + 212))(v11, 0, 0);
  v12 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v13 = v12[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v13 + 212))(v13, 1, 0);
  return (*(int (__thiscall **)(_DWORD))(**(this + 60) + 20))(*(this + 60));
}
