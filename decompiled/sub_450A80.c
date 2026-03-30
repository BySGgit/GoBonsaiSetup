int __usercall sub_450A80@<eax>(int a1@<eax>, int a2@<edi>)
{
  double v3; // st7
  double v4; // st6
  float *v6; // eax
  double v7; // st7
  float *v8; // [esp+0h] [ebp-34h]
  float v9; // [esp+0h] [ebp-34h]
  float v10; // [esp+8h] [ebp-2Ch]
  float v11; // [esp+8h] [ebp-2Ch]
  float v12; // [esp+8h] [ebp-2Ch]
  float v13; // [esp+8h] [ebp-2Ch]
  double v14; // [esp+Ch] [ebp-28h] BYREF
  float v15; // [esp+14h] [ebp-20h]
  float v16[3]; // [esp+1Ch] [ebp-18h] BYREF
  float v17[3]; // [esp+28h] [ebp-Ch] BYREF

  sub_401430((float *)&v14, (float *)a1, v8);
  v10 = *((float *)&v14 + 1) * *((float *)&v14 + 1) + *(float *)&v14 * *(float *)&v14 + v15 * v15;
  v11 = sqrt(v10);
  v3 = v11;
  if ( *(float *)(a2 + 12) >= *(float *)(a1 + 12) + v11 )
    return a2;
  v4 = v3 + *(float *)(a2 + 12);
  if ( *(float *)(a1 + 12) >= v4 )
  {
    *(_DWORD *)a2 = *(_DWORD *)a1;
    *(_DWORD *)(a2 + 4) = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a1 + 12);
    return a2;
  }
  v12 = v4 + *(float *)(a1 + 12);
  v9 = v3;
  sub_408450((float *)&v14, v16, v9);
  v14 = v12 * 0.5;
  v13 = v14 - *(float *)(a2 + 12);
  v6 = sub_401470(v17, v16, v13);
  *(float *)a2 = *(float *)a2 - *v6;
  *(float *)(a2 + 4) = *(float *)(a2 + 4) - v6[1];
  v7 = *(float *)(a2 + 8) - v6[2];
  *(float *)(a2 + 8) = v7;
  *(float *)(a2 + 12) = v14;
  return a2;
}
