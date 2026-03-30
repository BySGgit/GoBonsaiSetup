double __cdecl sub_42CB30(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // ebp
  double v3; // st7
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // ebx
  char *v9; // eax
  int v10; // ecx
  int v11; // eax
  double v12; // st7
  double v13; // st5
  int v14; // eax
  int v15; // ecx
  double v16; // st4
  double v17; // st5
  int v18; // ecx
  int v19; // eax
  int v20; // ebx
  double v21; // st5
  int v22; // edx
  unsigned int v23; // ebp
  double v24; // st5
  char *v25; // edx
  int v26; // ebx
  char v28; // [esp+Bh] [ebp-2Dh]
  float v29; // [esp+Ch] [ebp-2Ch]
  float v30; // [esp+Ch] [ebp-2Ch]
  int v31; // [esp+10h] [ebp-28h]
  int v32; // [esp+14h] [ebp-24h]
  float v33; // [esp+18h] [ebp-20h]
  float v34; // [esp+18h] [ebp-20h]
  float v35; // [esp+18h] [ebp-20h]
  float v36; // [esp+18h] [ebp-20h]
  float v37; // [esp+18h] [ebp-20h]
  float v38; // [esp+18h] [ebp-20h]
  float v39; // [esp+18h] [ebp-20h]
  float v40; // [esp+18h] [ebp-20h]
  _DWORD v41[7]; // [esp+1Ch] [ebp-1Ch] BYREF
  float v42; // [esp+3Ch] [ebp+4h]
  char v43; // [esp+3Ch] [ebp+4h]
  float v44; // [esp+40h] [ebp+8h]
  float v45; // [esp+40h] [ebp+8h]

  v29 = 0.0;
  v2 = a2;
  v3 = 0.0;
  v4 = a1;
  if ( *a1 == *a2 )
    v29 = 0.0 + 1000.0;
  if ( a1[4] == a2[2] )
    v29 = v29 + 500.0;
  v5 = a1[1];
  if ( v5 == a2[1] )
    v29 = v29 + 100.0;
  if ( v5 == 1 )
    v29 = v29 + 0.1000000014901161;
  if ( a1[3] == a2[15] )
    v29 = v29 + 10.0;
  v6 = a1[13];
  v7 = *(_DWORD *)(v6 + 108);
  v28 = 0;
  v32 = v6;
  v31 = v7;
  if ( v7 > 0 )
  {
    v8 = a2[3];
    v9 = *(char **)(v6 + 104);
    do
    {
      qmemcpy(v41, v9, sizeof(v41));
      if ( v41[0] == v8 && v41[1] == a2[4] )
        v28 = 1;
      v9 += 28;
      --v7;
    }
    while ( v7 );
    v4 = a1;
    if ( v28 )
      v29 = v29 + 1.0;
  }
  v10 = a2[7];
  v11 = v4[2];
  if ( v11 == v10 )
  {
    v12 = 1.0;
    v13 = v29 + 1.0;
  }
  else
  {
    switch ( v11 )
    {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
        v14 = 32;
        break;
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
        v14 = 16;
        break;
      case 23:
      case 24:
      case 25:
        v14 = 10;
        break;
      case 27:
      case 28:
      case 29:
      case 30:
      case 31:
      case 32:
        v14 = 8;
        break;
      case 85:
      case 86:
        v14 = 5;
        break;
      default:
        v14 = 0;
        break;
    }
    switch ( v10 )
    {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
        v15 = 32;
        break;
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
        v15 = 16;
        break;
      case 23:
      case 24:
      case 25:
        v15 = 10;
        break;
      case 27:
      case 28:
      case 29:
      case 30:
      case 31:
      case 32:
        v15 = 8;
        break;
      case 85:
      case 86:
        v15 = 5;
        break;
      default:
        v15 = 0;
        break;
    }
    v16 = 0.8999999761581421 - (double)(int)abs32(v14 - v15) * 0.2000000029802322;
    if ( v16 > 0.0 )
      v3 = v16;
    v17 = v3;
    v12 = 1.0;
    v42 = v17;
    v13 = v42 + v29;
  }
  v18 = v4[6];
  v30 = v13;
  v19 = 0;
  if ( v18 > 0 )
  {
    while ( *(_DWORD *)(v4[5] + 4 * v19) != a2[10] || *(_DWORD *)(v4[8] + 4 * v19) <= a2[11] )
    {
      if ( ++v19 >= v18 )
        goto LABEL_44;
    }
    v30 = v30 + v12;
  }
LABEL_44:
  v20 = 0;
  v43 = 0;
  if ( v31 >= 4 )
  {
    v21 = (double)(unsigned int)a2[5] / (double)(unsigned int)a2[6];
    v22 = *(_DWORD *)(v32 + 104) + 56;
    v23 = ((unsigned int)(v31 - 4) >> 2) + 1;
    v20 = 4 * v23;
    do
    {
      qmemcpy(v41, (const void *)(v22 - 56), sizeof(v41));
      v33 = (double)v41[2] / (double)v41[3] - v21;
      v34 = fabs(v33);
      if ( v34 < 0.1000000014901161 )
        v43 = 1;
      qmemcpy(v41, (const void *)(v22 - 28), sizeof(v41));
      v35 = (double)v41[2] / (double)v41[3] - v21;
      v36 = fabs(v35);
      if ( v36 < 0.1000000014901161 )
        v43 = 1;
      qmemcpy(v41, (const void *)v22, sizeof(v41));
      v37 = (double)v41[2] / (double)v41[3] - v21;
      v38 = fabs(v37);
      if ( v38 < 0.1000000014901161 )
        v43 = 1;
      qmemcpy(v41, (const void *)(v22 + 28), sizeof(v41));
      v39 = (double)v41[2] / (double)v41[3] - v21;
      v40 = fabs(v39);
      if ( v40 < 0.1000000014901161 )
        v43 = 1;
      v22 += 112;
      --v23;
    }
    while ( v23 );
    v2 = a2;
  }
  if ( v20 < v31 )
  {
    v24 = (double)(unsigned int)v2[5] / (double)(unsigned int)v2[6];
    v25 = (char *)(*(_DWORD *)(v32 + 104) + 28 * v20);
    v26 = v31 - v20;
    do
    {
      qmemcpy(v41, v25, sizeof(v41));
      v44 = (double)v41[2] / (double)v41[3] - v24;
      v45 = fabs(v44);
      if ( v45 < 0.1000000014901161 )
        v43 = 1;
      v25 += 28;
      --v26;
    }
    while ( v26 );
  }
  if ( v43 )
    return (float)(v12 + v30);
  return v30;
}
