void __thiscall sub_4361B0(int this, float a2)
{
  int *v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  bool v10; // zf
  int v11; // edi
  int v12; // esi
  int v13; // edi
  int v14; // edi
  int v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // esi
  int v19; // eax
  float v20; // ecx
  unsigned int v21; // eax
  LONG HighPart; // edx
  double v23; // st6
  int v24; // eax
  double LowPart; // st6
  LONG *v26; // ecx
  int v27; // esi
  int v28; // eax
  int v29; // eax
  int v30; // ecx
  int v31; // edx
  int v32; // esi
  int v33; // edi
  unsigned int v34; // eax
  int *v35; // edx
  double v36; // st6
  int v37; // eax
  LONG v38; // edx
  double v39; // st6
  int v40; // edx
  int v41; // eax
  int v42; // eax
  int v43; // edx
  LONG v44; // ecx
  int v45; // eax
  float v46; // ecx
  int v47; // ebx
  int v48; // [esp-4h] [ebp-6Ch]
  int v49; // [esp-4h] [ebp-6Ch]
  LARGE_INTEGER Frequency; // [esp+18h] [ebp-50h] BYREF
  int xLeft; // [esp+24h] [ebp-44h] BYREF
  LARGE_INTEGER PerformanceCount; // [esp+28h] [ebp-40h] BYREF
  float v53; // [esp+30h] [ebp-38h]
  float v54; // [esp+34h] [ebp-34h]
  int xRight; // [esp+3Ch] [ebp-2Ch] BYREF
  int v56; // [esp+40h] [ebp-28h] BYREF
  LONG v57[2]; // [esp+44h] [ebp-24h] BYREF
  int v58; // [esp+4Ch] [ebp-1Ch]
  int v59; // [esp+50h] [ebp-18h]
  struct tagRECT rc; // [esp+54h] [ebp-14h] BYREF

  if ( !*(_BYTE *)(this + 4) )
    return;
  v3 = *(int **)(this + 32);
  xRight = 0;
  xLeft = 0;
  v4 = *v3;
  if ( *v3 )
  {
    v5 = *(_DWORD *)(this + 24);
    v6 = *(_DWORD *)(v5 + 572);
    if ( v6 )
      v7 = *(_DWORD *)(*(_DWORD *)(v6 + 80) + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 596) + 4 * *(_DWORD *)(v4 + 4)));
    else
      v7 = 0;
    *(_DWORD *)(this + 88) = v7;
    sub_435650(*(_DWORD *)(this + 292), (_DWORD *)this);
  }
  Frequency.LowPart = 0;
  PerformanceCount.LowPart = this + 124;
  do
  {
    v8 = *(_DWORD *)(Frequency.LowPart + *(_DWORD *)(this + 32));
    sub_437110(0, (float *)(v8 + 28), a2, 0.69999999);
    v9 = *(_DWORD *)(this + 24);
    if ( *(_DWORD *)(*(_DWORD *)(v9 + 572) + 60) )
      sub_430950(v8, (LONG *)PerformanceCount.LowPart, *(_DWORD *)(this + 24));
    else
      sub_430C90((LONG *)PerformanceCount.LowPart, v9, v8, 0.80000001);
    PerformanceCount.LowPart += 16;
    Frequency.LowPart += 4;
  }
  while ( (int)Frequency.LowPart < 36 );
  v10 = *(_BYTE *)(this + 92) == 0;
  v11 = *(_DWORD *)(this + 304);
  v12 = this + 80;
  v56 = 0;
  if ( v10 || sub_436B30(v12) >= 0 )
    off_4D524C[0](*(_DWORD *)(this + 96), v11, 0, (int)&v56);
  v10 = *(_BYTE *)(this + 92) == 0;
  v13 = *(_DWORD *)(this + 292);
  xLeft = 0;
  if ( v10 || sub_436B30(v12) >= 0 )
    off_4D524C[0](*(_DWORD *)(this + 96), v13, 0, (int)&xLeft);
  v14 = *(_DWORD *)(this + 300);
  if ( *(_DWORD *)(this + 292) == v14 )
  {
    v15 = xLeft;
    v16 = xLeft;
    xRight = xLeft;
  }
  else
  {
    v10 = *(_BYTE *)(this + 92) == 0;
    xRight = 0;
    if ( v10 || sub_436B30(v12) >= 0 )
      off_4D524C[0](*(_DWORD *)(this + 96), v14, 0, (int)&xRight);
    v15 = xLeft;
    v16 = xRight;
  }
  if ( *(_DWORD *)(this + 292) != *(_DWORD *)(this + 300) )
  {
    v17 = v15;
    if ( v15 > v16 )
    {
      v17 = v16;
      v16 = v15;
    }
    SetRect(&rc, v17, *(_DWORD *)(this + 112), v16, *(_DWORD *)(this + 120));
    OffsetRect(&rc, *(_DWORD *)(this + 108) - v56, 0);
    IntersectRect(&rc, (const RECT *)(this + 108), &rc);
    v18 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 24) + 572) + 60);
    if ( v18 )
      (*(void (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v18 + 228))(v18, 7, 0);
    v19 = *(_DWORD *)(this + 24);
    v20 = *(float *)(this + 316);
    if ( *(_DWORD *)(*(_DWORD *)(v19 + 572) + 60) )
      sub_4302D0(v19, v20, &rc.left);
    else
      sub_4304F0(LODWORD(v20), (int)&rc, v19, &rc.left);
    if ( v18 )
      (*(void (__stdcall **)(int, int, int))(*(_DWORD *)v18 + 228))(v18, 7, 1);
  }
  v21 = *(_DWORD *)(this + 308);
  *(float *)&PerformanceCount.LowPart = (double)BYTE2(v21) * 0.003921568859368563;
  *(float *)&PerformanceCount.HighPart = (double)BYTE1(v21) * 0.003921568859368563;
  HighPart = PerformanceCount.HighPart;
  v23 = (double)(unsigned __int8)v21;
  Frequency.LowPart = HIBYTE(v21);
  v24 = **(_DWORD **)(this + 32);
  *(_DWORD *)(v24 + 92) = PerformanceCount.LowPart;
  *(_DWORD *)(v24 + 96) = HighPart;
  v53 = v23 * 0.003921568859368563;
  LowPart = (double)(int)Frequency.LowPart;
  *(float *)(v24 + 100) = v53;
  v26 = (LONG *)(this + 108);
  v54 = 0.003921568859368563 * LowPart;
  *(float *)(v24 + 104) = v54;
  v27 = **(_DWORD **)(this + 32);
  v28 = *(_DWORD *)(this + 24);
  v48 = *(_DWORD *)(this + 80) + 2 * *(_DWORD *)(this + 304);
  if ( *(_DWORD *)(*(_DWORD *)(v28 + 572) + 60) )
    sub_431020(v26, v28, v27, v48, 0, -1);
  else
    sub_431380(v26, v27, v28, v48, 0, -1);
  v29 = *(_DWORD *)(this + 292);
  v30 = *(_DWORD *)(this + 300);
  if ( v30 != v29 )
  {
    v31 = *(_DWORD *)(this + 300);
    if ( v30 >= v29 )
      v31 = *(_DWORD *)(this + 292);
    v32 = *(_DWORD *)(this + 304);
    if ( v32 <= v31 )
    {
      v32 = *(_DWORD *)(this + 300);
      if ( v30 < v29 )
      {
LABEL_45:
        v33 = v29 - v32;
        v34 = *(_DWORD *)(this + 312);
        Frequency.LowPart = BYTE1(v34);
        v35 = *(int **)(this + 32);
        *(float *)&PerformanceCount.LowPart = (double)BYTE2(v34) * 0.003921568859368563;
        *(float *)&PerformanceCount.HighPart = (double)BYTE1(v34) * 0.003921568859368563;
        v36 = (double)(unsigned __int8)v34;
        Frequency.LowPart = HIBYTE(v34);
        v37 = *v35;
        v38 = PerformanceCount.HighPart;
        *(_DWORD *)(v37 + 92) = PerformanceCount.LowPart;
        *(_DWORD *)(v37 + 96) = v38;
        v53 = v36 * 0.003921568859368563;
        v39 = (double)(int)Frequency.LowPart;
        *(float *)(v37 + 100) = v53;
        v54 = 0.003921568859368563 * v39;
        *(float *)(v37 + 104) = v54;
        v40 = **(_DWORD **)(this + 32);
        v41 = *(_DWORD *)(this + 24);
        v49 = *(_DWORD *)(this + 80) + 2 * v32;
        if ( *(_DWORD *)(*(_DWORD *)(v41 + 572) + 60) )
          sub_431020(&rc.left, v41, v40, v49, 0, v33);
        else
          sub_431380(&rc.left, v40, v41, v49, 0, v33);
        goto LABEL_48;
      }
      v32 = *(_DWORD *)(this + 292);
    }
    if ( v30 > v29 )
      v29 = *(_DWORD *)(this + 300);
    goto LABEL_45;
  }
