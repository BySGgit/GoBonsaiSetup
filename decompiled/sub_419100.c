int __thiscall sub_419100(float *this, float *a2, float a3)
{
  float v5; // [esp+40h] [ebp-254h]
  float v6; // [esp+48h] [ebp-24Ch]
  float v7[16]; // [esp+4Ch] [ebp-248h] BYREF
  _BYTE v8[64]; // [esp+8Ch] [ebp-208h] BYREF
  _BYTE v9[64]; // [esp+CCh] [ebp-1C8h] BYREF
  _BYTE v10[64]; // [esp+10Ch] [ebp-188h] BYREF
  _BYTE v11[64]; // [esp+14Ch] [ebp-148h] BYREF
  _BYTE v12[64]; // [esp+18Ch] [ebp-108h] BYREF
  _BYTE v13[64]; // [esp+1CCh] [ebp-C8h] BYREF
  _BYTE v14[64]; // [esp+20Ch] [ebp-88h] BYREF
  _DWORD v15[17]; // [esp+24Ch] [ebp-48h] BYREF

  D3DXMatrixTranslation(v10, 0.0, 0.0, 1.0);
  v5 = *(this + 111) * a3;
  v6 = *(this + 112) * 0.5099999904632568;
  D3DXMatrixScaling(v14, LODWORD(v5), LODWORD(v5), LODWORD(v6));
  v7[0] = flt_4D6430;
  v7[1] = 0.0;
  v7[2] = 0.0;
  v7[3] = 0.0;
  v7[4] = 0.0;
  v7[6] = 0.0;
  v7[7] = 0.0;
  v7[8] = 0.0;
  v7[9] = 0.0;
  v7[5] = flt_4D6430;
  v7[10] = 1.0;
  v7[11] = 0.029999971;
  v7[14] = 0.029999971;
  v7[12] = 0.0;
  v7[13] = 0.0;
  v7[15] = 1.0;
  qmemcpy(v8, v7, sizeof(v8));
  D3DXMatrixMultiply(v7, v8, v10);
  qmemcpy(v12, v7, sizeof(v12));
  D3DXMatrixMultiply(v9, v12, v14);
  qmemcpy(v11, v9, sizeof(v11));
  D3DXMatrixMultiply(v13, v11, this + 26);
  qmemcpy(v15, v13, 0x40u);
  return sub_44F2A0(a2, (int)v15, dword_4D8040, dword_4D7FB8, dword_4D7FC0, dword_4D7FBC, dword_4D7FC8, dword_4D7FCC);
}
