float *sub_402040()
{
  int v0; // ebx
  float *result; // eax
  float *v2; // eax
  double v3; // st7
  float v4; // eax
  int v5; // ecx
  bool v6; // zf
  float *v7; // eax
  double v8; // st7
  int v9; // ecx
  int v10; // edx
  double v11; // st7
  float *v12; // eax
  float *v13; // eax
  float v14; // [esp+24h] [ebp-70h] BYREF
  float v15; // [esp+28h] [ebp-6Ch]
  float v16; // [esp+2Ch] [ebp-68h]
  float v17; // [esp+30h] [ebp-64h]
  float v18[3]; // [esp+34h] [ebp-60h] BYREF
  float v19[3]; // [esp+40h] [ebp-54h] BYREF
  float v20[17]; // [esp+4Ch] [ebp-48h] BYREF

  v0 = dword_4D7EEC;
  if ( *(_BYTE *)(dword_4D7EEC + 420) )
    return sub_402310(dword_4D7EEC);
  if ( byte_4D8CA6 )
  {
    if ( *(_BYTE *)(dword_4D7EEC + 388) )
    {
      v3 = 0.78539819;
      *(_DWORD *)(dword_4D7EEC + 404) = dword_4D82D4;
      *(_DWORD *)(v0 + 408) = dword_4D82D8;
      v5 = dword_4D82DC;
    }
    else
    {
      sub_4081F0(v19, (int)&dword_4D8C94);
      v2 = (float *)sub_401540((int)v19, &v14, v0 + 224);
      v19[0] = *v2;
      v19[1] = v2[1];
      v19[2] = v2[2];
      sub_401190(&v14, (int)v19);
      v3 = 0.19634955;
      v4 = v15;
      v5 = LODWORD(v16);
      *(float *)(v0 + 404) = v14;
      *(float *)(v0 + 408) = v4;
    }
    v6 = *(_BYTE *)(v0 + 388) == 0;
    *(float *)(v0 + 416) = v3;
    *(_DWORD *)(v0 + 412) = v5;
    *(_BYTE *)(v0 + 388) = v6;
  }
  if ( *(_BYTE *)(v0 + 388) )
    sub_402880(v0);
  else
    sub_402600((float *)v0);
  sub_401300((float *)(v0 + 392));
  sub_401300((float *)(v0 + 404));
  sub_401430(&v14, (float *)(v0 + 392), (float *)(v0 + 404));
  sub_401300(&v14);
  v7 = sub_401470(v19, &v14, flt_4CA5E8);
  *(float *)(v0 + 392) = *v7 + *(float *)(v0 + 392);
  *(float *)(v0 + 396) = v7[1] + *(float *)(v0 + 396);
  *(float *)(v0 + 400) = v7[2] + *(float *)(v0 + 400);
  sub_401300((float *)(v0 + 392));
  v8 = *(float *)(v0 + 416) - *(float *)(v0 + 196);
  v9 = *(_DWORD *)(v0 + 356);
  v10 = *(_DWORD *)(v0 + 360);
  *(_DWORD *)(v0 + 212) = *(_DWORD *)(v0 + 352);
  v17 = v8;
  *(_DWORD *)(v0 + 216) = v9;
  v11 = v17;
  *(_DWORD *)(v0 + 220) = v10;
  *(float *)(v0 + 196) = v11 * 0.1000000014901161 + *(float *)(v0 + 196);
  D3DXMatrixRotationYawPitchRoll(v20, *(float *)(v0 + 212), *(float *)(v0 + 216), *(float *)(v0 + 220));
  v12 = sub_4015D0(v19, v20);
  v13 = sub_401500(v18, v12, *(float *)(v0 + 384));
  result = sub_401430(&v14, v13, (float *)(v0 + 364));
  *(float *)(v0 + 88) = v14;
  *(float *)(v0 + 92) = v15;
  *(float *)(v0 + 96) = v16;
  return result;
}
