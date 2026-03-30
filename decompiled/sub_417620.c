void __thiscall sub_417620(int this)
{
  int v2; // ebx
  double v3; // st7
  bool v4; // c0
  bool v5; // c3
  double v6; // st7
  double v7; // st7
  int v8; // esi
  void *v9; // esi
  void *v10; // eax
  int v11; // esi
  double v12; // st7
  bool v13; // c0
  bool v14; // c3
  double v15; // st7
  double v16; // st7
  float v18; // [esp+8h] [ebp-88h]
  float v19; // [esp+24h] [ebp-6Ch]
  float v20; // [esp+24h] [ebp-6Ch]
  float v21; // [esp+24h] [ebp-6Ch]
  float v22; // [esp+28h] [ebp-68h]
  float v23; // [esp+28h] [ebp-68h]
  float v24; // [esp+28h] [ebp-68h]
  float v25; // [esp+28h] [ebp-68h]
  float v26; // [esp+30h] [ebp-60h]
  float v27; // [esp+30h] [ebp-60h]
  float v28; // [esp+30h] [ebp-60h]
  float v29[3]; // [esp+34h] [ebp-5Ch] BYREF
  int v30[20]; // [esp+40h] [ebp-50h] BYREF

  sub_414E10(this);
  v2 = *(_DWORD *)(this + 180);
  if ( *(_DWORD *)(v2 + 172) == 1 )
    *(_DWORD *)(this + 520) = (int)(*(float *)(this + 444) * 2.5 + 1.0);
  v3 = *(float *)(this + 432);
  v4 = *(float *)flt_4D862C < v3;
  v5 = *(float *)flt_4D862C == v3;
  v6 = *(float *)(this + 456);
  if ( v4 || v5 )
    v7 = v6 + 0.001000000047497451;
  else
    v7 = v6 - 0.001000000047497451;
  *(float *)(this + 456) = v7;
  if ( *(float *)(this + 456) >= 0.0 )
  {
    if ( *(float *)(this + 456) > 1.0 )
      *(float *)(this + 456) = 1.0;
  }
  else
  {
    *(float *)(this + 456) = 0.0;
  }
  if ( *(float *)(this + 456) > 0.0 )
  {
    if ( *(_DWORD *)(this + 520) && *(float *)flt_4D862C <= (double)*(float *)(this + 432) )
    {
      v19 = *(float *)(this + 432) * 0.03999999910593033 / *(float *)flt_4D8630;
      if ( v19 >= 0.0 )
      {
        if ( v19 > 0.039999999 )
          v19 = 0.039999999;
      }
      else
      {
        v19 = 0.0;
      }
      if ( v19 > (double)rand() / 32767.0 )
      {
        *(float *)(this + 436) = *(float *)(this + 436) + *(float *)flt_4D862C;
        v20 = (double)rand() / 32767.0 * 6.283185482025146 - 3.141592741012573;
        v22 = (double)rand() / 32767.0 * (0.0 - -0.800000011920929) - 0.800000011920929;
        v29[0] = 0.0;
        v29[1] = v22;
        v29[2] = -v20;
        v9 = operator new(0x220u);
        v30[19] = 0;
        if ( v9 )
        {
          v23 = (double)rand() / 32767.0 * 0.1000000014901161 - 0.05000000074505806 + v20;
          v18 = v23;
          v24 = *(float *)(this + 444) * 0.75;
          v10 = sub_4158D0(v30, v24, 1.0, v18);
          v11 = sub_4159C0(v10, *(_DWORD *)(this + 180), (int)v9, (int)v29);
        }
        else
        {
          v11 = 0;
        }
        ++*(_DWORD *)(this + 480);
        v12 = *(float *)(this + 432);
        v13 = *(float *)flt_4D8630 < v12;
        v14 = *(float *)flt_4D8630 == v12;
        v15 = *(float *)flt_4D8630;
        if ( !v13 && !v14 )
          v15 = *(float *)(this + 432);
        v21 = v15;
        v25 = *(float *)(v2 + 432);
        v26 = *(float *)(this + 428) * v25 / *(float *)(this + 432);
        v27 = ((double)rand() / 32767.0 * 0.699999988079071 + 0.300000011920929) * v26 * (v21 / v25);
        v16 = v27;
        v28 = *(float *)(this + 428) - v27;
        *(float *)(this + 428) = v28;
        *(float *)(this + 512) = v28 / *(float *)(v2 + 428);
        *(float *)(v11 + 428) = v16;
        *(float *)(v11 + 424) = *(float *)(this + 424);
        if ( (*(_DWORD *)(this + 520))-- == 1 )
        {
          *(float *)(this + 512) = 0.0;
          *(float *)(this + 428) = 0.0;
        }
      }
    }
  }
  else
  {
    v8 = *(_DWORD *)(this + 180);
    if ( v8 )
      sub_450C80((_DWORD *)this, v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)this + 8))(this);
  }
}