LABEL_48:
  if ( (dword_4D8DF8 & 1) == 0 )
  {
    dword_4D8DF8 |= 1u;
    byte_4D8DD1 = 1;
    qword_4D8DD8 = 0;
    qword_4D8DE0 = 0;
    MEMORY[0x4D8DE4] = 0;
    qword_4D8DE8 = 0;
    MEMORY[0x4D8DEC] = 0;
    qword_4D8DF0 = 0;
    MEMORY[0x4D8DF4] = 0;
    Frequency.QuadPart = 0;
    QueryPerformanceFrequency(&Frequency);
    qword_4D8DD8 = Frequency.QuadPart;
  }
  PerformanceCount.QuadPart = 0;
  QueryPerformanceCounter(&PerformanceCount);
  if ( (double)PerformanceCount.QuadPart / (double)qword_4D8DD8 - *(double *)(this + 280) >= *(double *)(this + 272) )
  {
    v10 = (dword_4D8DF8 & 1) == 0;
    *(_BYTE *)(this + 288) = *(_BYTE *)(this + 288) == 0;
    if ( v10 )
    {
      dword_4D8DF8 |= 1u;
      sub_4375D0();
    }
    Frequency.QuadPart = 0;
    QueryPerformanceCounter(&Frequency);
    *(double *)(this + 280) = (double)Frequency.QuadPart / (double)qword_4D8DD8;
  }
  if ( *(_BYTE *)(this + 6) && *(_BYTE *)(this + 288) && !byte_4D7DEC )
  {
    v42 = xLeft - v56 + *(_DWORD *)(this + 108);
    v43 = *(_DWORD *)(this + 112);
    v44 = v42 - 1;
    v10 = *(_BYTE *)(this + 296) == 0;
    v58 = v42 + 1;
    v45 = *(_DWORD *)(this + 120);
    v57[0] = v44;
    v57[1] = v43;
    v59 = v45;
    if ( v10 )
    {
      v10 = *(_BYTE *)(this + 92) == 0;
      PerformanceCount.LowPart = *(_DWORD *)(this + 292);
      Frequency.LowPart = 0;
      if ( v10 || sub_436B30(this + 80) >= 0 )
        off_4D524C[0](*(_DWORD *)(this + 96), PerformanceCount.LowPart, 1, (int)&Frequency);
      v43 = *(_DWORD *)(this + 108) + Frequency.LowPart - v56;
      v58 = v43;
    }
    v46 = *(float *)(this + 320);
    v47 = *(_DWORD *)(this + 24);
    if ( *(_DWORD *)(*(_DWORD *)(v47 + 572) + 60) )
      sub_4302D0(v47, v46, v57);
    else
      sub_4304F0(LODWORD(v46), v43, v47, v57);
  }
}
