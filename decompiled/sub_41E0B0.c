signed int __stdcall sub_41E0B0(int a1, int a2)
{
  _BYTE *EngineInstance; // esi
  signed int result; // eax
  _BYTE *v4; // esi
  _BYTE *v5; // esi
  _BYTE *v6; // esi
  void *v7; // esi
  HWND v8; // esi
  HMENU Menu; // eax
  _DWORD *v10; // esi
  int v11; // esi
  void *v12; // eax
  _DWORD *v13; // esi
  int v14; // esi
  void *v15; // eax
  _DWORD *v16; // esi
  int v17; // esi
  void *v18; // eax
  _BYTE *v19; // esi
  void *v20; // eax
  void *v21; // eax
  _BYTE *v22; // esi
  _BYTE *v23; // esi
  _BYTE *v24; // esi
  _BYTE *v25; // esi
  void *v26; // eax
  void *v27; // eax
  _DWORD *v28; // esi
  int v29; // esi
  void *v30; // eax
  _DWORD *v31; // esi
  int v32; // esi
  void *v33; // eax
  void *v34; // eax
  int v35; // eax
  int v36; // esi
  int v37; // eax
  char v38; // [esp+17h] [ebp-125h]
  char v39; // [esp+17h] [ebp-125h]
  char v40; // [esp+17h] [ebp-125h]
  char v41; // [esp+17h] [ebp-125h]
  char v42; // [esp+17h] [ebp-125h]
  char v43; // [esp+17h] [ebp-125h]
  char v44; // [esp+17h] [ebp-125h]
  char v45; // [esp+17h] [ebp-125h]
  int v46[24]; // [esp+18h] [ebp-124h] BYREF
  _DWORD v47[24]; // [esp+78h] [ebp-C4h] BYREF
  int Val[3]; // [esp+D8h] [ebp-64h] BYREF
  int v49; // [esp+E4h] [ebp-58h]
  int v50; // [esp+E8h] [ebp-54h]
  int v51; // [esp+ECh] [ebp-50h]
  int v52; // [esp+F0h] [ebp-4Ch]
  int v53; // [esp+F4h] [ebp-48h]
  int v54; // [esp+F8h] [ebp-44h]
  int v55; // [esp+FCh] [ebp-40h]
  int v56; // [esp+100h] [ebp-3Ch]
  int v57; // [esp+104h] [ebp-38h]
  int v58; // [esp+108h] [ebp-34h]
  int v59; // [esp+10Ch] [ebp-30h]
  int v60; // [esp+110h] [ebp-2Ch]
  int v61; // [esp+114h] [ebp-28h]
  int v62; // [esp+118h] [ebp-24h]
  struct tagRECT rc; // [esp+124h] [ebp-18h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v38 = EngineInstance[780];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v38 )
    return -2147467259;
  v4 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4[777] = 1;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v5 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v39 = v5[773];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v39 )
    goto LABEL_22;
  v6 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v40 = v6[776];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v40 )
    return -2147467259;
  result = sub_41CC30(L"Direct3D Window");
  if ( result >= 0 )
  {
LABEL_22:
    SetRect(&rc, 0, 0, 128, 128);
    v7 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v8 = (HWND)*((_DWORD *)v7 + 142);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    Menu = GetMenu(v8);
    AdjustWindowRect(&rc, 0xCF0000u, Menu != 0);
    dword_4D7EFC = rc.right - rc.left;
    dword_4D7F00 = rc.bottom - rc.top;
    memset(Val, 0, sizeof(Val));
    v49 = 0;
    v50 = 1;
    v51 = 0;
    v52 = 0;
    v53 = 2;
    v54 = 0;
    v55 = 0;
    v56 = 0;
    v57 = 0;
    v58 = 0;
    v59 = 0;
    v60 = 0;
    v61 = 0;
    v62 = 0;
    memset(v46, 0, sizeof(v46));
    v46[0] = 0;
    v46[13] = 1;
    v46[5] = a1;
    v46[6] = a2;
    v10 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v11 = v10[208];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v11 )
    {
      v12 = GetEngineInstance();
      v46[5] = sub_41A9E0((int)v12);
      v53 = 1;
    }
    v13 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v14 = v13[209];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v14 )
    {
      v15 = GetEngineInstance();
      v46[6] = sub_41AA60((int)v15);
      v53 = 1;
    }
    v16 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v17 = v16[202];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v17 != -1 )
    {
      v18 = GetEngineInstance();
      v46[1] = sub_41A860((int)v18);
      v49 = 1;
    }
    v19 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v41 = v19[820];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v41 )
    {
      v46[13] = 0;
      v20 = GetEngineInstance();
      if ( !sub_41A9E0((int)v20) )
      {
        v21 = GetEngineInstance();
        if ( !sub_41AA60((int)v21) )
          v53 = 0;
      }
    }
    v22 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v42 = v22[812];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v42 )
      v46[13] = 1;
    v23 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v43 = v23[840];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v43 )
    {
      v46[2] = 1;
      v49 = 1;
    }
    v24 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v44 = v24[841];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v44 )
    {
      v46[2] = 2;
      v49 = 1;
    }
    v25 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v45 = v25[842];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v45 )
    {
      v46[4] = 80;
    }
    else
    {
      v26 = GetEngineInstance();
      if ( sub_41AB60((int)v26) )
      {
        v46[4] = 64;
      }
      else
      {
        v27 = GetEngineInstance();
        if ( !sub_41ABE0((int)v27) )
          goto LABEL_81;
        v46[4] = 32;
      }
    }
    v52 = 1;
LABEL_81:
    v28 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v29 = v28[214];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v29 )
    {
      v30 = GetEngineInstance();
      if ( sub_41AD60((int)v30) != 1 )
      {
LABEL_90:
        v31 = GetEngineInstance();
        if ( byte_4CA649 )
          EnterCriticalSection(&CriticalSection);
        v32 = v31[201];
        if ( byte_4CA649 )
          LeaveCriticalSection(&CriticalSection);
        if ( v32 != -1 )
        {
          v33 = GetEngineInstance();
          if ( sub_41A820((int)v33) == 9 )
          {
            v46[0] = 0;
            Val[0] = 1;
          }
          else
          {
            v34 = GetEngineInstance();
            if ( sub_41A820((int)v34) == 10 )
            {
              v46[0] = 1;
              Val[0] = 1;
              memset(v47, 0, 0x5Cu);
              sub_4386C0(v47, &v46[1]);
              qmemcpy(&v46[1], v47, 0x5Cu);
            }
          }
        }
        v35 = sub_4283D0(Val, v46, v46);
        v36 = v35;
        if ( v35 >= 0 )
        {
          v37 = sub_41E880(v46, 0, 0, 0, 1);
          return v37 >= 0 ? 0 : v37;
        }
        else
        {
          sub_4256B0(v35);
          return v36;
        }
      }
      v46[18] = 0;
    }
    else
    {
      v46[18] = 0x80000000;
    }
    v62 = 1;
    goto LABEL_90;
  }
  return result;
}
