int __fastcall sub_4386C0(_DWORD *a1, _DWORD *a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // edx
  _DWORD *v6; // ecx
  int v7; // eax
  int result; // eax
  unsigned int v9; // edx

  *a1 = *a2;
  v2 = a2[1];
  switch ( v2 )
  {
    case 1:
      a1[1] = 0;
      break;
    case 2:
      a1[1] = 1;
      break;
    case 4:
      a1[1] = 2;
      break;
  }
  a1[3] = a2[4];
  a1[4] = a2[5];
  a1[5] = a2[16];
  v3 = a2[6];
  a1[2] = 0;
  a1[6] = 1;
  v4 = sub_4387B0(v3);
  v6[7] = v4;
  v7 = v5[8];
  if ( v7 == 1 )
  {
    v6[10] = v5[9];
    v6[11] = 0;
  }
  else
  {
    v6[10] = v7;
    v6[11] = v5[9];
  }
  v6[13] = v5[7];
  v6[14] = v5[11];
  result = v5[12];
  v9 = v5[17];
  v6[12] = 32;
  v6[15] = result;
  v6[18] = 0;
  if ( v9 > 4 )
  {
    if ( v9 == 8 )
    {
      v6[20] = 0;
      v6[19] = 4;
    }
    else
    {
      if ( v9 != 0x80000000 )
      {
LABEL_14:
        v6[19] = 1;
        v6[20] = 0;
        return result;
      }
      v6[19] = 0;
      v6[20] = 0;
    }
  }
  else
  {
    if ( v9 != 4 )
    {
      if ( v9 == 2 )
      {
        v6[20] = 0;
        v6[19] = 2;
        return result;
      }
      goto LABEL_14;
    }
    v6[20] = 0;
    v6[19] = 3;
  }
  return result;
}
