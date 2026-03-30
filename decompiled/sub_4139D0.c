int sub_4139D0()
{
  float *v0; // eax
  int v1; // esi
  int v2; // ebx
  float *v3; // eax
  float *v4; // edi
  float *v5; // eax
  float *v6; // edi
  float *v7; // eax
  float v8; // ecx
  double v9; // st7
  float v10; // edx
  float v11; // eax
  float v12; // ecx
  float v13; // edx
  double v14; // st7
  int *i; // [esp+14h] [ebp-1ACh]
  int v17; // [esp+18h] [ebp-1A8h]
  int v18; // [esp+1Ch] [ebp-1A4h]
  double v19[2]; // [esp+20h] [ebp-1A0h] BYREF
  float v20[6]; // [esp+34h] [ebp-18Ch] BYREF
  float v21[6]; // [esp+4Ch] [ebp-174h] BYREF
  float v22[3]; // [esp+64h] [ebp-15Ch] BYREF
  float v23[3]; // [esp+70h] [ebp-150h] BYREF
  float v24[3]; // [esp+7Ch] [ebp-144h] BYREF
  float v25[3]; // [esp+88h] [ebp-138h] BYREF
  float v26[3]; // [esp+94h] [ebp-12Ch] BYREF
  float v27[3]; // [esp+A0h] [ebp-120h] BYREF
  float v28[3]; // [esp+ACh] [ebp-114h] BYREF
  int v29[61]; // [esp+B8h] [ebp-108h] BYREF
  int v30; // [esp+1BCh] [ebp-4h]

  sub_4015F0(v27, (float *)(dword_4D7EEC + 104));
  v0 = sub_401500((float *)v19, &flt_4D8DFC, 100000.0);
  sub_4013F0(v28, v0, v27);
  v21[0] = v27[0];
  v21[1] = v27[1];
  v21[2] = v27[2];
  v21[3] = v28[0];
  v21[4] = v28[1];
  v21[5] = v28[2];
  v1 = sub_450E30(0, v29, v27, v28, 20);
  v18 = v1;
  v17 = 0;
  if ( v1 <= 0 )
    return 0;
  for ( i = v29; ; i += 3 )
  {
    v2 = *i;
    if ( !*i )
      goto LABEL_9;
    if ( (dword_4D8CE0 & 1) == 0 )
    {
      dword_4D8CE0 |= 1u;
      v30 = 0;
      sub_40FBA0();
      v30 = -1;
    }
    if ( !byte_4D822A[11 * *(_DWORD *)(v2 + 4)] )
      goto LABEL_9;
    v3 = sub_40A310(v2, v22);
    v4 = sub_401500(v24, v3, *(float *)(v2 + 448));
    v5 = sub_40D6C0(v2, v25);
    v6 = sub_4013F0(v26, v4, v5);
    v7 = sub_40D6C0(v2, v23);
    v8 = *v7;
    v9 = *(float *)(v2 + 444) + 0.1500000059604645;
    v10 = v7[1];
    v20[2] = v7[2];
    *(float *)v19 = v9;
    v11 = v6[2];
    v20[0] = v8;
    v19[0] = *(float *)v19;
    v12 = *v6;
    v20[1] = v10;
    v13 = v6[1];
    v20[5] = v11;
    v20[3] = v12;
    v20[4] = v13;
    v14 = sub_44EE20(v21, v20);
    if ( v19[0] * v19[0] > v14 )
      break;
    v1 = v18;
LABEL_9:
    if ( ++v17 >= v1 )
      return 0;
  }
  return v2;
}
