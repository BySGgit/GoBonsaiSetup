void __thiscall sub_40F140(_DWORD *this)
{
  unsigned int v1; // edi
  float **v2; // eax
  float *v3; // esi
  int v4; // ecx
  float *v5; // ebx
  float *v6; // ebp
  int v7; // ebx
  float *v8; // esi
  float v9; // ecx
  float v10; // edx
  float v11; // eax
  float v12; // ecx
  float v13; // edx
  double v14; // st7
  float *v15; // eax
  float *v16; // eax
  double v17; // st7
  float *v18; // eax
  float v19; // edx
  float v20; // eax
  double v21; // st6
  float v22; // ecx
  float v23; // edx
  float v24; // eax
  double v25; // st6
  bool v26; // c0
  double v27; // rt1
  double v28; // st6
  double v29; // st7
  double v30; // rt2
  double v31; // st7
  double v32; // st6
  double v33; // st5
  double v34; // st7
  void (__thiscall *v35)(int); // eax
  float *v36; // esi
  float v37; // [esp+1Ch] [ebp-2C8h]
  float v38; // [esp+34h] [ebp-2B0h] BYREF
  float v39; // [esp+38h] [ebp-2ACh]
  float v40; // [esp+3Ch] [ebp-2A8h]
  float v41; // [esp+40h] [ebp-2A4h]
  float v42; // [esp+44h] [ebp-2A0h]
  float v43; // [esp+48h] [ebp-29Ch]
  float v44; // [esp+4Ch] [ebp-298h]
  _DWORD *v45; // [esp+50h] [ebp-294h] BYREF
  float v46; // [esp+54h] [ebp-290h] BYREF
  float v47; // [esp+58h] [ebp-28Ch]
  float v48; // [esp+5Ch] [ebp-288h]
  int v49; // [esp+60h] [ebp-284h] BYREF
  int v50; // [esp+64h] [ebp-280h] BYREF
  float v51; // [esp+68h] [ebp-27Ch]
  int v52; // [esp+6Ch] [ebp-278h]
  float v53[3]; // [esp+70h] [ebp-274h] BYREF
  float v54[3]; // [esp+7Ch] [ebp-268h] BYREF
  float v55[3]; // [esp+88h] [ebp-25Ch] BYREF
  float v56[16]; // [esp+94h] [ebp-250h] BYREF
  _BYTE v57[64]; // [esp+D4h] [ebp-210h] BYREF
  _BYTE v58[64]; // [esp+114h] [ebp-1D0h] BYREF
  _BYTE v59[64]; // [esp+154h] [ebp-190h] BYREF
  _BYTE v60[64]; // [esp+194h] [ebp-150h] BYREF
  _BYTE v61[64]; // [esp+1D4h] [ebp-110h] BYREF
  _BYTE v62[64]; // [esp+214h] [ebp-D0h] BYREF
  _BYTE v63[64]; // [esp+254h] [ebp-90h] BYREF
  _BYTE v64[64]; // [esp+294h] [ebp-50h] BYREF
  int v65; // [esp+2E0h] [ebp-4h]

  v1 = (unsigned int)this;
  v45 = this;
  v2 = (float **)*(this + 51);
  if ( 150.0 != flt_4D526C )
  {
    v6 = *v2;
    if ( *v2 == (float *)v2 )
      return;
    while ( 1 )
    {
      v38 = v6[2];
      sub_451210(&v49, (unsigned int *)&v38);
      if ( v49 != dword_4D8C10 )
      {
        v7 = *(_DWORD *)(v49 + 12);
        if ( v7 )
          break;
      }
      v8 = *(float **)v6;
      if ( v6 != *(float **)(v1 + 204) )
      {
        **((_DWORD **)v6 + 1) = v8;
        *(float *)(*(_DWORD *)v6 + 4) = v6[1];
        operator delete(v6);
        --*(_DWORD *)(v1 + 208);
      }
      v6 = v8;
LABEL_54:
      if ( v6 == *(float **)(v1 + 204) )
        return;
    }
    qmemcpy(v56, (const void *)(v7 + 40), sizeof(v56));
    sub_4015F0(&v46, v56);
    v9 = *(float *)(v7 + 504);
    v10 = *(float *)(v7 + 508);
    v42 = *(float *)(v7 + 500);
    v11 = *(float *)(v7 + 488);
    v43 = v9;
    v12 = *(float *)(v7 + 492);
    v44 = v10;
    v13 = *(float *)(v7 + 496);
    v39 = v11;
    v40 = v12;
    v41 = v13;
    if ( (dword_4D8CD8 & 1) == 0 )
    {
      dword_4D8CD8 |= 1u;
      v65 = 0;
      sub_40FAD0();
      v65 = -1;
    }
    v14 = v40;
    if ( byte_4D8227[11 * *(_DWORD *)(v7 + 4)] )
    {
      v40 = v14 - 0.02500000037252903;
      v38 = (double)rand() / 32767.0 * 0.5 + 0.5;
      v37 = v38;
      v15 = sub_401500(v54, (float *)&dword_4D8A68, 0.090000004);
      v16 = sub_401470(v55, v15, v37);
      v39 = *v16 + v39;
      v40 = v16[1] + v40;
      v41 = v16[2] + v41;
      v38 = COERCE_FLOAT(rand());
      v39 = ((double)SLODWORD(v38) / 32767.0 + (double)SLODWORD(v38) / 32767.0 - 1.0) * 0.119999997317791 + v39;
      v38 = COERCE_FLOAT(rand());
      v40 = ((double)SLODWORD(v38) / 32767.0 + (double)SLODWORD(v38) / 32767.0 - 1.0) * 0.119999997317791 + v40;
      v38 = COERCE_FLOAT(rand());
      v41 = ((double)SLODWORD(v38) / 32767.0 + (double)SLODWORD(v38) / 32767.0 - 1.0) * 0.119999997317791 + v41;
      v38 = COERCE_FLOAT(rand());
      v42 = ((double)SLODWORD(v38) / 32767.0 + (double)SLODWORD(v38) / 32767.0 - 1.0) * 0.05000000074505806 + v42;
      v38 = COERCE_FLOAT(rand());
      v43 = ((double)SLODWORD(v38) / 32767.0 + (double)SLODWORD(v38) / 32767.0 - 1.0) * 0.05000000074505806 + v43;
      v38 = COERCE_FLOAT(rand());
      v17 = ((double)SLODWORD(v38) / 32767.0 + (double)SLODWORD(v38) / 32767.0 - 1.0) * 0.05000000074505806 + v44;
    }
    else
    {
      v40 = v14 - 0.1000000014901161;
      v18 = sub_401500(v53, (float *)&dword_4D8A68, 0.029999999);
      v39 = *v18 + v39;
      v40 = v18[1] + v40;
      v41 = v18[2] + v41;
      v42 = v42 * 0.9800000190734863;
      v43 = v43 * 0.9800000190734863;
      v17 = 0.9800000190734863 * v44;
    }
    v44 = v17;
    v19 = v40;
    v20 = v41;
    v21 = v39;
    *(float *)(v7 + 488) = v39;
    v22 = v42;
    *(float *)(v7 + 492) = v19;
    v23 = v43;
    *(float *)(v7 + 496) = v20;
    v24 = v44;
    *(float *)(v7 + 500) = v22;
    *(float *)(v7 + 504) = v23;
    *(float *)(v7 + 508) = v24;
    if ( v21 >= -5.0 )
    {
      v26 = v21 > 5.0;
      v25 = 5.0;
      if ( v26 )
        v39 = 5.0;
    }
    else
    {
      v39 = -5.0;
      v25 = 5.0;
    }
    if ( v40 >= -5.0 )
    {
      if ( v40 > v25 )
        v40 = v25;
      v30 = v25;
      v28 = -5.0;
      v29 = v30;
    }
    else
    {
      v27 = v25;
      v28 = -5.0;
      v29 = v27;
      v40 = -5.0;
    }
    if ( v41 >= v28 )
    {
      if ( v41 > v29 )
        v41 = v29;
    }
    else
    {
      v41 = v28;
    }
    if ( v42 >= -0.2000000029802322 )
    {
      if ( v42 > 0.2000000029802322 )
        v42 = 0.2;
      v32 = 0.2000000029802322;
      v31 = -0.2000000029802322;
    }
    else
    {
      v31 = -0.2000000029802322;
      v42 = -0.2;
      v32 = 0.2000000029802322;
    }
    if ( v43 >= v31 )
    {
      if ( v43 <= v32 )
        goto LABEL_44;
      v33 = 0.2;
    }
    else
    {
      v33 = -0.2;
    }
    v43 = v33;
LABEL_44:
    if ( v44 >= v31 )
    {
      if ( v32 >= v44 )
        goto LABEL_49;
      v34 = 0.2;
    }
    else
    {
      v34 = -0.2;
    }
    v44 = v34;
LABEL_49:
    v46 = v46 + v39;
    v47 = v47 + v40;
    v48 = v48 + v41;
    v56[12] = v46;
    v56[13] = v47;
    v56[14] = v48;
    sub_4085B0(v7 + 468, &v50, (int)v56);
    D3DXMatrixTranslation(v57, v50, LODWORD(v51), v52);
    D3DXMatrixRotationYawPitchRoll(v58, LODWORD(v42), LODWORD(v43), LODWORD(v44));
    D3DXMatrixInverse(v63, 0, v57);
    qmemcpy(v61, v63, sizeof(v61));
    D3DXMatrixMultiply(v59, v61, v58);
    qmemcpy(v60, v59, sizeof(v60));
    D3DXMatrixMultiply(v62, v60, v57);
    qmemcpy(v64, v62, sizeof(v64));
    D3DXMatrixMultiply(v56, v56, v64);
    v35 = *(void (__thiscall **)(int))(*(_DWORD *)v7 + 12);
    qmemcpy((void *)(v7 + 40), v56, 0x40u);
    v35(v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 16))(v7);
    v1 = (unsigned int)v45;
    if ( v51 >= -100.0 )
    {
      v6 = *(float **)v6;
    }
    else
    {
      v36 = *(float **)v6;
      if ( v6 != (float *)v45[51] )
      {
        **((_DWORD **)v6 + 1) = v36;
        *(float *)(*(_DWORD *)v6 + 4) = v6[1];
        operator delete(v6);
        --*(_DWORD *)(v1 + 208);
      }
      v6 = v36;
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(v7);
    }
    goto LABEL_54;
  }
  v3 = *v2;
  if ( *v2 != (float *)v2 )
  {
    do
    {
      v45 = (_DWORD *)*((_DWORD *)v3 + 2);
      sub_451210(&v38, (unsigned int *)&v45);
      if ( LODWORD(v38) != dword_4D8C10 )
      {
        v4 = *(_DWORD *)(LODWORD(v38) + 12);
        if ( v4 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4);
      }
      v5 = *(float **)v3;
      if ( v3 != *(float **)(v1 + 204) )
      {
        **((_DWORD **)v3 + 1) = v5;
        *(float *)(*(_DWORD *)v3 + 4) = v3[1];
        operator delete(v3);
        --*(_DWORD *)(v1 + 208);
      }
      v3 = v5;
    }
    while ( v5 != *(float **)(v1 + 204) );
  }
}
