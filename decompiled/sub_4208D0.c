void sub_4208D0()
{
  _BYTE *EngineInstance; // esi
  char v1; // bl
  _DWORD *v2; // esi
  int v3; // esi
  _BYTE *v4; // esi
  char v5; // bl
  _DWORD *v6; // esi
  int v7; // edi
  int v8; // ebp
  _BYTE *v9; // esi
  char v10; // bl
  char v11; // bl
  _BYTE *v12; // esi
  char v13; // bl
  int v14; // eax
  int v15; // esi
  void *v16; // eax
  int v17; // edi
  int v18; // eax
  void *v19; // eax
  _DWORD *v20; // eax
  void *v21; // eax
  _BYTE *v22; // esi
  char v23; // bl
  float *v24; // esi
  double *v25; // esi
  bool v26; // zf
  double *v27; // esi
  float *v28; // esi
  _DWORD *v29; // esi
  void (__stdcall *v30)(_DWORD, _DWORD, _DWORD, int); // edi
  _DWORD *v31; // esi
  int v32; // esi
  _DWORD *v33; // esi
  int v34; // esi
  void *v35; // eax
  void *v36; // eax
  void (__stdcall *v37)(int, _DWORD, _DWORD, _DWORD, int); // esi
  void *v38; // eax
  int v39; // eax
  int v40; // eax
  void *v41; // eax
  _BYTE *v42; // esi
  char v43; // bl
  void *v44; // eax
  void *v45; // edi
  void *v46; // eax
  _DWORD *v47; // esi
  int v48; // esi
  int v49; // edi
  _DWORD *v50; // esi
  _DWORD *v51; // esi
  int v52; // esi
  void *v53; // eax
  float v54; // [esp+38h] [ebp-148h] BYREF
  double v55; // [esp+3Ch] [ebp-144h] BYREF
  int v56[24]; // [esp+44h] [ebp-13Ch] BYREF
  _BYTE v57[92]; // [esp+A4h] [ebp-DCh] BYREF
  double v58; // [esp+104h] [ebp-7Ch] BYREF
  int v59; // [esp+110h] [ebp-70h]
  int Val[25]; // [esp+114h] [ebp-6Ch] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v1 = EngineInstance[796];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v1 )
    goto LABEL_16;
  v2 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v3 = v2[197];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v3 > 0 )
    goto LABEL_16;
  v4 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v5 = v4[782];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v5 )
