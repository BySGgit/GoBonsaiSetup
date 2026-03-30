int __stdcall sub_408A30(int a1)
{
  int v1; // eax
  float v2; // ecx
  int v3; // esi
  double v4; // st7
  double v5; // st6
  double v6; // st7
  float *v7; // eax
  float *v8; // edi
  double v9; // st7
  double v10; // st6
  double v11; // st5
  float *v12; // eax
  float *v13; // eax
  float *v14; // eax
  _DWORD *v15; // edi
  _DWORD *v16; // eax
  int result; // eax
  float v18; // [esp+14h] [ebp-CCh]
  float v19; // [esp+14h] [ebp-CCh]
  float v20; // [esp+14h] [ebp-CCh]
  float v21; // [esp+14h] [ebp-CCh]
  float v22; // [esp+14h] [ebp-CCh]
  float v23; // [esp+14h] [ebp-CCh]
  double v24[2]; // [esp+18h] [ebp-C8h] BYREF
  _DWORD *v25; // [esp+2Ch] [ebp-B4h]
  float v26; // [esp+30h] [ebp-B0h] BYREF
  float v27; // [esp+34h] [ebp-ACh]
  float v28; // [esp+38h] [ebp-A8h]
  float v29; // [esp+3Ch] [ebp-A4h]
  float v30[6]; // [esp+40h] [ebp-A0h] BYREF
  _BYTE v31[64]; // [esp+58h] [ebp-88h] BYREF
  _BYTE v32[68]; // [esp+98h] [ebp-48h] BYREF

  v26 = (double)rand() / 32767.0 + 0.0;
  v27 = (double)rand() / 32767.0 + 0.0;
  v1 = rand();
  v2 = v27;
  *(float *)(a1 + 252) = v26;
  *(float *)(a1 + 256) = v2;
  v28 = (double)v1 / 32767.0 + 0.0;
  *(float *)(a1 + 260) = v28;
  v29 = 1.0;
  *(float *)(a1 + 264) = 1.0;
  LODWORD(v24[0]) = rand();
  v3 = *(_DWORD *)(a1 + 276);
  *(float *)(a1 + 272) = (double)SLODWORD(v24[0]) / 32767.0 * 0.800000011920929 + 0.2000000029802322;
  v18 = sub_4153D0(*(_DWORD *)(v3 + 240));
  *(float *)v24 = sub_403BA0(v3);
  v25 = (_DWORD *)rand();
  *(float *)(a1 + 204) = ((double)(int)v25 / 32767.0 * 0.2000000476837158 + 0.8999999761581421)
                       * (v18
                        * 0.3330000042915344);
  v4 = *(float *)v24;
  v19 = ((double)rand() / 32767.0 * 0.2000000476837158 + 0.8999999761581421) * (*(float *)v24 + *(float *)v24);
  *(float *)(a1 + 208) = v19;
  if ( *(float *)(a1 + 204) < 10.0 )
    *(float *)(a1 + 204) = 10.0;
  v5 = v4;
  v6 = v19;
  v20 = v5 * 4.0;
  if ( v20 > (double)*(float *)(a1 + 204) )
    *(float *)(a1 + 204) = v20;
  if ( flt_4D62D8 > v6 )
    *(float *)(a1 + 208) = flt_4D62D8;
  if ( *(float *)(a1 + 208) > 15.0 )
    *(float *)(a1 + 208) = 15.0;
  sub_401B10(*(_DWORD *)(a1 + 276), v30);
  sub_401690(v30, (int)&v26);
  v7 = sub_408590(&v26, v30);
  v8 = (float *)(a1 + 224);
  *(float *)(a1 + 224) = *v7;
  *(float *)(a1 + 228) = v7[1];
  *(float *)(a1 + 232) = v7[2];
  *(float *)(a1 + 228) = 0.0;
  v9 = *(float *)(a1 + 228);
  v25 = (_DWORD *)(a1 + 224);
  v10 = *(float *)(a1 + 224);
  v11 = *(float *)(a1 + 232);
  v24[0] = *(float *)(a1 + 204) - *(float *)v24;
  v21 = v9 * v9 + v10 * v10 + v11 * v11;
  v22 = sqrt(v21);
  if ( 0.699999988079071 * v24[0] < v22 )
  {
    v23 = v24[0];
    v12 = sub_408470(v30, v8);
    v13 = sub_401470((float *)v24, v12, v23);
    v14 = sub_401470(&v26, v13, 0.69999999);
    *v8 = *v14;
    *(float *)(a1 + 228) = v14[1];
    *(float *)(a1 + 232) = v14[2];
  }
  D3DXMatrixInverse(v31, 0, *(_DWORD *)(a1 + 276) + 104);
  qmemcpy(v32, v31, 0x40u);
  v15 = v25;
  v16 = sub_401540((int)v25, &v26, (int)v32);
  *v15 = *v16;
  v15[1] = v16[1];
  result = v16[2];
  v15[2] = result;
  return result;
}
