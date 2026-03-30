int __userpurge sub_4102C0@<eax>(int a1@<eax>, char a2)
{
  __int64 v3; // kr00_8
  float v4; // edx
  int v5; // edi
  double v6; // st6
  int v7; // edi
  double v8; // st6
  int v9; // edi
  float *v10; // esi
  int v11; // edi
  int v12; // eax
  double v13; // st6
  int v14; // eax
  int v15; // eax
  double v16; // st6
  int result; // eax
  float v18; // [esp+8h] [ebp-2Ch]
  float v19; // [esp+8h] [ebp-2Ch]
  float v20; // [esp+8h] [ebp-2Ch]
  float v21; // [esp+Ch] [ebp-28h]
  float v22; // [esp+Ch] [ebp-28h]
  float v23; // [esp+Ch] [ebp-28h]
  double v24; // [esp+10h] [ebp-24h]
  float v25; // [esp+10h] [ebp-24h]
  int v26; // [esp+10h] [ebp-24h]
  float v27; // [esp+10h] [ebp-24h]
  int v28; // [esp+10h] [ebp-24h]
  __int64 v29; // [esp+10h] [ebp-24h]
  float v30; // [esp+10h] [ebp-24h]
  float v31; // [esp+14h] [ebp-20h]
  float v32; // [esp+18h] [ebp-1Ch]
  float v33; // [esp+18h] [ebp-1Ch]
  __int64 v34; // [esp+1Ch] [ebp-18h]
  double v35; // [esp+1Ch] [ebp-18h]
  float v36; // [esp+1Ch] [ebp-18h]
  float v37; // [esp+1Ch] [ebp-18h]
  float v38; // [esp+1Ch] [ebp-18h]
  float v39; // [esp+1Ch] [ebp-18h]
  float v40; // [esp+1Ch] [ebp-18h]
  float v41; // [esp+1Ch] [ebp-18h]
  float v42; // [esp+1Ch] [ebp-18h]
  float v43; // [esp+20h] [ebp-14h]
  float v44; // [esp+20h] [ebp-14h]
  float v45; // [esp+24h] [ebp-10h]
  float v46; // [esp+24h] [ebp-10h]
  float v47; // [esp+24h] [ebp-10h]
  float v48; // [esp+28h] [ebp-Ch]
  float v49; // [esp+2Ch] [ebp-8h]
  float v50; // [esp+30h] [ebp-4h]
  float v51; // [esp+38h] [ebp+4h]
  float v52; // [esp+38h] [ebp+4h]
  float v53; // [esp+38h] [ebp+4h]
  float v54; // [esp+38h] [ebp+4h]
  float v55; // [esp+38h] [ebp+4h]
  float v56; // [esp+38h] [ebp+4h]
  float v57; // [esp+38h] [ebp+4h]
  float v58; // [esp+38h] [ebp+4h]
  float v59; // [esp+38h] [ebp+4h]
  float v60; // [esp+38h] [ebp+4h]
  float v61; // [esp+38h] [ebp+4h]

  if ( a2 )
  {
    *(float *)(a1 + 232) = (double)rand() / 32767.0 * 0.5 + 0.5;
    v51 = -flt_4D5274;
    *(float *)(a1 + 236) = v51 + (flt_4D5274 - v51) * ((double)rand() / 32767.0);
    v52 = -flt_4D5284;
    *(float *)&v34 = v52 + (flt_4D5284 - v52) * ((double)rand() / 32767.0);
    *((float *)&v34 + 1) = flt_4D528C + (flt_4D5290 - flt_4D528C) * ((double)rand() / 32767.0);
    v53 = -flt_4D5288;
    v3 = v34;
    v45 = v53 + (flt_4D5288 - v53) * ((double)rand() / 32767.0);
    v4 = v45;
LABEL_8:
    *(_QWORD *)(a1 + 220) = v3;
    *(float *)(a1 + 228) = v4;
    goto LABEL_9;
  }
  *(float *)(a1 + 232) = 0.0;
  v35 = flt_4D5274;
  v24 = flt_4D5274 * 0.5;
  *(float *)(a1 + 236) = v24 + (v35 - v24) * ((double)rand() / 32767.0);
  if ( flt_4D5284 >= (double)*(float *)(a1 + 220) )
  {
    if ( -flt_4D5284 <= *(float *)(a1 + 220) )
    {
      v9 = *(_DWORD *)(dword_4D7EE8 + 240);
      v38 = sub_4153D0(v9);
      v23 = sub_4153D0(v9);
      v20 = sub_4153D0(v9);
      v56 = -flt_4D5284;
      *(float *)&v29 = v56 + (flt_4D5284 - v56) * ((double)rand() / 32767.0);
      *((float *)&v29 + 1) = (double)rand() / 32767.0 * (v23 + flt_4D5290 - (v20 + flt_4D528C)) + flt_4D528C + v38;
      v57 = -flt_4D5288;
      v32 = v57 + (flt_4D5288 - v57) * ((double)rand() / 32767.0);
      v4 = v32;
      v3 = v29;
      goto LABEL_8;
    }
    v7 = *(_DWORD *)(dword_4D7EE8 + 240);
    v19 = sub_4153D0(v7);
    v27 = sub_4153D0(v7);
    v22 = sub_4153D0(v7);
    v37 = flt_4D5284 + 100.0;
    v44 = flt_4D528C + v19 + (flt_4D5290 + v27 - (flt_4D528C + v22)) * ((double)rand() / 32767.0);
    v55 = -flt_4D5288;
    v28 = rand();
    v8 = flt_4D5288;
    *(float *)(a1 + 220) = v37;
    *(float *)(a1 + 224) = v44;
    v47 = v55 + (v8 - v55) * ((double)v28 / 32767.0);
    *(float *)(a1 + 228) = v47;
  }
  else
  {
    v5 = *(_DWORD *)(dword_4D7EE8 + 240);
    v25 = sub_4153D0(v5);
    v18 = sub_4153D0(v5);
    v21 = sub_4153D0(v5);
    v36 = -flt_4D5284 - 100.0;
    v43 = flt_4D528C + v25 + (flt_4D5290 + v18 - (flt_4D528C + v21)) * ((double)rand() / 32767.0);
    v54 = -flt_4D5288;
    v26 = rand();
    v6 = flt_4D5288;
    *(float *)(a1 + 220) = v36;
    *(float *)(a1 + 224) = v43;
    v46 = v54 + (v6 - v54) * ((double)v26 / 32767.0);
    *(float *)(a1 + 228) = v46;
  }
LABEL_9:
  v10 = (float *)(a1 + 12);
  v11 = 5;
  do
  {
    v10[6] = (double)rand() / 32767.0 * 0.5 + 0.5;
    v39 = -flt_4D5294;
    v30 = v39 + (flt_4D5294 - v39) * ((double)rand() / 32767.0);
    v40 = -flt_4D5298;
    v31 = v40 + (flt_4D5298 - v40) * ((double)rand() / 32767.0);
    v41 = -flt_4D529C;
    v12 = rand();
    v13 = flt_4D529C;
    *(v10 - 3) = v30;
    *(v10 - 2) = v31;
    v33 = v41 + (v13 - v41) * ((double)v12 / 32767.0);
    *(v10 - 1) = v33;
    *v10 = flt_4D52A0 + (flt_4D52A4 - flt_4D52A0) * ((double)rand() / 32767.0);
    v14 = rand();
    v10[4] = ((double)v14 / 32767.0 + (double)v14 / 32767.0) * 3.141592741012573;
    v42 = -flt_4D52B0;
    v10[5] = v42 + (flt_4D52B0 - v42) * ((double)rand() / 32767.0);
    v58 = -flt_4D52A8;
    v48 = v58 + (flt_4D52A8 - v58) * ((double)rand() / 32767.0);
    v59 = -flt_4D52A8;
    v49 = v59 + (flt_4D52A8 - v59) * ((double)rand() / 32767.0);
    v60 = -flt_4D52A8;
    v15 = rand();
    v16 = flt_4D52A8;
    v10[1] = v48;
    v10[2] = v49;
    v50 = v60 + (v16 - v60) * ((double)v15 / 32767.0);
    v10[3] = v50;
    v61 = -flt_4D5274;
    result = rand();
    v10 += 11;
    *(v10 - 4) = v61 + (flt_4D5274 - v61) * ((double)result / 32767.0);
    --v11;
  }
  while ( v11 );
  return result;
}
