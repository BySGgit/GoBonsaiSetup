_DWORD *__usercall sub_4151B0@<eax>(float *a1@<ecx>, _DWORD *a2@<esi>)
{
  double v2; // st7
  double v3; // st6
  float *v4; // eax
  float v6; // [esp+8h] [ebp-14h]
  float v7; // [esp+8h] [ebp-14h]
  float v8; // [esp+8h] [ebp-14h]
  float v9; // [esp+8h] [ebp-14h]
  float v10; // [esp+8h] [ebp-14h]
  float v11; // [esp+8h] [ebp-14h]
  float v12; // [esp+8h] [ebp-14h]
  float v13[4]; // [esp+Ch] [ebp-10h] BYREF

  if ( dword_4D8644 != 2 )
  {
    switch ( dword_4D8644 )
    {
      case 3:
        v10 = a1[108] / 20.0;
        if ( v10 >= 0.0 )
        {
          if ( v10 > 1.0 )
            v10 = 1.0;
        }
        else
        {
          v10 = 0.0;
        }
        break;
      case 4:
        v10 = a1[109] / 20.0;
        if ( v10 >= 0.0 )
        {
          if ( v10 > 1.0 )
            v10 = 1.0;
        }
        else
        {
          v10 = 0.0;
        }
        break;
      case 5:
        v9 = a1[114];
        v2 = 0.0;
        v3 = v9;
        if ( v9 < 0.0 )
          goto LABEL_26;
        goto LABEL_7;
      default:
        return a2;
    }
    v11 = 1.0 - v10;
    v12 = pow(v11, 6.0);
    v9 = 1.0 - v12;
    v2 = 0.0;
    if ( v9 >= 0.0 )
    {
      if ( v9 > 1.0 )
        v9 = 1.0;
      goto LABEL_8;
    }
    goto LABEL_26;
  }
  v6 = a1[105] / 20.0;
  if ( v6 >= 0.0 )
  {
    if ( v6 > 1.0 )
      v6 = 1.0;
  }
  else
  {
    v6 = 0.0;
  }
  v7 = 1.0 - v6;
  v8 = pow(v7, 6.0);
  v9 = 1.0 - v8;
  v2 = 0.0;
  v3 = v9;
  if ( v9 < 0.0 )
    goto LABEL_26;
LABEL_7:
  v2 = 1.0;
  if ( v3 > 1.0 )
LABEL_26:
    v9 = v2;
LABEL_8:
  v4 = sub_413DF0(v13, v9);
  *a2 = *(_DWORD *)v4;
  a2[1] = *((_DWORD *)v4 + 1);
  a2[2] = *((_DWORD *)v4 + 2);
  a2[3] = *((_DWORD *)v4 + 3);
  return a2;
}
