void __usercall sub_43FAD0(float *a1@<ecx>, float *a2@<esi>, float *a3)
{
  float v3; // [esp+10h] [ebp-50h]
  float v4; // [esp+14h] [ebp-4Ch]
  _BYTE v5[48]; // [esp+18h] [ebp-48h] BYREF
  float v6; // [esp+48h] [ebp-18h]
  float v7; // [esp+4Ch] [ebp-14h]
  float v8; // [esp+50h] [ebp-10h]

  v4 = *a3;
  v3 = a3[1];
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))D3DXMatrixScaling)(v5, *a1, a1[1], 0.0);
  v6 = v6 + v4;
  v7 = v7 + v3;
  v8 = v8 + 0.0;
  sub_4504E0(dword_4D8040[0], dword_4D7FA0, (int)v5, a2, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4);
  sub_4504E0(dword_4D8040[0], dword_4D7FA0, (int)v5, a2, dword_4D7FA8, dword_4D7FA4, dword_4D7FB0, dword_4D7FB4);
}
