_DWORD *__thiscall sub_416030(int this)
{
  float *v2; // eax
  float *v3; // edi
  _DWORD *result; // eax
  _DWORD *v5; // esi
  int v6; // ecx
  float v7; // [esp+90h] [ebp-35Ch]
  _DWORD v8[4]; // [esp+94h] [ebp-358h] BYREF
  _BYTE v9[64]; // [esp+A4h] [ebp-348h] BYREF
  _BYTE v10[64]; // [esp+E4h] [ebp-308h] BYREF
  _BYTE v11[64]; // [esp+124h] [ebp-2C8h] BYREF
  _BYTE v12[64]; // [esp+164h] [ebp-288h] BYREF
  _BYTE v13[64]; // [esp+1A4h] [ebp-248h] BYREF
  _BYTE v14[64]; // [esp+1E4h] [ebp-208h] BYREF
  _BYTE v15[64]; // [esp+224h] [ebp-1C8h] BYREF
  _BYTE v16[64]; // [esp+264h] [ebp-188h] BYREF
  _BYTE v17[64]; // [esp+2A4h] [ebp-148h] BYREF
  _BYTE v18[64]; // [esp+2E4h] [ebp-108h] BYREF
  _BYTE v19[64]; // [esp+324h] [ebp-C8h] BYREF
  _BYTE v20[64]; // [esp+364h] [ebp-88h] BYREF
  _BYTE v21[68]; // [esp+3A4h] [ebp-48h] BYREF

  v7 = *(float *)(this + 448) + *(float *)(this + 444);
  D3DXMatrixTranslation(v14, 0.0, 0.0, LODWORD(v7));
  D3DXMatrixScaling(v15, *(float *)(this + 444), *(float *)(this + 444), *(float *)(this + 444));
  D3DXMatrixRotationYawPitchRoll(v16, 0.0, LODWORD(flt_4D6388), 0.0);
  D3DXMatrixMultiply(v12, v16, v15);
  qmemcpy(v13, v12, sizeof(v13));
  D3DXMatrixMultiply(v9, v13, v14);
  qmemcpy(v10, v9, sizeof(v10));
  D3DXMatrixMultiply(v11, v10, this + 104);
  qmemcpy(v20, v11, sizeof(v20));
  v2 = (float *)sub_4151B0((float *)this, v8);
  sub_44F2A0(v2, (int)v20, dword_4D8040, dword_4D7FA0, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4);
  D3DXMatrixRotationYawPitchRoll(v11, 0.0, 0.0, LODWORD(flt_4D6388));
  D3DXMatrixMultiply(v10, v16, v11);
  qmemcpy(v9, v10, sizeof(v9));
  D3DXMatrixMultiply(v13, v9, v15);
  qmemcpy(v12, v13, sizeof(v12));
  D3DXMatrixMultiply(v17, v12, v14);
  qmemcpy(v18, v17, sizeof(v18));
  D3DXMatrixMultiply(v19, v18, this + 104);
  qmemcpy(v21, v19, 0x40u);
  v3 = (float *)sub_4151B0((float *)this, v8);
  sub_44F2A0(v3, (int)v21, dword_4D8040, dword_4D7FA0, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4);
  result = *(_DWORD **)(this + 168);
  v5 = (_DWORD *)*result;
  if ( (_DWORD *)*result != result )
  {
    do
    {
      v6 = v5[2];
      v5 = (_DWORD *)*v5;
      result = (_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
    }
    while ( v5 != *(_DWORD **)(this + 168) );
  }
  return result;
}
