float *__thiscall sub_40A0E0(float *this)
{
  float *v2; // eax
  float *v3; // eax
  float *v4; // eax
  float *result; // eax
  float v6; // [esp+18h] [ebp-10Ch]
  float *v7; // [esp+28h] [ebp-FCh]
  float v8[3]; // [esp+2Ch] [ebp-F8h] BYREF
  float v9[3]; // [esp+38h] [ebp-ECh] BYREF
  float v10[3]; // [esp+44h] [ebp-E0h] BYREF
  float v11[3]; // [esp+50h] [ebp-D4h] BYREF
  _BYTE v12[64]; // [esp+5Ch] [ebp-C8h] BYREF
  _BYTE v13[64]; // [esp+9Ch] [ebp-88h] BYREF
  _BYTE v14[68]; // [esp+DCh] [ebp-48h] BYREF

  v6 = *(this + 50);
  v2 = sub_401470(v10, &flt_4D538C, 0.75);
  v7 = sub_401470(v11, v2, v6);
  v3 = sub_408590(this + 53, v9);
  v4 = sub_401430(v8, v7, v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))D3DXMatrixTranslation)(v12, *v4, v4[1], v4[2]);
  D3DXMatrixScaling(v13, *(this + 49), *(this + 50), *(this + 49));
  D3DXMatrixMultiply(v14, v13, v12);
  qmemcpy(this + 10, v14, 0x40u);
  result = sub_408590(this + 53, v8);
  *(this + 6) = *result;
  *(this + 7) = result[1];
  *(this + 8) = result[2];
  return result;
}