LABEL_16:
    Sleep(0x32u);
  v6 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = v6[1];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v8 = v7;
  v9 = GetEngineInstance();
  if ( !v7 )
  {
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v10 = v9[796];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v10 )
    {
      qmemcpy(v56, sub_427EC0(Val), sizeof(v56));
      sub_41E880(v56, 0, 0, 0, 1);
    }
    return;
  }
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v11 = v9[796];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v11 )
    goto LABEL_53;
  v12 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v13 = v12[784];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v13 )
  {
LABEL_53:
    if ( (dword_4D8DF8 & 1) == 0 )
    {
      dword_4D8DF8 |= 1u;
      sub_4375D0();
    }
    sub_437680((int)&unk_4D8DD0, &v55, &v58, &v54);
    v22 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v23 = v22[758];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v23 )
    {
      v24 = (float *)GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      *(float *)&v55 = v24[190];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v54 = *(float *)&v55;
      v55 = sub_41B820() + *(float *)&v55;
    }
    v25 = (double *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v26 = byte_4CA649 == 0;
    v25[82] = v55;
    if ( !v26 )
      LeaveCriticalSection(&CriticalSection);
    v27 = (double *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v26 = byte_4CA649 == 0;
    v27[83] = v58;
    if ( !v26 )
      LeaveCriticalSection(&CriticalSection);
    v28 = (float *)GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v26 = byte_4CA649 == 0;
    v28[168] = v54;
    if ( !v26 )
      LeaveCriticalSection(&CriticalSection);
    sub_427750();
    sub_425560();
    v29 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v30 = (void (__stdcall *)(_DWORD, _DWORD, _DWORD, int))v29[218];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v30 )
    {
      v31 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v32 = v31[236];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v30(LODWORD(v55), HIDWORD(v55), LODWORD(v54), v32);
      v33 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v34 = v33[1];
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v8 = v34;
      if ( !v34 )
        return;
    }
    if ( byte_4D7E8F )
    {
      byte_4D7E8F = 0;
    }
    else
    {
      v35 = GetEngineInstance();
      if ( !sub_41A6A0((int)v35) )
      {
        v36 = GetEngineInstance();
        v37 = (void (__stdcall *)(int, _DWORD, _DWORD, _DWORD, int))sub_41AEE0((int)v36);
        if ( v37 )
        {
          v38 = GetEngineInstance();
          v39 = sub_41B160((int)v38);
          v37(v8, LODWORD(v55), HIDWORD(v55), LODWORD(v54), v39);
          v8 = sub_41B510();
          if ( !v8 )
            return;
        }
        v40 = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v8 + 68))(v8, 0, 0, 0, 0);
        if ( v40 < 0 && (v40 == -2005530520 || v40 == -2005530585) )
        {
          v41 = GetEngineInstance();
          sub_41A6E0((int)v41, 1);
        }
      }
    }
    v42 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v43 = v42[861];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v43 )
    {
      v44 = GetEngineInstance();
      v45 = (void *)sub_41B320((int)v44);
      v46 = GetEngineInstance();
      qmemcpy(v45, (const void *)sub_41B2E0((int)v46), 0x100u);
    }
    v47 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v48 = v47[174];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v49 = v48 + 1;
    v50 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v26 = byte_4CA649 == 0;
    v50[174] = v49;
    if ( !v26 )
      LeaveCriticalSection(&CriticalSection);
    v51 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v52 = v51[213];
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( !v52 )
      return;
    v53 = GetEngineInstance();
    if ( v49 <= sub_41ACE0((int)v53) )
      return;
    goto LABEL_121;
  }
  v14 = (*(int (__stdcall **)(int))(*(_DWORD *)v7 + 12))(v7);
  if ( v14 >= 0 )
  {
LABEL_52:
    v21 = GetEngineInstance();
    sub_41A6E0((int)v21, 0);
    goto LABEL_53;
  }
  if ( v14 == -2005530520 )
    return;
  if ( !sub_41B9C0()
    || (v15 = sub_41BA20(),
        v16 = GetEngineInstance(),
        v17 = sub_419610((int)v16),
        (*(void (__stdcall **)(int, _DWORD, double *))(*(_DWORD *)v15 + 32))(v15, *(_DWORD *)(v17 + 4), &v58),
        *(_DWORD *)(v17 + 12) == v59) )
  {
    v18 = sub_4204F0();
    if ( v18 < 0 )
    {
      if ( v18 == -2005530520 )
        return;
      if ( v18 == -2147219192 || v18 == -2147219197 )
      {
        sub_4256B0(v18);
        goto LABEL_121;
      }
      v19 = GetEngineInstance();
      v20 = (_DWORD *)sub_419610((int)v19);
      if ( sub_41E880(v20, 0, 0, 1, 0) < 0 )
      {
LABEL_121:
        sub_428190(0);
        return;
      }
    }
    goto LABEL_52;
  }
  Val[0] = 1;
  Val[1] = 1;
  Val[3] = 1;
  Val[4] = 1;
  Val[5] = 1;
  Val[6] = 2;
  Val[7] = 2;
  Val[8] = 2;
  Val[9] = 2;
  Val[10] = 2;
  Val[11] = 2;
  Val[12] = 2;
  Val[13] = 2;
  Val[14] = 2;
  Val[15] = 2;
  Val[16] = 2;
  qmemcpy(v56, sub_427EC0(v57), sizeof(v56));
  v56[3] = v59;
  if ( sub_4283D0(Val, v56, v56) < 0 )
  {
    sub_4256B0(-2147219198);
    sub_428190(0);
  }
  if ( sub_41E880(v56, 0, 0, 0, 0) < 0 && sub_425B80() < 0 )
    goto LABEL_121;
}
