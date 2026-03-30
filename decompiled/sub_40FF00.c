float *__usercall sub_40FF00@<eax>(float *a1@<edx>, float *a2@<ecx>, float *a3@<esi>)
{
  double v3; // st5
  double v4; // st6
  double v5; // st7
  float v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]
  float v10; // [esp+8h] [ebp-4h]
  float v11; // [esp+8h] [ebp-4h]
  float v12; // [esp+8h] [ebp-4h]

  v9 = *a3 * *a2;
  v3 = 1.0;
  if ( v9 >= 0.0 )
  {
    if ( v9 <= 1.0 )
      v3 = v9;
    v7 = v3;
    v4 = 0.0;
    v5 = 1.0;
  }
  else
  {
    v4 = 0.0;
    v5 = 1.0;
    v7 = 0.0;
  }
  v10 = a2[1] * *a3;
  if ( v10 >= v4 )
  {
    if ( v10 <= v5 )
      v8 = a2[1] * *a3;
    else
      v8 = v5;
  }
  else
  {
    v8 = v4;
  }
  v11 = a2[2] * *a3;
  if ( v11 < v4 || (v4 = v11, v11 <= v5) )
    v5 = v4;
  v12 = v5;
  *a1 = v7;
  a1[1] = v8;
  a1[2] = v12;
  a1[3] = a2[3];
  return a1;
}
