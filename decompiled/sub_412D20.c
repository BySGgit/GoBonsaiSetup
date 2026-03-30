void sub_412D20()
{
  int v0; // eax
  float *v1; // esi
  float *v2; // eax
  int *v3; // eax
  float *v4; // edi
  double v5; // [esp+10h] [ebp-68h]
  float v6; // [esp+10h] [ebp-68h]
  float v7; // [esp+10h] [ebp-68h]
  float v8; // [esp+10h] [ebp-68h]
  float v9; // [esp+10h] [ebp-68h]
  float v10; // [esp+10h] [ebp-68h]
  float v11; // [esp+10h] [ebp-68h]
  float v12; // [esp+10h] [ebp-68h]
  float v13; // [esp+10h] [ebp-68h]
  float v14; // [esp+10h] [ebp-68h]
  float v15; // [esp+10h] [ebp-68h]
  float v16; // [esp+10h] [ebp-68h]
  float v17; // [esp+1Ch] [ebp-5Ch]
  float v18; // [esp+20h] [ebp-58h]
  float v19; // [esp+20h] [ebp-58h]
  float v20[3]; // [esp+24h] [ebp-54h] BYREF
  float v21[3]; // [esp+30h] [ebp-48h] BYREF
  float v22[3]; // [esp+3Ch] [ebp-3Ch] BYREF
  void *v23[7]; // [esp+48h] [ebp-30h] BYREF
  int v24; // [esp+74h] [ebp-4h]

  if ( 0.0 == flt_4D526C || dword_4D8C14 > dword_4D52DC )
  {
    v4 = (float *)&dword_4D82D4;
  }
  else
  {
    if ( (dword_4DBCC0 & 1) == 0 )
    {
      dword_4DBCC0 |= 1u;
      dword_4DBCB4 = dword_4D8A68;
      dword_4DBCB8 = dword_4D8A6C;
      dword_4DBCBC = dword_4D8A70;
      atexit(nullsub_4);
    }
    if ( (double)rand() / 32767.0 < 0.004999999888241291 || byte_4D6330 )
    {
      v5 = (double)rand() / 32767.0 * 0.5 + 0.5;
      v18 = (double)(rand() % 2 != 0 ? 1 : -1) * v5;
      *(float *)&v5 = (double)rand() / 32767.0 * 0.2000000029802322 - 0.1000000014901161;
      v0 = rand();
      byte_4D6330 = 0;
      v17 = (double)v0 / 32767.0 * 0.2000000029802322 - 0.1000000014901161;
      v20[0] = v18;
      dword_4DBCB4 = LODWORD(v18);
      v20[1] = *(float *)&v5;
      dword_4DBCB8 = LODWORD(v5);
      v20[2] = v17;
      dword_4DBCBC = LODWORD(v17);
    }
    v1 = sub_401500(v20, (float *)&dword_4D8A68, 0.99000001);
    v2 = sub_401500(v22, (float *)&dword_4DBCB4, 0.0099999998);
    v3 = (int *)sub_4013F0(v21, v1, v2);
    dword_4D8A68 = *v3;
    dword_4D8A6C = v3[1];
    dword_4D8A70 = v3[2];
    v6 = *(float *)&dword_4D8A6C * *(float *)&dword_4D8A6C
       + *(float *)&dword_4D8A68 * *(float *)&dword_4D8A68
       + *(float *)&dword_4D8A70 * *(float *)&dword_4D8A70;
    v7 = sqrt(v6);
    flt_4D8D10 = v7 * 0.2000000029802322 + flt_4D8D10;
    v8 = sin(flt_4D8D10);
    v19 = v8 * 0.300000011920929 + 0.699999988079071;
    v9 = *(float *)(dword_4D7EE8 + 216) / 365.0;
    v10 = v9 - (double)(int)v9;
    v11 = flt_4D7EF8 / 365.0 + v10;
    v12 = v11 * 3.141592741012573 + v11 * 3.141592741012573 + 4.5;
    v13 = cos(v12);
    v14 = 1.0 - (v13 + 1.0) * 0.5;
    v15 = v14 * 0.5 + 0.5;
    if ( (dword_4DBCC0 & 2) == 0 )
    {
      dword_4DBCC0 |= 2u;
      v24 = 0;
      sub_4033D0(L"windStrengthMax", (int)v23);
      LOBYTE(v24) = 1;
      sub_408600(v23, (int)&unk_4DBC90, (int)&flt_4D8D14);
      if ( v23[5] >= (void *)8 )
        operator delete(v23[0]);
      atexit(sub_4723C0);
    }
    v16 = v15 * v19 * flt_4D8D14;
    v4 = sub_401500(v21, (float *)&dword_4D8A68, v16);
  }
  sub_40D1A0((int)v4);
}
