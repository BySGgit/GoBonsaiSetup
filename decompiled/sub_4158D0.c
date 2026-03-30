void *__cdecl sub_4158D0(void *a1, float a2, float a3, float a4)
{
  _BYTE v5[64]; // [esp+2Ch] [ebp-CCh] BYREF
  _BYTE v6[64]; // [esp+6Ch] [ebp-8Ch] BYREF
  _BYTE v7[68]; // [esp+ACh] [ebp-4Ch] BYREF

  D3DXMatrixTranslation(v5, 0.0, LODWORD(a2), LODWORD(a3));
  D3DXMatrixRotationYawPitchRoll(v6, 0.0, 0.0, LODWORD(a4));
  D3DXMatrixMultiply(v7, v5, v6);
  qmemcpy(a1, v7, 0x40u);
  return a1;
}
