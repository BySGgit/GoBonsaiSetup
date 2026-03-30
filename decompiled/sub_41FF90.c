int __usercall sub_41FF90@<eax>(int a1@<eax>)
{
  _DWORD *EngineInstance; // esi
  _DWORD *v3; // ebp
  int *v4; // esi
  int v5; // edi
  _DWORD *v6; // esi
  int v7; // esi
  int v8; // eax
  _BYTE *v9; // esi
  bool v10; // zf
  int v12; // esi
  _DWORD *v13; // edi
  _DWORD *v14; // esi
  int v15; // esi
  _DWORD *v16; // esi
  _DWORD *v17; // esi
  int v18; // esi
  void *v19; // eax
  char *v20; // esi
  char *v21; // edi
  _DWORD *v22; // esi
  int v23; // esi
  _DWORD *v24; // eax
  int v25; // edx
  int v26; // ecx
  _DWORD *v27; // eax
  _DWORD *v28; // esi
  char *v29; // esi
  char *v30; // ebx
  _BYTE *v31; // esi
  _DWORD *v32; // esi
  int (__stdcall *v33)(int, char *, int); // ebp
  int v34; // edi
  _DWORD *v35; // esi
  int v36; // edi
  _DWORD *v37; // esi
  int v38; // esi
  _BYTE *v39; // esi
  _DWORD *v40; // esi
  int v41; // esi
  _BYTE *v42; // esi
  _BYTE *v43; // esi
  void *v44; // eax
  int (__stdcall *v45)(int, char *, int); // esi
  int v46; // edi
  void *v47; // eax
  int v48; // eax
  _BYTE *v49; // esi
  void *v50; // eax
  int v51; // [esp-4h] [ebp-18h]
  int v52; // [esp+10h] [ebp-4h] BYREF

  v52 = 0;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = (_DWORD *)EngineInstance[2];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( a1 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)a1 + 4))(a1);
    v52 = a1;
  }
  else
  {
    sub_41F750();
    v4 = (int *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v5 = *v4;
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v6 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v7 = v6[140];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v8 = (*(int (__stdcall **)(int, _DWORD, _DWORD, int, _DWORD, _DWORD *, int *))(*(_DWORD *)v5 + 64))(
           v5,
           v3[1],
           v3[2],
           v7,
           v3[4],
           v3 + 5,
           &v52);
    if ( v8 == -2005530520 )
    {
      v9 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v10 = byte_4CA649 == 0;
      v9[796] = 1;
      if ( !v10 )
      {
        LeaveCriticalSection(&CriticalSection);
        return 0;
      }
      return 0;
    }
    if ( v8 < 0 )
      return -2147219195;
  }
  v12 = v52;
  v13 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v10 = byte_4CA649 == 0;
  v13[1] = v12;
  if ( !v10 )
    LeaveCriticalSection(&CriticalSection);
  if ( v3[2] != 2 )
    goto LABEL_36;
  v14 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v15 = v14[192];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v15 )
  {
LABEL_36:
    if ( v3[2] == 1 )
    {
      v17 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v18 = v17[192];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v18 == 10 )
      {
        v19 = GetEngineInstance();
        sub_41A360((int)v19, 0);
      }
    }
  }
  else
  {
    v16 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v10 = byte_4CA649 == 0;
    v16[192] = 10;
    if ( !v10 )
      LeaveCriticalSection(&CriticalSection);
  }
  sub_427060();
  sub_427250();
  v20 = (char *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v21 = v20 + 44;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v22 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v23 = v22[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, char *))(*(_DWORD *)v23 + 28))(v23, v21);
  v24 = sub_428650();
  v25 = v24[23];
  v26 = 0;
  if ( v25 <= 0 )
  {
LABEL_55:
    v28 = 0;
  }
  else
  {
    v27 = (_DWORD *)v24[22];
    while ( 1 )
    {
      v28 = (_DWORD *)*v27;
      if ( *(_DWORD *)*v27 == v3[1] )
        break;
      ++v26;
      ++v27;
      if ( v26 >= v25 )
        goto LABEL_55;
    }
  }
  sub_427980(v3[2], v3[4], (int)(v28 + 1));
  v29 = (char *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v30 = v29 + 12;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v31 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v10 = byte_4CA649 == 0;
  v31[780] = 1;
  if ( !v10 )
    LeaveCriticalSection(&CriticalSection);
  v32 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v33 = (int (__stdcall *)(int, char *, int))v32[223];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v34 = 0;
  if ( v33 )
  {
    v35 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v36 = v35[241];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v37 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v38 = v37[1];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v34 = v33(v38, v30, v36);
  }
  v39 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v10 = byte_4CA649 == 0;
  v39[780] = 0;
  if ( !v10 )
    LeaveCriticalSection(&CriticalSection);
  v40 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v41 = v40[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v41 )
    return -2147467259;
  if ( v34 < 0 )
    return 4 * (v34 != -2147219197) - 2147219197;
  v42 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v10 = byte_4CA649 == 0;
  v42[778] = 1;
  if ( !v10 )
    LeaveCriticalSection(&CriticalSection);
  v43 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v10 = byte_4CA649 == 0;
  v43[780] = 1;
  if ( !v10 )
    LeaveCriticalSection(&CriticalSection);
  v44 = GetEngineInstance();
  v45 = (int (__stdcall *)(int, char *, int))sub_41AE20((int)v44);
  v46 = 0;
  if ( v45 )
  {
    v47 = GetEngineInstance();
    v51 = sub_41B0A0((int)v47);
    v48 = sub_41B510();
    v46 = v45(v48, v30, v51);
  }
  v49 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v10 = byte_4CA649 == 0;
  v49[780] = 0;
  if ( !v10 )
    LeaveCriticalSection(&CriticalSection);
  if ( !sub_41B510() )
    return -2147467259;
  if ( v46 < 0 )
    return v46 != -2147219197 ? -2147219192 : -2147219197;
  v50 = GetEngineInstance();
  sub_41A5E0((int)v50, 1);
  return 0;
}
