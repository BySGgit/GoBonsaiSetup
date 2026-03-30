double __usercall sub_42A3E0@<st0>(_DWORD *a1@<edi>, _DWORD *a2, int a3)
{
  _DWORD *v3; // ebp
  double v4; // st7
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // ebx
  double v9; // st2
  int v10; // eax
  int v11; // ecx
  double v12; // st2
  int v13; // eax
  bool v14; // zf
  int v15; // eax
  int v16; // ecx
  char v17; // bl
  _DWORD *v18; // eax
  int v19; // esi
  int v20; // esi
  int v21; // ecx
  double v22; // st7
  double v23; // st5
  int v24; // eax
  int v25; // ecx
  double v26; // st4
  double v27; // st5
  int v28; // ecx
  int v29; // eax
  _DWORD *v30; // ecx
  int v31; // eax
  char v32; // bl
  int v33; // eax
  int v34; // edx
  _DWORD *v35; // ecx
  int v36; // eax
  float v38; // [esp+4h] [ebp-18h]
  float v39; // [esp+4h] [ebp-18h]
  float v40; // [esp+4h] [ebp-18h]
  float v42; // [esp+8h] [ebp-14h]
  int v43; // [esp+8h] [ebp-14h]
  float v44; // [esp+20h] [ebp+4h]

  v38 = 0.0;
  v3 = a2;
  v4 = 0.0;
  if ( *a1 == *a2 )
    v38 = 0.0 + 1000.0;
  v5 = a1[1];
  if ( v5 == a2[1] )
    v38 = v38 + 100.0;
  if ( v5 == 1 )
    v38 = v38 + 0.1000000014901161;
  v6 = a1[4];
  if ( v6 == a2[12] )
    v38 = v38 + 10.0;
  v7 = a2[2];
  v8 = a1[2];
  if ( v8 == v7 )
  {
    v9 = v38 + 1.0;
  }
  else
  {
    switch ( v8 )
    {
      case 20:
      case 21:
      case 22:
      case 32:
        v10 = 8;
        break;
      case 23:
      case 24:
      case 25:
        v10 = 5;
        break;
      case 26:
      case 30:
        v10 = 4;
        break;
      case 27:
      case 29:
        v10 = 2;
        break;
      case 31:
      case 35:
        v10 = 10;
        break;
      case 36:
        v10 = 16;
        break;
      default:
        v10 = 0;
        break;
    }
    switch ( v7 )
    {
      case 20:
      case 21:
      case 22:
      case 32:
        v11 = 8;
        break;
      case 23:
      case 24:
      case 25:
        v11 = 5;
        break;
      case 26:
      case 30:
        v11 = 4;
        break;
      case 27:
      case 29:
        v11 = 2;
        break;
      case 31:
      case 35:
        v11 = 10;
        break;
      case 36:
        v11 = 16;
        break;
      default:
        v11 = 0;
        break;
    }
    v12 = 0.8999999761581421 - (double)(int)abs32(v10 - v11) * 0.2000000029802322;
    if ( v12 <= 0.0 )
      v12 = 0.0;
    v42 = v12;
    v9 = v42 + v38;
  }
  v39 = v9;
  if ( !v6 )
  {
    v13 = *(_DWORD *)(a3 + 12);
    switch ( v13 )
    {
      case 20:
      case 21:
      case 22:
      case 31:
      case 32:
      case 35:
      case 36:
        v14 = v8 == v13;
        break;
      default:
        v14 = v8 == 22;
        break;
    }
    if ( v14 )
      v39 = v39 + 0.1000000014901161;
  }
  if ( (a2[3] & 0xC0) != 0 && (*(_DWORD *)(a1[21] + 36) & 0x10000) != 0 )
    v39 = v39 + 1.0;
  if ( (*(_DWORD *)(a1[21] + 36) & 0x10000) != 0 )
    v39 = v39 + 0.1000000014901161;
  v15 = a1[20];
  v16 = *(_DWORD *)(v15 + 1620);
  v17 = 0;
  v43 = v16;
  if ( v16 > 0 )
  {
    v18 = *(_DWORD **)(v15 + 1616);
    v19 = v16;
    do
    {
      v3 = a2;
      if ( v18[3] == a1[2] && *v18 == a2[4] && v18[1] == a2[5] )
        v17 = 1;
      v18 += 4;
      --v19;
    }
    while ( v19 );
    if ( v17 )
      v39 = v39 + 1.0;
  }
  v20 = a1[3];
  v21 = v3[6];
  if ( v20 == v21 )
  {
    v22 = 1.0;
    v23 = v39 + 1.0;
  }
  else
  {
    switch ( v20 )
    {
      case 20:
      case 21:
      case 22:
      case 32:
        v24 = 8;
        break;
      case 23:
      case 24:
      case 25:
        v24 = 5;
        break;
      case 26:
      case 30:
        v24 = 4;
        break;
      case 27:
      case 29:
        v24 = 2;
        break;
      case 31:
      case 35:
        v24 = 10;
        break;
      case 36:
        v24 = 16;
        break;
      default:
        v24 = 0;
        break;
    }
    switch ( v21 )
    {
      case 20:
      case 21:
      case 22:
      case 32:
        v25 = 8;
        break;
      case 23:
      case 24:
      case 25:
        v25 = 5;
        break;
      case 26:
      case 30:
        v25 = 4;
        break;
      case 27:
      case 29:
        v25 = 2;
        break;
      case 31:
      case 35:
        v25 = 10;
        break;
      case 36:
        v25 = 16;
        break;
      default:
        v25 = 0;
        break;
    }
    v26 = 0.8999999761581421 - 0.2000000029802322 * (double)(int)abs32(v24 - v25);
    if ( v26 > 0.0 )
      v4 = v26;
    v27 = v4;
    v22 = 1.0;
    v44 = v27;
    v23 = v44 + v39;
  }
  v40 = v23;
  if ( v20 == a1[2] )
    v40 = v40 + 0.1000000014901161;
  v28 = a1[9];
  v29 = 0;
  if ( v28 > 0 )
  {
    while ( *(_DWORD *)(a1[8] + 4 * v29) != v3[8] || *(_DWORD *)(a1[11] + 4 * v29) <= v3[9] )
    {
      if ( ++v29 >= v28 )
        goto LABEL_79;
    }
    v40 = v40 + v22;
  }
LABEL_79:
  if ( (int)a1[6] > 0 )
  {
    v30 = (_DWORD *)a1[5];
    v31 = 0;
    while ( v3[14] != *v30 )
    {
      ++v31;
      ++v30;
      if ( v31 >= a1[6] )
        goto LABEL_86;
    }
    if ( v31 != -1 )
      v40 = v40 + v22;
  }
LABEL_86:
  v32 = 0;
  if ( v43 > 0 )
  {
    v33 = *(_DWORD *)(a1[20] + 1616);
    v34 = v43;
    do
    {
      if ( *(_DWORD *)(v33 + 12) == a1[2] && *(_DWORD *)(v33 + 8) == v3[16] )
        v32 = 1;
      v33 += 16;
      --v34;
    }
    while ( v34 );
    if ( v32 )
      v40 = v40 + v22;
  }
  if ( (int)a1[15] <= 0 )
    return v40;
  v35 = (_DWORD *)a1[14];
  v36 = 0;
  while ( v3[17] != *v35 )
  {
    ++v36;
    ++v35;
    if ( v36 >= a1[15] )
      return v40;
  }
  if ( v36 == -1 )
    return v40;
  return (float)(v22 + v40);
}
