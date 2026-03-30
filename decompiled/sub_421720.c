int __usercall sub_421720@<eax>(int *a1@<esi>, int a2)
{
  _DWORD *EngineInstance; // edi
  int v3; // edi
  int result; // eax
  int v5; // eax
  void (__stdcall *v6)(int *, int, _DWORD *); // edx
  int v7; // edi
  int v8; // edx
  unsigned int v9; // eax
  int v10; // ecx
  int (__stdcall *v11)(int *, _DWORD *, _DWORD, int *); // edx
  void *v12; // eax
  int v13; // eax
  int (__stdcall *v14)(int *, int, _DWORD *, int *); // edx
  void *v15; // eax
  void *v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // [esp+40h] [ebp-ACh]
  int v20; // [esp+40h] [ebp-ACh]
  int v21; // [esp+50h] [ebp-9Ch] BYREF
  int v22; // [esp+54h] [ebp-98h] BYREF
  int v23; // [esp+58h] [ebp-94h] BYREF
  int v24; // [esp+5Ch] [ebp-90h] BYREF
  _DWORD *v25; // [esp+60h] [ebp-8Ch]
  _DWORD v26[5]; // [esp+64h] [ebp-88h] BYREF
  _DWORD v27[4]; // [esp+78h] [ebp-74h] BYREF
  int v28; // [esp+88h] [ebp-64h]
  unsigned int v29; // [esp+8Ch] [ebp-60h]
  int v30; // [esp+90h] [ebp-5Ch]
  int v31; // [esp+94h] [ebp-58h]
  int v32; // [esp+98h] [ebp-54h]
  float v33; // [esp+9Ch] [ebp-50h]
  float v34; // [esp+A0h] [ebp-4Ch]
  _DWORD v35[6]; // [esp+A4h] [ebp-48h] BYREF
  int v36; // [esp+BCh] [ebp-30h] BYREF
  int v37; // [esp+C0h] [ebp-2Ch]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = EngineInstance[94];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v23 = 0;
  v24 = 0;
  result = (*(int (__stdcall **)(int, _DWORD, void *, int *))(*(_DWORD *)v3 + 36))(v3, 0, &unk_4B8D1C, &v22);
  if ( result >= 0 )
  {
    (*(void (__stdcall **)(int, int *))(*(_DWORD *)v22 + 48))(v22, &v36);
    *(float *)&v35[4] = 0.0;
    v5 = *a1;
    *(float *)&v35[5] = 1.0;
    v35[2] = v36;
    v35[3] = v37;
    v6 = *(void (__stdcall **)(int *, int, _DWORD *))(v5 + 120);
    v35[0] = 0;
    v35[1] = 0;
    v6(a1, 1, v35);
    v7 = (*(int (__stdcall **)(int *, int, _DWORD, int *))(*a1 + 304))(a1, v22, 0, &v24);
    if ( v22 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v22 + 8))(v22);
      v22 = 0;
    }
    if ( v7 >= 0 )
    {
      v21 = v24;
      v25 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v25[97] = v21;
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( *(_BYTE *)(a2 + 88) )
      {
        v8 = *(_DWORD *)(a2 + 92);
        v27[0] = v36;
        v9 = *(_DWORD *)(a2 + 44);
        v27[1] = v37;
        v10 = *(_DWORD *)(a2 + 48);
        v29 = v9;
        v30 = v10;
        v28 = v8;
        v11 = *(int (__stdcall **)(int *, _DWORD *, _DWORD, int *))(*a1 + 292);
        v21 = 0;
        v27[2] = 1;
        v27[3] = 1;
        v31 = 0;
        v32 = 64;
        v33 = 0.0;
        v34 = 0.0;
        result = v11(a1, v27, 0, &v21);
        if ( result < 0 )
          return result;
        v19 = v21;
        v12 = GetEngineInstance();
        sub_4196D0((int)v12, v19);
        v13 = *a1;
        v26[0] = v28;
        v26[1] = v29 > 1 ? 5 : 3;
        v14 = *(int (__stdcall **)(int *, int, _DWORD *, int *))(v13 + 308);
        v26[2] = 0;
        v7 = v14(a1, v21, v26, &v23);
        if ( v7 < 0 )
          return v7;
        v20 = v23;
        v15 = GetEngineInstance();
        sub_419710((int)v15, v20);
      }
      v16 = GetEngineInstance();
      v17 = sub_419750((int)v16);
      v18 = *a1;
      v23 = v17;
      (*(void (__stdcall **)(int *, int, int *, int))(v18 + 96))(a1, 1, &v24, v17);
    }
    return v7;
  }
  return result;
}
