float *__cdecl sub_40A320(float *a1, int a2)
{
  float *v2; // eax
  float *v3; // eax
  float v5[3]; // [esp+Ch] [ebp-B0h] BYREF
  float v6[3]; // [esp+18h] [ebp-A4h] BYREF
  float v7[3]; // [esp+24h] [ebp-98h] BYREF
  float v8[16]; // [esp+30h] [ebp-8Ch] BYREF
  _BYTE v9[68]; // [esp+70h] [ebp-4Ch] BYREF

  v2 = (float *)sub_401070(a2, (int)v6);
  sub_408590(v2, v5);
  v3 = sub_401120(v6, flt_4D5380, v5);
  sub_401070((int)v3, (int)v7);
  sub_401120(v6, v5, v7);
  v8[0] = v7[0];
  v8[1] = v5[0];
  v8[2] = v6[0];
  v8[3] = 0.0;
  v8[4] = v7[1];
  v8[5] = v5[1];
  v8[6] = v6[1];
  v8[7] = 0.0;
  v8[8] = v7[2];
  v8[9] = v5[2];
  v8[10] = v6[2];
  v8[11] = 0.0;
  v8[12] = 0.0;
  v8[13] = 0.0;
  v8[14] = 0.0;
  v8[15] = 1.0;
  qmemcpy(v9, v8, 0x40u);
  D3DXMatrixInverse(v8, 0, v9);
  qmemcpy(a1, v8, 0x40u);
  return a1;
}
