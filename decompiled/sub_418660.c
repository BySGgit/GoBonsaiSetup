void __usercall sub_418660(int a1@<esi>)
{
  void *v1; // edi
  void *v2; // eax
  double v3; // st7
  void *v4; // edi
  void *v5; // eax
  int v6; // edi
  float v7; // [esp+1Ch] [ebp-ACh]
  float v8; // [esp+1Ch] [ebp-ACh]
  float v9; // [esp+1Ch] [ebp-ACh]
  float v10; // [esp+1Ch] [ebp-ACh]
  float v11; // [esp+20h] [ebp-A8h]
  float v12; // [esp+20h] [ebp-A8h]
  float v13; // [esp+24h] [ebp-A4h] BYREF
  float v14; // [esp+28h] [ebp-A0h]
  float v15; // [esp+2Ch] [ebp-9Ch]
  void *v16; // [esp+30h] [ebp-98h]
  float v17; // [esp+34h] [ebp-94h]
  int v18[16]; // [esp+38h] [ebp-90h] BYREF
  int v19[17]; // [esp+78h] [ebp-50h] BYREF
  int v20; // [esp+C4h] [ebp-4h]

  v11 = (double)rand() / 32767.0 * 6.283185482025146 - 3.141592741012573;
  v7 = (0.300000011920929 - 0.0) * ((double)rand() / 32767.0) + 0.0;
  v13 = 0.0;
  v14 = v7;
  v15 = -v11;
  v17 = v7 / 0.300000011920929;
  v1 = operator new(0x220u);
  v16 = v1;
  v20 = 0;
  if ( v1 )
  {
    v8 = (double)rand() / 32767.0 * 0.1000000014901161 - 0.05000000074505806 + v11;
    v2 = sub_4158D0(v18, 0.0, 1.0, v8);
    sub_4159C0(v2, a1, (int)v1, (int)&v13);
  }
  v20 = -1;
  v3 = *(float *)(a1 + 432);
  ++*(_DWORD *)(a1 + 480);
  if ( *(float *)flt_4D862C < v3 && (double)rand() / 32767.0 < 0.2000000029802322 )
  {
    v12 = v11 + 3.141592741012573;
    v9 = (double)rand() / 32767.0 * 0.8999999463558197 + 0.4000000059604645;
    v13 = 0.0;
    v14 = v9;
    v15 = -v12;
    v4 = operator new(0x220u);
    v16 = v4;
    v20 = 1;
    if ( v4 )
    {
      v10 = (double)rand() / 32767.0 * 0.1000000014901161 - 0.05000000074505806 + v12;
      v5 = sub_4158D0(v19, 0.0, 1.0, v10);
      v6 = sub_4159C0(v5, a1, (int)v4, (int)&v13);
    }
    else
    {
      v6 = 0;
    }
    ++*(_DWORD *)(a1 + 480);
    *(float *)(v6 + 428) = ((double)rand() / 32767.0 * 0.1000000238418579 + 0.8999999761581421) * v17;
  }
}
