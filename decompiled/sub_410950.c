void __thiscall sub_410950(float *this)
{
  double v1; // st6
  double v2; // st7
  double v3; // st5
  double v4; // st4
  double v5; // st5
  float *v6; // ebx
  double v7; // st7
  double v8; // st6
  double v9; // st4
  bool v10; // c0
  bool v11; // c3
  double v12; // st6
  double v13; // st4
  bool v14; // c0
  bool v15; // c3
  double v16; // st6
  double v17; // st7
  double v18; // rt2
  double v19; // st6
  float *v20; // esi
  int v21; // ebp
  float *v22; // eax
  double v23; // st7
  float *v24; // eax
  float v25; // [esp+14h] [ebp-40h]
  float v26; // [esp+18h] [ebp-3Ch]
  float v27; // [esp+18h] [ebp-3Ch]
  float v28; // [esp+18h] [ebp-3Ch]
  float v29; // [esp+18h] [ebp-3Ch]
  float v30; // [esp+18h] [ebp-3Ch]
  float v31; // [esp+18h] [ebp-3Ch]
  float v32; // [esp+1Ch] [ebp-38h]
  float v33; // [esp+1Ch] [ebp-38h]
  float v34; // [esp+1Ch] [ebp-38h]
  int v35; // [esp+1Ch] [ebp-38h]
  float v36; // [esp+20h] [ebp-34h]
  float v37; // [esp+20h] [ebp-34h]
  float v38; // [esp+20h] [ebp-34h]
  float v39; // [esp+20h] [ebp-34h]
  float v40; // [esp+20h] [ebp-34h]
  float v41; // [esp+20h] [ebp-34h]
  float v42; // [esp+20h] [ebp-34h]
  float v43; // [esp+20h] [ebp-34h]
  float v44; // [esp+20h] [ebp-34h]
  float v45; // [esp+20h] [ebp-34h]
  float v46; // [esp+20h] [ebp-34h]
  float v47[3]; // [esp+24h] [ebp-30h] BYREF
  float v48[3]; // [esp+30h] [ebp-24h] BYREF
  float v49[3]; // [esp+3Ch] [ebp-18h] BYREF
  float v50[3]; // [esp+48h] [ebp-Ch] BYREF

  if ( byte_4D523E && byte_4D52D0 )
  {
    v25 = (flt_4D526C + flt_4D526C) / 50.0;
    if ( v25 >= 0.0 )
    {
      if ( v25 > 1.0 )
        v25 = 1.0;
      v1 = 0.0;
      v2 = 1.0;
    }
    else
    {
      v1 = 0.0;
      v2 = 1.0;
      v25 = 0.0;
    }
    v32 = *(float *)(dword_4D7EE8 + 216) / 365.0;
    v33 = v32 - (double)(int)v32;
    v34 = flt_4D7EF8 / 365.0 + v33;
    v3 = v34;
    *(this + 653) = v34;
    if ( *(this + 652) + 0.5 >= v34 )
    {
      v4 = 1.0;
      if ( *(this + 652) - 0.5 <= v3 )
        v5 = v3 - *(this + 652);
      else
        v5 = v3 + 1.0 - *(this + 652);
    }
    else
    {
      v4 = 1.0;
      v5 = v3 - 1.0 - *(this + 652);
    }
    *(this + 652) = v5 * 0.300000011920929 + *(this + 652);
    if ( v2 >= *(this + 652) )
    {
      if ( v1 > *(this + 652) )
        *(this + 652) = v4 + *(this + 652);
    }
    else
    {
      *(this + 652) = *(this + 652) - v4;
    }
    v6 = this + 108;
    v35 = 10;
    while ( 1 )
    {
      v26 = ((double)rand() / 32767.0 * 0.5 + 0.5) * v25 * flt_4D5270;
      sub_401500(v47, (float *)&dword_4D8A68, v26);
      *(v6 - 4) = *(v6 - 4) + v47[0];
      *(v6 - 3) = v47[1] + *(v6 - 3);
      *(v6 - 2) = v47[2] + *(v6 - 2);
      v36 = -flt_4D5278;
      v7 = v25;
      *v6 = (v36 + (flt_4D5278 - v36) * ((double)rand() / 32767.0)) * v25 + *v6;
      v37 = -flt_4D5274;
      if ( v37 <= (double)*v6 )
      {
        if ( *v6 > (double)flt_4D5274 )
          *v6 = flt_4D5274;
      }
      else
      {
        *v6 = v37;
      }
      v38 = *v6 * v7 + *(v6 - 1);
      *(v6 - 1) = v38;
      v8 = *(v6 - 4);
      v9 = -flt_4D5284;
      v10 = v9 < v8;
      v11 = v9 == v8;
      v12 = flt_4D5284;
      if ( !v10 && !v11 && v47[0] < 0.0 )
        break;
      v13 = *(v6 - 4);
      v14 = v13 < v12;
      v15 = v13 == v12;
      v16 = 0.0;
      if ( !v14 && !v15 && v47[0] > 0.0 )
        goto LABEL_30;
      v17 = 0.0;
LABEL_27:
      if ( v17 <= *(v6 - 1) )
      {
        if ( *(v6 - 1) > 1.0 )
          *(v6 - 1) = 1.0;
      }
      else
      {
        *(v6 - 1) = v17;
      }
      if ( *(v6 - 1) == v17 )
        sub_4102C0((int)(v6 - 59), 0);
      v20 = v6 - 54;
      v21 = 5;
      do
      {
        v27 = -flt_4D52AC;
        v48[0] = v27 + (flt_4D52AC - v27) * ((double)rand() / 32767.0);
        v28 = -flt_4D52AC;
        v48[1] = v28 + (flt_4D52AC - v28) * ((double)rand() / 32767.0);
        v29 = -flt_4D52AC;
        v48[2] = v29 + (flt_4D52AC - v29) * ((double)rand() / 32767.0);
        v22 = sub_401500(v49, v48, v25);
        *(v20 - 1) = *(v20 - 1) + *v22;
        *v20 = v22[1] + *v20;
        v20[1] = v22[2] + v20[1];
        v23 = flt_4D52A8;
        v39 = -flt_4D52A8;
        if ( v39 <= (double)*(v20 - 1) )
        {
          if ( *(v20 - 1) <= v23 )
            goto LABEL_40;
        }
        else
        {
          v23 = v39;
        }
        *(v20 - 1) = v23;
        v23 = flt_4D52A8;
LABEL_40:
        v40 = -v23;
        if ( v40 <= (double)*v20 )
        {
          if ( *v20 <= v23 )
            goto LABEL_44;
        }
        else
        {
          v23 = v40;
        }
        *v20 = v23;
        v23 = flt_4D52A8;
LABEL_44:
        v41 = -v23;
        if ( v41 <= (double)v20[1] )
        {
          if ( v20[1] > v23 )
            v20[1] = v23;
        }
        else
        {
          v20[1] = v41;
        }
        v30 = -flt_4D52B4;
        v20[3] = (v30 + (flt_4D52B4 - v30) * ((double)rand() / 32767.0)) * v25 + v20[3];
        v42 = -flt_4D52B0;
        if ( v42 <= (double)v20[3] )
        {
          if ( v20[3] > (double)flt_4D52B0 )
            v20[3] = flt_4D52B0;
        }
        else
        {
          v20[3] = v42;
        }
        v31 = -flt_4D52BC;
        v20[5] = (v31 + (flt_4D52BC - v31) * ((double)rand() / 32767.0)) * v25 + v20[5];
        v43 = -flt_4D5274;
        if ( v43 <= (double)v20[5] )
        {
          if ( v20[5] > (double)flt_4D5274 )
            v20[5] = flt_4D5274;
        }
        else
        {
          v20[5] = v43;
        }
        v20[4] = v20[5] * v25 + v20[4];
        if ( v20[4] >= 0.2000000029802322 )
        {
          if ( v20[4] > 1.0 )
            v20[4] = 1.0;
        }
        else
        {
          v20[4] = 0.2;
        }
        v24 = sub_401500(v50, v20 - 1, v25);
        *(v20 - 5) = *v24 + *(v20 - 5);
        *(v20 - 4) = v24[1] + *(v20 - 4);
        *(v20 - 3) = v24[2] + *(v20 - 3);
        v20[2] = v20[3] * v25 + v20[2];
        v44 = -flt_4D5294;
        if ( v44 <= (double)*(v20 - 5) )
        {
          if ( *(v20 - 5) > (double)flt_4D5294 )
            *(v20 - 5) = flt_4D5294;
        }
        else
        {
          *(v20 - 5) = v44;
        }
        v45 = -flt_4D5298;
        if ( v45 <= (double)*(v20 - 4) )
        {
          if ( *(v20 - 4) > (double)flt_4D5298 )
            *(v20 - 4) = flt_4D5298;
        }
        else
        {
          *(v20 - 4) = v45;
        }
        v46 = -flt_4D529C;
        if ( v46 <= (double)*(v20 - 3) )
        {
          if ( *(v20 - 3) > (double)flt_4D529C )
            *(v20 - 3) = flt_4D529C;
        }
        else
        {
          *(v20 - 3) = v46;
        }
        v20 += 11;
        --v21;
      }
      while ( v21 );
      v6 += 60;
      if ( !--v35 )
        return;
    }
    v16 = 0.0;
LABEL_30:
    v18 = v16;
    v19 = v38 - v7 * flt_4D527C;
    v17 = v18;
    *(v6 - 1) = v19;
    goto LABEL_27;
  }
}
