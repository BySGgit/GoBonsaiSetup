int __usercall sub_401690@<eax>(float *a1@<edi>, int a2@<esi>)
{
  float *v2; // eax
  float *v3; // eax
  float *v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  float v9; // [esp+4h] [ebp-28h]
  float v10; // [esp+4h] [ebp-28h]
  float v11[3]; // [esp+8h] [ebp-24h] BYREF
  float v12[3]; // [esp+14h] [ebp-18h] BYREF
  float v13[3]; // [esp+20h] [ebp-Ch] BYREF

  sub_401430(v11, a1, a1 + 3);
  v2 = sub_4014B0(v12, v11, 2.0);
  v9 = v2[1] * v2[1] + *v2 * *v2 + v2[2] * v2[2];
  v3 = sub_4014B0(v13, v11, 2.0);
  v4 = sub_4013F0(v11, v3, a1);
  v5 = *(_DWORD *)v4;
  v6 = *((_DWORD *)v4 + 1);
  v7 = *((_DWORD *)v4 + 2);
  *(_DWORD *)a2 = v5;
  *(_DWORD *)(a2 + 4) = v6;
  *(_DWORD *)(a2 + 8) = v7;
  v10 = sqrt(v9);
  *(float *)(a2 + 12) = v10;
  return a2;
}
