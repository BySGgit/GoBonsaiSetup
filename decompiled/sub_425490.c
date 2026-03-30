int __stdcall sub_425490(int a1)
{
  _DWORD *EngineInstance; // esi
  int v2; // esi
  int v4; // ecx
  int *v5; // eax
  int v6; // esi
  int v7; // edi
  int v8; // ebx
  int v9; // ebp
  int v10; // edx
  int *v11; // eax
  int v12; // [esp+10h] [ebp-20h]
  int *v13; // [esp+14h] [ebp-1Ch]
  int v14; // [esp+28h] [ebp-8h]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = EngineInstance[382];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v2 )
    return 1;
  v4 = 0;
  v12 = *(_DWORD *)(v2 + 4);
  if ( v12 <= 0 )
    return -2147024809;
  v5 = *(int **)v2;
  v13 = *(int **)v2;
  while ( 1 )
  {
    v6 = *v5;
    v7 = v5[1];
    v8 = v5[2];
    v9 = v5[3];
    v14 = v5[4];
    v10 = v5[5];
    if ( v10 == a1 )
      break;
    ++v4;
    v5 += 6;
    if ( v4 >= v12 )
      return -2147024809;
  }
  LOBYTE(v14) = 0;
  if ( v4 >= 0 && v4 < v12 )
  {
    v11 = &v13[6 * v4];
    *v11 = v6;
    v11[1] = v7;
    v11[2] = v8;
    v11[3] = v9;
    v11[4] = v14;
    v11[5] = v10;
  }
  return 0;
}
