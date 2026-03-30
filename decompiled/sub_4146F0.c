float *__thiscall sub_4146F0(int this)
{
  float *result; // eax
  int v3; // eax
  float *v4; // eax
  float *v5; // eax
  float *v6; // eax
  float v7; // [esp+24h] [ebp-144h]
  float v8; // [esp+38h] [ebp-130h]
  float v9[3]; // [esp+3Ch] [ebp-12Ch] BYREF
  float v10[3]; // [esp+48h] [ebp-120h] BYREF
  float v11[3]; // [esp+54h] [ebp-114h] BYREF
  _BYTE v12[64]; // [esp+60h] [ebp-108h] BYREF
  _BYTE v13[64]; // [esp+A0h] [ebp-C8h] BYREF
  _BYTE v14[64]; // [esp+E0h] [ebp-88h] BYREF
  _BYTE v15[68]; // [esp+120h] [ebp-48h] BYREF

  result = *(float **)(this + 180);
  if ( result )
  {
    v8 = *(float *)(this + 296);
    *(float *)(this + 296) = result[112] * v8;
    D3DXMatrixRotationQuaternion(v15, this + 320);
    D3DXMatrixMultiply(v12, v15, this + 240);
    v3 = *(_DWORD *)(this + 180);
    qmemcpy((void *)(this + 40), v12, 0x40u);
    if ( v3 )
    {
      D3DXMatrixMultiply(v12, this + 240, v3 + 104);
      qmemcpy(v14, v12, sizeof(v14));
      D3DXMatrixInverse(v13, 0, v14);
    }
    else
    {
      D3DXMatrixInverse(v13, 0, this + 240);
    }
    qmemcpy((void *)(this + 352), v13, 0x40u);
    *(float *)(this + 296) = v8;
    v7 = flt_4D63B0;
    v4 = sub_401470(v10, &flt_4D5398, *(float *)(this + 448));
    v5 = sub_401470(v11, v4, v7);
    sub_401540((int)v5, v9, this + 104);
    v6 = sub_4015F0(v11, (float *)(this + 104));
    result = sub_4013F0(v10, v9, v6);
    *(float *)(this + 24) = *result;
    *(float *)(this + 28) = result[1];
    *(float *)(this + 32) = result[2];
  }
  return result;
}
