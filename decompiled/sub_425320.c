int __stdcall sub_425320(float a1, _DWORD *a2, int a3)
{
  int result; // eax
  _DWORD *EngineInstance; // esi
  int v5; // esi
  int v6; // ebp
  _DWORD *v7; // esi
  bool v8; // zf
  _DWORD *v9; // esi
  _DWORD *v10; // edi
  _DWORD *v11; // eax
  void *v12; // eax
  int v13; // eax
  int v14; // [esp-4h] [ebp-2Ch]
  int v15; // [esp+20h] [ebp-8h]

  if ( !sub_43ABB0 )
    return -2147024809;
  LOBYTE(v15) = 1;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5 = EngineInstance[200];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v6 = v5 + 1;
  v7 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v8 = byte_4CA649 == 0;
  v7[200] = v6;
  if ( !v8 )
    LeaveCriticalSection(&CriticalSection);
  v9 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v10 = (_DWORD *)v9[382];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v10 )
  {
    v11 = operator new(0xCu);
    if ( v11 )
    {
      *v11 = 0;
      v11[1] = 0;
      v11[2] = 0;
    }
    else
    {
      v11 = 0;
    }
    v10 = v11;
    if ( !v11 )
      return -2147024882;
    v14 = (int)v11;
    v12 = GetEngineInstance();
    sub_41B2A0((int)v12, v14);
  }
  result = sub_428310(v10[1] + 1, (int)v10);
  if ( result >= 0 )
  {
    v13 = *v10 + 24 * v10[1];
    *(_DWORD *)v13 = sub_43ABB0;
    *(_DWORD *)(v13 + 4) = a3;
    *(float *)(v13 + 8) = a1;
    *(float *)(v13 + 12) = a1;
    *(_DWORD *)(v13 + 16) = v15;
    *(_DWORD *)(v13 + 20) = v6;
    ++v10[1];
    if ( a2 )
      *a2 = v6;
    return 0;
  }
  return result;
}
