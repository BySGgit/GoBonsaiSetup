int sub_425560()
{
  float *EngineInstance; // esi
  _DWORD *v1; // esi
  _DWORD *v2; // ebx
  int result; // eax
  int v4; // ecx
  void (__stdcall *v5)(int, int); // edx
  int v6; // esi
  float v7; // ebp
  int v8; // edi
  int v9; // [esp+10h] [ebp-24h]
  int v10; // [esp+14h] [ebp-20h]
  float v11; // [esp+18h] [ebp-1Ch]
  float v12; // [esp+28h] [ebp-Ch]
  int v13; // [esp+2Ch] [ebp-8h]

  EngineInstance = (float *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v11 = EngineInstance[168];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v1 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = (_DWORD *)v1[382];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  result = 0;
  if ( v2 )
  {
    v9 = 0;
    if ( (int)v2[1] > 0 )
    {
      v10 = 0;
      do
      {
        v4 = *v2 + v10;
        v5 = *(void (__stdcall **)(int, int))v4;
        v6 = *(_DWORD *)(v4 + 4);
        v7 = *(float *)(v4 + 8);
        v8 = *(_DWORD *)(v4 + 20);
        v13 = *(_DWORD *)(v4 + 16);
        if ( (_BYTE)v13 )
        {
          v12 = *(float *)(v4 + 12) - v11;
          if ( v12 < 0.0 )
          {
            v5(v8, v6);
            v4 = v10 + *v2;
            v7 = *(float *)(v4 + 8);
            v5 = *(void (__stdcall **)(int, int))v4;
            v6 = *(_DWORD *)(v4 + 4);
            v8 = *(_DWORD *)(v4 + 20);
            v12 = v7;
            v13 = *(_DWORD *)(v4 + 16);
          }
          if ( v9 >= 0 && v9 < v2[1] )
          {
            *(_DWORD *)v4 = v5;
            *(_DWORD *)(v4 + 4) = v6;
            *(float *)(v4 + 8) = v7;
            *(float *)(v4 + 12) = v12;
            *(_DWORD *)(v4 + 16) = v13;
            *(_DWORD *)(v4 + 20) = v8;
          }
        }
        v10 += 24;
        result = v9 + 1;
        v9 = result;
      }
      while ( result < v2[1] );
    }
  }
  return result;
}
