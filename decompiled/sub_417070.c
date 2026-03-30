_DWORD *__thiscall sub_417070(int this)
{
  float *v2; // edi
  _DWORD *result; // eax
  _DWORD *v4; // esi
  int v5; // ecx
  _DWORD v6[4]; // [esp+54h] [ebp-258h] BYREF
  _BYTE v7[64]; // [esp+64h] [ebp-248h] BYREF
  _BYTE v8[64]; // [esp+A4h] [ebp-208h] BYREF
  _BYTE v9[64]; // [esp+E4h] [ebp-1C8h] BYREF
  _BYTE v10[64]; // [esp+124h] [ebp-188h] BYREF
  _BYTE v11[64]; // [esp+164h] [ebp-148h] BYREF
  _BYTE v12[64]; // [esp+1A4h] [ebp-108h] BYREF
  _BYTE v13[64]; // [esp+1E4h] [ebp-C8h] BYREF
  _BYTE v14[64]; // [esp+224h] [ebp-88h] BYREF
  _BYTE v15[68]; // [esp+264h] [ebp-48h] BYREF

  D3DXMatrixTranslation(v7, 0.0, 0.0, *(float *)(this + 444));
  D3DXMatrixScaling(v14, *(float *)(this + 444), *(float *)(this + 444), *(float *)(this + 444));
  D3DXMatrixRotationYawPitchRoll(v12, 0.0, LODWORD(flt_4D6388), 0.0);
  D3DXMatrixMultiply(v10, v12, v14);
  qmemcpy(v8, v10, sizeof(v8));
  D3DXMatrixMultiply(v9, v8, v7);
  qmemcpy(v11, v9, sizeof(v11));
  D3DXMatrixMultiply(v13, v11, this + 104);
  qmemcpy(v15, v13, 0x40u);
  v2 = (float *)sub_4151B0((float *)this, v6);
  sub_44F2A0(v2, (int)v15, dword_4D8040, dword_4D7FA0, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4);
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
