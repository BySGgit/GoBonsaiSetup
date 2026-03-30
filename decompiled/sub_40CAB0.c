int __usercall sub_40CAB0@<eax>(float *a1@<esi>)
{
  double v1; // st7
  float v3; // [esp+14h] [ebp-A0h]
  float v4; // [esp+1Ch] [ebp-98h]
  float v5; // [esp+20h] [ebp-94h]
  float v6; // [esp+20h] [ebp-94h]
  float v7; // [esp+20h] [ebp-94h]
  float v8; // [esp+24h] [ebp-90h]
  _BYTE v9[64]; // [esp+28h] [ebp-8Ch] BYREF
  _BYTE v10[68]; // [esp+68h] [ebp-4Ch] BYREF

  v5 = a1[111];
  v8 = 1.0;
  if ( a1[110] < 0.02500000037252903 )
    v8 = 0.02500000037252903 * (a1[110] + a1[110]) - 1.0;
  if ( a1[114] < 1.0 )
    v8 = (1.0 - a1[114]) * 0.5 + v8;
  v1 = v5;
  v4 = v5;
  v6 = v8 * v5;
  v3 = v1;
  D3DXMatrixScaling(v9, LODWORD(v3), LODWORD(v6), LODWORD(v4));
  D3DXMatrixMultiply(v10, v9, a1 + 26);
  v7 = sub_415020((int)a1);
  return sub_40AC70(a1 + 128, (int)v10, v7);
}
