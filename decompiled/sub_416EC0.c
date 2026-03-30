int __thiscall sub_416EC0(float *this, float *a2, float a3)
{
  float v5; // [esp+3Ch] [ebp-264h]
  float v6; // [esp+50h] [ebp-250h]
  float v7; // [esp+50h] [ebp-250h]
  _BYTE v8[4]; // [esp+58h] [ebp-248h] BYREF
  float v9; // [esp+5Ch] [ebp-244h]
  _BYTE v10[64]; // [esp+64h] [ebp-23Ch] BYREF
  _BYTE v11[64]; // [esp+A4h] [ebp-1FCh] BYREF
  _BYTE v12[64]; // [esp+E4h] [ebp-1BCh] BYREF
  _BYTE v13[64]; // [esp+124h] [ebp-17Ch] BYREF
  _BYTE v14[64]; // [esp+164h] [ebp-13Ch] BYREF
  _BYTE v15[52]; // [esp+1A4h] [ebp-FCh] BYREF
  _BYTE v16[76]; // [esp+1D8h] [ebp-C8h] BYREF
  _BYTE v17[52]; // [esp+224h] [ebp-7Ch] BYREF
  _BYTE v18[68]; // [esp+258h] [ebp-48h] BYREF

  v6 = a3 * *(this + 111);
  v5 = v6;
  v7 = a3 * -*(this + 111) * 0.3499999940395355;
  D3DXMatrixTranslation(v8, 0.0, LODWORD(v7), LODWORD(v5));
  v9 = a3 * *(this + 111) * 0.5;
  D3DXMatrixScaling(v17, LODWORD(v9), LODWORD(v9), LODWORD(v9));
  D3DXMatrixRotationYawPitchRoll(v15, 0.0, 2.1991148, 0.0);
  D3DXMatrixMultiply(v13, v15, v17);
  qmemcpy(v11, v13, sizeof(v11));
  D3DXMatrixMultiply(v12, v11, v10);
  qmemcpy(v14, v12, sizeof(v14));
  D3DXMatrixMultiply(&v16[12], v14, this + 26);
  qmemcpy(v18, v16, 0x40u);
  return sub_44F2A0(a2, (int)v18, dword_4D8040, dword_4D7FA0, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4);
}
