int __fastcall sub_429BF0(int a1, _DWORD *a2, void *a3, _DWORD *a4)
{
  int v4; // ebx
  int *EngineInstance; // esi
  int v6; // ebp
  int *v7; // eax
  _DWORD *v8; // edi
  _DWORD *v9; // esi
  int v10; // ebp
  int v11; // ebx
  int v12; // esi
  _DWORD *v13; // edi
  int v15; // [esp+Ch] [ebp-90h]
  _DWORD *v16; // [esp+10h] [ebp-8Ch]
  int v17; // [esp+14h] [ebp-88h]
  float v19; // [esp+1Ch] [ebp-80h]
  int v21; // [esp+28h] [ebp-74h]
  _DWORD *v22; // [esp+30h] [ebp-6Ch]
  float v23; // [esp+34h] [ebp-68h]
  _BYTE v24[76]; // [esp+38h] [ebp-64h] BYREF
  _DWORD v25[4]; // [esp+84h] [ebp-18h] BYREF

  v19 = -1.0;
  v4 = 0;
  v16 = 0;
  sub_41F750();
  EngineInstance = (int *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = *EngineInstance;
  v21 = *EngineInstance;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v7 = (int *)sub_428650();
  v8 = v7 + 22;
  v22 = v7 + 22;
  v15 = 0;
  if ( v7[23] <= 0 )
    return -2147219198;
  do
  {
    v9 = *(_DWORD **)(*v8 + 4 * v4);
    (*(void (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)v6 + 32))(v6, *v9, v25);
    if ( (int)v9[408] > 0 )
    {
      v10 = v9[407];
      v17 = v9[408];
      do
      {
        if ( *(int *)(*(_DWORD *)v10 + 316) > 0 )
        {
          v11 = *(_DWORD *)(*(_DWORD *)v10 + 312);
          v12 = *(_DWORD *)(*(_DWORD *)v10 + 316);
          do
          {
            v13 = *(_DWORD **)v11;
            if ( !*(_DWORD *)(*(_DWORD *)v11 + 16) || v13[2] == v25[3] )
            {
              if ( sub_42A020(v13, a1, a2) )
              {
                v23 = sub_42A3E0(v13, a4, (int)v25);
                if ( v19 < (double)v23 )
                {
                  v19 = v23;
                  v16 = v13;
                }
              }
            }
            v11 += 4;
            --v12;
          }
          while ( v12 );
          v8 = v22;
        }
        v10 += 4;
        --v17;
      }
      while ( v17 );
      v6 = v21;
      v4 = v15;
    }
    v15 = ++v4;
  }
  while ( v4 < v8[1] );
  if ( !v16 )
    return -2147219198;
  sub_42A8D0(v24, v16, a2);
  qmemcpy(a3, v24, 0x48u);
  return 0;
}
