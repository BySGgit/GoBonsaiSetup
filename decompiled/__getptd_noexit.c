DWORD *_getptd_noexit()
{
  DWORD LastError; // eax
  DWORD v1; // edi
  int (__stdcall *v2)(int); // eax
  DWORD *v3; // esi
  int v4; // eax
  int (__stdcall *v5)(int, int); // eax
  DWORD CurrentThreadId; // eax
  int v8; // [esp-8h] [ebp-10h]
  int v9; // [esp-4h] [ebp-Ch]
  int v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = dword_4C93F0;
  v1 = LastError;
  v2 = (int (__stdcall *)(int))__set_flsgetvalue();
  v3 = (DWORD *)v2(v9);
  if ( !v3 )
  {
    v4 = _calloc_crt(1, 532);
    v3 = (DWORD *)v4;
    if ( v4 )
    {
      v10 = v4;
      v8 = dword_4C93F0;
      v5 = (int (__stdcall *)(int, int))DecodePointer(dword_4D72B0);
      if ( v5(v8, v10) )
      {
        _initptd((int)v3, 0);
        CurrentThreadId = GetCurrentThreadId();
        v3[1] = -1;
        *v3 = CurrentThreadId;
      }
      else
      {
        free(v3);
        v3 = 0;
      }
    }
  }
  SetLastError(v1);
  return v3;
}
