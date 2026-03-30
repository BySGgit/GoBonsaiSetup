float *__thiscall sub_417300(int this)
{
  int v2; // eax
  float *v3; // eax
  float *v4; // eax
  float *v5; // eax
  float *result; // eax
  float v7; // [esp+20h] [ebp-140h]
  float v8; // [esp+24h] [ebp-13Ch]
  float v9[3]; // [esp+34h] [ebp-12Ch] BYREF
  float v10[3]; // [esp+40h] [ebp-120h] BYREF
  float v11[3]; // [esp+4Ch] [ebp-114h] BYREF
  _BYTE v12[64]; // [esp+58h] [ebp-108h] BYREF
  _BYTE v13[64]; // [esp+98h] [ebp-C8h] BYREF
  _BYTE v14[64]; // [esp+D8h] [ebp-88h] BYREF
  _BYTE v15[68]; // [esp+118h] [ebp-48h] BYREF

  D3DXMatrixRotationQuaternion(v14, this + 320);
  D3DXMatrixMultiply(v13, v14, this + 240);
  v2 = *(_DWORD *)(this + 180);
  qmemcpy((void *)(this + 40), v13, 0x40u);
  if ( v2 )
  {
    D3DXMatrixMultiply(v13, this + 240, v2 + 104);
    qmemcpy(v15, v13, 0x40u);
    D3DXMatrixInverse(v12, 0, v15);
  }
  else
  {
    D3DXMatrixInverse(v12, 0, this + 240);
  }
  v8 = flt_4D63B0;
  v7 = *(float *)(this + 448);
  qmemcpy((void *)(this + 352), v12, 0x40u);
  v3 = sub_401470(v10, &flt_4D5398, v7);
  v4 = sub_401470(v11, v3, v8);
  sub_401540((int)v4, v9, this + 104);
  v5 = sub_4015F0(v11, (float *)(this + 104));
  result = sub_4013F0(v10, v9, v5);
  *(float *)(this + 24) = *result;
  *(float *)(this + 28) = result[1];
  *(float *)(this + 32) = result[2];
  return result;
}
