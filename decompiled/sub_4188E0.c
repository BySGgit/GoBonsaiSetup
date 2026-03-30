void __usercall sub_4188E0(int a1@<esi>)
{
  void *v1; // edi
  void *v2; // eax
  int v3; // edi
  double v4; // st7
  double v5; // st7
  int v6; // eax
  _DWORD *v7; // ecx
  double v8; // st7
  _DWORD *v9; // eax
  int v10; // edx
  float v11; // [esp+4h] [ebp-84h]
  float v12; // [esp+8h] [ebp-80h]
  float v13; // [esp+20h] [ebp-68h]
  float v14; // [esp+20h] [ebp-68h]
  float v15; // [esp+20h] [ebp-68h]
  float v16; // [esp+20h] [ebp-68h]
  float v17; // [esp+20h] [ebp-68h]
  float i; // [esp+20h] [ebp-68h]
  float v19; // [esp+24h] [ebp-64h]
  float v20; // [esp+24h] [ebp-64h]
  float v21; // [esp+24h] [ebp-64h]
  float v22; // [esp+24h] [ebp-64h]
  float v23; // [esp+24h] [ebp-64h]
  float v24; // [esp+24h] [ebp-64h]
  float v25; // [esp+24h] [ebp-64h]
  float v26[3]; // [esp+2Ch] [ebp-5Ch] BYREF
  int v27[20]; // [esp+38h] [ebp-50h] BYREF

  v13 = *(float *)(a1 + 432) - *(float *)(a1 + 436);
  if ( *(float *)flt_4D862C <= (double)v13 )
  {
    v14 = v13 / *(float *)flt_4D8630 * 0.0003000000142492354;
    if ( v14 >= 0.0 )
    {
      if ( v14 > 0.003 )
        v14 = 0.003;
    }
    else
    {
      v14 = 0.0;
    }
    if ( v14 > (double)rand() / 32767.0 )
    {
      v15 = (double)rand() / 32767.0 * 6.283185482025146 - 3.141592741012573;
      v19 = (double)rand() / 32767.0 * 1.100000023841858 - 1.600000023841858;
      v26[0] = 0.0;
      v26[1] = v19;
      v26[2] = -v15;
      v1 = operator new(0x220u);
      v27[19] = 0;
      if ( v1 )
      {
        v20 = (double)rand() / 32767.0 * 0.1000000014901161 - 0.05000000074505806 + v15;
        v12 = v20;
        v21 = (double)rand() / 32767.0;
        v11 = v21;
        v22 = *(float *)(a1 + 444) * 0.8500000238418579;
        v2 = sub_4158D0(v27, v22, v11, v12);
        v3 = sub_4159C0(v2, a1, (int)v1, (int)v26);
      }
      else
      {
        v3 = 0;
      }
      v4 = *(float *)(a1 + 432);
      ++*(_DWORD *)(a1 + 480);
      v16 = v4 - *(float *)(a1 + 436);
      v5 = v16;
      if ( *(float *)flt_4D8630 <= (double)v16 )
        v5 = *(float *)flt_4D8630;
      v17 = v5;
      v6 = rand();
      v7 = *(_DWORD **)(a1 + 168);
      v23 = *(float *)flt_4D862C + (v17 - *(float *)flt_4D862C) * ((double)v6 / 32767.0);
      v8 = v23;
      *(float *)(a1 + 436) = v23 + *(float *)(a1 + 436);
      v9 = (_DWORD *)*v7;
      for ( i = 0.0; v9 != v7; i = *(float *)(v10 + 428) + i )
      {
        v10 = v9[2];
        v9 = (_DWORD *)*v9;
      }
      v24 = 1.0;
      if ( i > 0.0 )
      {
        v25 = v8 / *(float *)(a1 + 432);
        v24 = i * v25 / (1.0 - v25);
      }
      *(float *)(v3 + 428) = v24;
      *(float *)(v3 + 424) = v24;
    }
  }
}
