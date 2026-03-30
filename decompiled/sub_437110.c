int __userpurge sub_437110@<eax>(int a1@<eax>, float *a2@<esi>, float a3, float a4)
{
  float v4; // eax
  double v5; // st6
  int result; // eax
  int v7; // [esp+4h] [ebp-14h]
  float v8; // [esp+4h] [ebp-14h]
  float v9; // [esp+4h] [ebp-14h]
  float v10; // [esp+4h] [ebp-14h]
  float v11; // [esp+8h] [ebp-10h]
  float v12; // [esp+Ch] [ebp-Ch]
  float v13; // [esp+10h] [ebp-8h]
  float v14; // [esp+14h] [ebp-4h]

  v4 = a2[a1];
  v11 = (double)BYTE2(v4) * 0.003921568859368563;
  v5 = (double)BYTE1(v4);
  v7 = LOBYTE(v4);
  result = HIBYTE(LODWORD(v4));
  v12 = v5 * 0.003921568859368563;
  v13 = (double)v7 * 0.003921568859368563;
  v14 = 0.003921568859368563 * (double)result;
  v8 = a3 * 30.0;
  v9 = pow(a4, v8);
  v10 = 1.0 - v9;
  a2[6] = (v11 - a2[6]) * v10 + a2[6];
  a2[7] = (v12 - a2[7]) * v10 + a2[7];
  a2[8] = (v13 - a2[8]) * v10 + a2[8];
  a2[9] = v10 * (v14 - a2[9]) + a2[9];
  return result;
}
