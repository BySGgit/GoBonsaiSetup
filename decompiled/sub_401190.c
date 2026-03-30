float *__userpurge sub_401190@<eax>(float *a1@<edi>, int a2)
{
  double v2; // st6
  float v4; // [esp+8h] [ebp-28h]
  float v5; // [esp+8h] [ebp-28h]
  float v6; // [esp+8h] [ebp-28h]
  float v7; // [esp+8h] [ebp-28h]
  float v8; // [esp+8h] [ebp-28h]
  float v9; // [esp+Ch] [ebp-24h]
  float v10; // [esp+10h] [ebp-20h]
  float v11[3]; // [esp+14h] [ebp-1Ch] BYREF
  float v12; // [esp+20h] [ebp-10h] BYREF
  float v13; // [esp+24h] [ebp-Ch]
  float v14; // [esp+28h] [ebp-8h]

  sub_401070(a2, (int)&v12);
  v4 = flt_4D538C * v12 + flt_4D5390 * v13 + flt_4D5394 * v14;
  if ( v4 <= 1.0 )
  {
    if ( v4 < -1.0 )
      v4 = -1.0;
  }
  else
  {
    v4 = 1.0;
  }
  v5 = acos(v4);
  v9 = v5 - 1.570796370506287;
  v13 = 0.0;
  D3DXVec3Normalize(&v12, &v12);
  v6 = flt_4D5398 * v12 + flt_4D539C * v13 + flt_4D53A0 * v14;
  if ( v6 <= 1.0 )
  {
    if ( v6 < -1.0 )
      v6 = -1.0;
  }
  else
  {
    v6 = 1.0;
  }
  v7 = acos(v6);
  v10 = v7;
  if ( sub_401180(&flt_4D5398, &v12, v11)[1] <= 0.0 )
    v2 = -1.0;
  else
    v2 = 1.0;
  v8 = v2;
  *a1 = v8 * v10;
  a1[1] = v9;
  a1[2] = 0.0;
  return a1;
}
