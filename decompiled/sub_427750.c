void sub_427750()
{
  _BYTE *EngineInstance; // esi
  char v1; // bl
  double *v2; // esi
  _DWORD *v3; // esi
  int v4; // esi
  double *v5; // edi
  unsigned int v6; // esi
  _DWORD *v7; // edi
  bool v8; // zf
  float *v9; // esi
  double *v10; // esi
  _DWORD *v11; // esi
  char *v12; // esi
  wchar_t *v13; // esi
  double v14; // [esp+18h] [ebp-14h]
  float v15; // [esp+18h] [ebp-14h]
  double v16; // [esp+20h] [ebp-Ch]

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[755];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v1 )
  {
    v2 = (double *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v14 = v2[85];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v3 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v4 = v3[172];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v5 = (double *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v16 = v5[83];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v6 = v4 + 1;
    v7 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v8 = byte_4CA649 == 0;
    v7[172] = v6;
    if ( !v8 )
      LeaveCriticalSection(&CriticalSection);
    if ( v16 - v14 > 1.0 )
    {
      v15 = (double)v6 / (v16 - v14);
      v9 = (float *)GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v8 = byte_4CA649 == 0;
      v9[173] = v15;
      if ( !v8 )
        LeaveCriticalSection(&CriticalSection);
      v10 = (double *)GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v8 = byte_4CA649 == 0;
      v10[85] = v16;
      if ( !v8 )
        LeaveCriticalSection(&CriticalSection);
      v11 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v8 = byte_4CA649 == 0;
      v11[172] = 0;
      if ( !v8 )
        LeaveCriticalSection(&CriticalSection);
      v12 = (char *)GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v13 = (wchar_t *)(v12 + 2044);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      sub_419310(v13, (wchar_t *)L"%0.2f fps ", v15);
    }
  }
}
