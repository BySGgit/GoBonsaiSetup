int __stdcall sub_428DD0(unsigned int a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // esi
  int v4; // eax
  _DWORD *EngineInstance; // edi
  int v6; // edi
  _DWORD *v7; // edi
  int v8; // edi
  int v10; // [esp+3Ch] [ebp-64h] BYREF
  unsigned int i; // [esp+40h] [ebp-60h]
  _DWORD *v12; // [esp+44h] [ebp-5Ch]
  _DWORD v13[14]; // [esp+48h] [ebp-58h] BYREF
  _BYTE v14[12]; // [esp+80h] [ebp-20h] BYREF
  int v15; // [esp+8Ch] [ebp-14h]
  _DWORD v16[3]; // [esp+90h] [ebp-10h]

  v12 = a3;
  v16[0] = 1;
  v16[1] = 3;
  v16[2] = 2;
  for ( i = 0; i < 3; ++i )
  {
    v3 = operator new(0x144u);
    if ( !v3 )
      return -2147024882;
    v4 = v16[i];
    v3[78] = 0;
    v3[79] = 0;
    v3[80] = 0;
    *v3 = *a2;
    v3[1] = v4;
    if ( (*(int (__stdcall **)(_DWORD, _DWORD, int, _DWORD *))(**(_DWORD **)(a1 + 4) + 56))(
           *(_DWORD *)(a1 + 4),
           *a2,
           v4,
           v3 + 2) < 0 )
    {
LABEL_20:
      sub_429780((int)v3);
      operator delete(v3);
      continue;
    }
    if ( v3[1] != 1 )
    {
      (*(void (__stdcall **)(_DWORD, _DWORD, _BYTE *))(**(_DWORD **)(a1 + 4) + 32))(*(_DWORD *)(a1 + 4), 0, v14);
      memset(v13, 0, sizeof(v13));
      v13[0] = 1;
      v13[1] = 1;
      v13[2] = v15;
      v13[3] = 1;
      v13[6] = 3;
      v13[8] = 1;
      EngineInstance = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v6 = EngineInstance[140];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v13[7] = v6;
      v10 = 0;
      v7 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v8 = v7[140];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD *, int *))(**(_DWORD **)(a1 + 4) + 64))(
             *(_DWORD *)(a1 + 4),
             *a2,
             v3[1],
             v8,
             66,
             v13,
             &v10) < 0 )
        goto LABEL_20;
      if ( v10 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v10 + 8))(v10);
        v10 = 0;
      }
    }
    if ( sub_429000(v3, a1, a2, v12) < 0 || (int)v3[79] <= 0 )
      goto LABEL_20;
    if ( sub_42DBC0(a2[408] + 1, (int)(a2 + 407)) >= 0 )
      *(_DWORD *)(a2[407] + 4 * a2[408]++) = v3;
  }
  return 0;
}
