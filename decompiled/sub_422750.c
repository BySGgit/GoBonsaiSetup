void sub_422750()
{
  _DWORD *EngineInstance; // esi
  int v1; // esi
  _DWORD *v2; // esi
  int v3; // esi
  void *v4; // eax
  _BYTE *v5; // esi
  char v6; // bl
  void *v7; // eax
  double *v8; // esi
  bool v9; // zf
  double *v10; // esi
  float *v11; // esi
  _DWORD *v12; // esi
  void (__stdcall *v13)(_DWORD, _DWORD, _DWORD, _DWORD); // esi
  void *v14; // eax
  int v15; // eax
  _BYTE *v16; // esi
  char v17; // bl
  void *v18; // eax
  void (__stdcall *v19)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // esi
  void *v20; // eax
  void *v21; // eax
  int v22; // eax
  void *v23; // eax
  int v24; // edi
  void *v25; // eax
  _DWORD *v26; // esi
  int v27; // esi
  int v28; // eax
  int v29; // eax
  void *v30; // eax
  _DWORD *v31; // eax
  void *v32; // eax
  void *v33; // eax
  void *v34; // eax
  int v35; // esi
  void *v36; // eax
  void *v37; // eax
  void *v38; // eax
  char v39; // [esp+1Ch] [ebp-38h]
  float v40; // [esp+34h] [ebp-20h] BYREF
  int v41; // [esp+38h] [ebp-1Ch]
  int v42; // [esp+3Ch] [ebp-18h]
  double v43; // [esp+40h] [ebp-14h] BYREF
  double v44; // [esp+48h] [ebp-Ch] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[92];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v41 = v1;
  if ( !v1 )
    return;
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = v2[94];
  v42 = v3;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v3 )
    return;
  if ( sub_41B900() || !sub_41B980() || (v4 = GetEngineInstance(), sub_4197D0((int)v4)) )
    Sleep(0x32u);
  if ( (dword_4D8DF8 & 1) == 0 )
  {
    dword_4D8DF8 |= 1u;
    sub_4375D0();
  }
  sub_437680((int)&unk_4D8DD0, &v43, &v44, &v40);
  v5 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = v5[758];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v6 )
  {
    v7 = GetEngineInstance();
    v40 = sub_41A2A0((int)v7);
    v43 = sub_41B820() + v40;
  }
  v8 = (double *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v9 = byte_4CA649 == 0;
  v8[82] = v43;
  if ( !v9 )
    LeaveCriticalSection(&CriticalSection);
  v10 = (double *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v9 = byte_4CA649 == 0;
  v10[83] = v44;
  if ( !v9 )
    LeaveCriticalSection(&CriticalSection);
  v11 = (float *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v9 = byte_4CA649 == 0;
  v11[168] = v40;
  if ( !v9 )
    LeaveCriticalSection(&CriticalSection);
  sub_423D40();
  sub_427750();
  sub_425560();
  v12 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v13 = (void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v12[218];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v13 )
  {
    v14 = GetEngineInstance();
    v15 = sub_41B060((int)v14);
    v13(LODWORD(v43), HIDWORD(v43), LODWORD(v40), v15);
    v41 = sub_41B550();
    if ( !v41 )
      return;
  }
  v16 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v17 = v16[784];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v17 )
  {
    v18 = GetEngineInstance();
    v19 = (void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))sub_41AFE0((int)v18);
    if ( v19 )
    {
      v20 = GetEngineInstance();
      if ( !sub_4197D0((int)v20) )
      {
        v21 = GetEngineInstance();
        v22 = sub_41B260((int)v21);
        v19(v41, LODWORD(v43), HIDWORD(v43), LODWORD(v40), v22);
        if ( !sub_41B550() )
          return;
      }
    }
  }
  v23 = GetEngineInstance();
  if ( sub_4197D0((int)v23) )
  {
    v24 = 1;
  }
  else
  {
    v25 = GetEngineInstance();
    v24 = *(_DWORD *)(sub_419610((int)v25) + 84);
  }
  v26 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v27 = v26[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v28 = (*(int (__stdcall **)(int, _DWORD, int))(*(_DWORD *)v42 + 32))(v42, *(_DWORD *)(v27 + 80), v24);
  switch ( v28 )
  {
    case 142213121:
      v39 = 1;
LABEL_71:
      v33 = GetEngineInstance();
      sub_419790((int)v33, v39);
      break;
    case -2005270521:
      v29 = sub_4224F0();
      if ( v29 < 0 )
      {
        if ( v29 == -2147219192 || v29 == -2147219197 )
        {
          sub_4256B0(v29);
          sub_428190(0);
          return;
        }
        v30 = GetEngineInstance();
        v31 = (_DWORD *)sub_419610((int)v30);
        if ( sub_41E880(v31, 0, 0, 1, 0) < 0 )
          goto LABEL_74;
      }
      break;
    case -2005270523:
      if ( sub_426F10() < 0 )
      {
        sub_4256B0(-2147219190);
        sub_428190(0);
        return;
      }
      break;
    default:
      if ( v28 >= 0 )
      {
        v32 = GetEngineInstance();
        if ( sub_4197D0((int)v32) )
        {
          v39 = 0;
          goto LABEL_71;
        }
      }
      break;
  }
  v34 = GetEngineInstance();
  v35 = sub_419ED0((int)v34) + 1;
  v36 = GetEngineInstance();
  sub_419E90((int)v36, v35);
  sub_424190();
  sub_4245E0();
  v37 = GetEngineInstance();
  if ( sub_41ACE0((int)v37) )
  {
    v38 = GetEngineInstance();
    if ( v35 > sub_41ACE0((int)v38) )
LABEL_74:
      sub_428190(0);
  }
}
