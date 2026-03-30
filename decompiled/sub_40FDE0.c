float *__usercall sub_40FDE0@<eax>(int a1@<eax>, float *a2@<esi>, int a3, float a4)
{
  int v5; // ebx
  double v6; // st7
  bool v7; // c3
  double v8; // st7
  int v9; // edx
  float *v10; // eax
  int v11; // ecx
  int v12; // edx
  int v14; // eax
  float *v15; // ecx
  double v16; // st7
  double v17; // st6
  double v18; // st7
  float v19; // [esp+Ch] [ebp-14h]
  float v20; // [esp+Ch] [ebp-14h]
  int v21; // [esp+Ch] [ebp-14h]
  float v22; // [esp+Ch] [ebp-14h]
  float v23; // [esp+10h] [ebp-10h]
  float v24; // [esp+14h] [ebp-Ch]
  float v25; // [esp+18h] [ebp-8h]
  float v26; // [esp+1Ch] [ebp-4h]

  v5 = a1 - 1;
  v19 = (float)(a1 - 1);
  v6 = v19;
  v20 = v19 * a4;
  v7 = v20 == v6;
  v8 = v20;
  if ( v7 )
  {
    v9 = *(_DWORD *)(a3 + 16 * a1 - 12);
    v10 = (float *)(a3 + 16 * a1 - 16);
    *a2 = *v10;
    v11 = *((_DWORD *)v10 + 2);
    *((_DWORD *)a2 + 1) = v9;
    v12 = *((_DWORD *)v10 + 3);
    *((_DWORD *)a2 + 2) = v11;
    *((_DWORD *)a2 + 3) = v12;
    return a2;
  }
  else
  {
    v14 = (int)v8;
    v21 = (int)v8;
    if ( (int)v8 >= v5 )
    {
      v14 = a1 - 2;
      v21 = a1 - 2;
    }
    v15 = (float *)(a3 + 16 * v14);
    v22 = v8 - (double)v21;
    if ( v22 >= 0.0 )
    {
      v16 = v22;
      if ( v22 > 1.0 )
        v16 = (float)1.0;
    }
    else
    {
      v16 = (float)0.0;
    }
    v23 = (v15[4] - *v15) * v16 + *v15;
    v17 = v15[5];
    *a2 = v23;
    v24 = (v17 - v15[1]) * v16 + v15[1];
    v25 = (v15[6] - v15[2]) * v16 + v15[2];
    v18 = v16 * (v15[7] - v15[3]) + v15[3];
    a2[1] = v24;
    a2[2] = v25;
    v26 = v18;
    a2[3] = v26;
    return a2;
  }
}
