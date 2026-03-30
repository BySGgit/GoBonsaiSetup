_DWORD *__thiscall sub_418F10(int this)
{
  float *v2; // edi
  _DWORD *result; // eax
  _DWORD *v4; // esi
  int v5; // ecx
  float v6; // [esp+40h] [ebp-25Ch]
  _DWORD v7[4]; // [esp+44h] [ebp-258h] BYREF
  float v8[16]; // [esp+54h] [ebp-248h] BYREF
  _BYTE v9[64]; // [esp+94h] [ebp-208h] BYREF
  _BYTE v10[64]; // [esp+D4h] [ebp-1C8h] BYREF
  _BYTE v11[64]; // [esp+114h] [ebp-188h] BYREF
  _BYTE v12[64]; // [esp+154h] [ebp-148h] BYREF
  _BYTE v13[64]; // [esp+194h] [ebp-108h] BYREF
  _BYTE v14[64]; // [esp+1D4h] [ebp-C8h] BYREF
  _BYTE v15[64]; // [esp+214h] [ebp-88h] BYREF
  _DWORD v16[17]; // [esp+254h] [ebp-48h] BYREF

  D3DXMatrixTranslation(v15, 0.0, 0.0, 1.0);
  v6 = *(float *)(this + 448) * 0.5099999904632568;
  D3DXMatrixScaling(v9, *(float *)(this + 444), *(float *)(this + 444), LODWORD(v6));
  v8[0] = flt_4D6430;
  v8[1] = 0.0;
  v8[2] = 0.0;
  v8[3] = 0.0;
  v8[4] = 0.0;
  v8[6] = 0.0;
  v8[7] = 0.0;
  v8[8] = 0.0;
  v8[9] = 0.0;
  v8[5] = flt_4D6430;
  v8[10] = 1.0;
  v8[11] = 0.029999971;
  v8[14] = 0.029999971;
  v8[12] = 0.0;
  v8[13] = 0.0;
  v8[15] = 1.0;
  qmemcpy(v11, v8, sizeof(v11));
  D3DXMatrixMultiply(v8, v11, v15);
  qmemcpy(v13, v8, sizeof(v13));
  D3DXMatrixMultiply(v10, v13, v9);
  qmemcpy(v12, v10, sizeof(v12));
  D3DXMatrixMultiply(v14, v12, this + 104);
  qmemcpy(v16, v14, 0x40u);
  v2 = (float *)sub_4151B0((float *)this, v7);
  sub_44F2A0(v2, (int)v16, dword_4D8040, dword_4D7FB8, dword_4D7FC0, dword_4D7FBC, dword_4D7FC8, dword_4D7FCC);
  result = *(_DWORD **)(this + 168);
  v4 = (_DWORD *)*result;
  if ( (_DWORD *)*result != result )
  {
    do
    {
      v5 = v4[2];
      v4 = (_DWORD *)*v4;
      result = (_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    }
    while ( v4 != *(_DWORD **)(this + 168) );
  }
  return result;
}
