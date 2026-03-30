int sub_427060()
{
  _DWORD *EngineInstance; // esi
  _DWORD *v1; // esi
  _DWORD *v2; // esi
  int v3; // esi
  int v4; // edi
  char *v5; // esi
  _DWORD *v6; // esi
  int result; // eax
  _DWORD *v8; // esi
  int v9; // esi
  int v10; // edi
  _DWORD *v11; // esi
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // [esp+18h] [ebp-34h] BYREF
  _DWORD v17[11]; // [esp+1Ch] [ebp-30h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = (_DWORD *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 || *v1 )
  {
    v8 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v9 = v8[94];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v10 = (*(int (__stdcall **)(int, _DWORD, void *, int *))(*(_DWORD *)v9 + 36))(v9, 0, &unk_4B8D1C, &v16);
    v11 = GetEngineInstance();
    if ( byte_4CA649 )
    {
      EnterCriticalSection(&CriticalSection);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
    }
    result = 0;
    v11[98] = 0;
    v11[99] = 0;
    v11[100] = 0;
    v11[101] = 0;
    v11[102] = 0;
    if ( v10 >= 0 )
    {
      (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)v16 + 48))(v16, v17);
      v12 = v17[1];
      v13 = v17[4];
      v11[98] = v17[0];
      v14 = v17[5];
      v11[99] = v12;
      v15 = v17[6];
      v11[100] = v13;
      v11[101] = v14;
      v11[102] = v15;
LABEL_26:
      result = v16;
      if ( v16 )
        return (*(int (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
    }
  }
  else
  {
    v2 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v3 = v2[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v4 = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, int *))(*(_DWORD *)v3 + 72))(v3, 0, 0, 0, &v16);
    v5 = (char *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v6 = v5 + 12;
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    result = 0;
    *v6 = 0;
    v6[1] = 0;
    v6[2] = 0;
    v6[3] = 0;
    v6[4] = 0;
    v6[5] = 0;
    v6[6] = 0;
    v6[7] = 0;
    if ( v4 >= 0 )
    {
      (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)v16 + 48))(v16, v6);
      goto LABEL_26;
    }
  }
  return result;
}
