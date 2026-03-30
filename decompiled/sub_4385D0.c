int __usercall sub_4385D0@<eax>(_DWORD *a1@<eax>, _DWORD *a2@<ecx>)
{
  int v3; // eax
  int v4; // eax
  _DWORD *v5; // ecx
  int v6; // edi
  int v7; // eax
  int v8; // edi
  int v9; // eax
  unsigned int v10; // edi
  int result; // eax
  int v12; // edx

  *a2 = *a1;
  v3 = a1[1];
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      a2[1] = 2;
    }
    else if ( v3 == 2 )
    {
      a2[1] = 4;
    }
  }
  else
  {
    a2[1] = 1;
  }
  v4 = sub_4388E0(a1[7]);
  v6 = a1[3];
  v5[2] = v4;
  v5[6] = v4;
  v5[7] = a1[13];
  v5[8] = a1[10];
  v7 = a1[11];
  v5[4] = v6;
  v8 = a1[4];
  v5[9] = v7;
  v9 = a1[14];
  v5[5] = v8;
  v10 = a1[6];
  v5[11] = v9;
  result = a1[15];
  v5[3] = 64;
  v5[10] = v12;
  v5[12] = result;
  v5[13] = v12;
  v5[14] = 83;
  v5[15] = 0;
  if ( v10 )
  {
    result = a1[5] / v10;
    v5[16] = result;
  }
  else
  {
    v5[16] = 60;
  }
  switch ( a1[19] )
  {
    case 0:
      v5[17] = 0x80000000;
      break;
    case 2:
      v5[17] = 2;
      break;
    case 3:
      v5[17] = 4;
      break;
    case 4:
      v5[17] = 8;
      break;
    default:
      v5[17] = 0;
      break;
  }
  return result;
}
