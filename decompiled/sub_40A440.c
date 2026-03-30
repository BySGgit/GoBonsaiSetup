void sub_40A440()
{
  int *v0; // esi
  int v1; // ecx
  float *v2; // esi
  float *v3; // eax
  float *v4; // eax
  float *v5; // esi
  float *v6; // eax
  float *v7; // eax
  float *v8; // esi
  float *v9; // eax
  float *v10; // eax
  float *v11; // esi
  float *v12; // eax
  float *v13; // eax
  float v14; // [esp+8h] [ebp-E8h]
  float v15; // [esp+8h] [ebp-E8h]
  int v16; // [esp+Ch] [ebp-E4h] BYREF
  int v17; // [esp+10h] [ebp-E0h]
  int v18; // [esp+14h] [ebp-DCh]
  int v19; // [esp+18h] [ebp-D8h]
  int v20; // [esp+1Ch] [ebp-D4h]
  int v21; // [esp+20h] [ebp-D0h] BYREF
  int v22; // [esp+24h] [ebp-CCh]
  int v23; // [esp+28h] [ebp-C8h]
  int v24; // [esp+2Ch] [ebp-C4h] BYREF
  int v25; // [esp+30h] [ebp-C0h]
  int v26; // [esp+34h] [ebp-BCh]
  int v27; // [esp+38h] [ebp-B8h] BYREF
  int v28; // [esp+3Ch] [ebp-B4h]
  int v29; // [esp+40h] [ebp-B0h]
  int v30; // [esp+44h] [ebp-ACh] BYREF
  int v31; // [esp+48h] [ebp-A8h]
  int v32; // [esp+4Ch] [ebp-A4h]
  float v33[3]; // [esp+50h] [ebp-A0h] BYREF
  int v34; // [esp+5Ch] [ebp-94h]
  int v35; // [esp+60h] [ebp-90h]
  int v36; // [esp+64h] [ebp-8Ch]
  float v37[3]; // [esp+68h] [ebp-88h] BYREF
  float v38[3]; // [esp+74h] [ebp-7Ch] BYREF
  float v39[3]; // [esp+80h] [ebp-70h] BYREF
  float v40[3]; // [esp+8Ch] [ebp-64h] BYREF
  float v41[3]; // [esp+98h] [ebp-58h] BYREF
  float v42[3]; // [esp+A4h] [ebp-4Ch] BYREF
  float v43[16]; // [esp+B0h] [ebp-40h] BYREF

  if ( !byte_4D7E8C )
  {
    byte_4D7E8C = 1;
    dword_4D7E90 = 0;
    dword_4D7EA8 = 0;
  }
  sub_40CE80(&dword_4D7E90);
  sub_40CE80(&dword_4D7EA8);
  *(float *)&v18 = 0.0;
  v20 = 0;
  v0 = (int *)&unk_4D8378;
  do
  {
    v14 = (double)v20 / 6.0;
    v15 = (v14 + v14) * 3.141592741012573;
    *(float *)&v19 = cos(v15);
    v16 = v19;
    *(float *)&v19 = sin(v15);
    ++v20;
    v17 = v19;
    v1 = v19;
    *v0 = v16;
    v0[1] = v1;
    *((float *)v0 + 2) = 0.0;
    v0 += 3;
  }
  while ( (int)v0 < (int)&dword_4D83C0 );
  *(float *)&v30 = -1.0;
  *(float *)&v31 = 0.0;
  *(float *)&v32 = 0.0;
  *(float *)&v27 = 1.0;
  *(float *)&v28 = 0.0;
  *(float *)&v29 = 0.0;
  *(float *)&v21 = -1.0;
  *(float *)&v22 = -1.0;
  *(float *)&v23 = 2.0;
  *(float *)&v26 = 2.0;
  *(float *)&v24 = 1.0;
  *(float *)&v18 = 1.0;
  *(float *)&v25 = -1.0;
  *(float *)&v35 = -1.0;
  *(float *)&v16 = 0.0;
  *(float *)&v17 = 0.0;
  *(float *)&v34 = 0.0;
  *(float *)&v36 = 0.0;
  v2 = sub_401430(v37, (float *)&v30, (float *)&v16);
  v3 = sub_401430(v33, (float *)&v30, (float *)&v21);
  v4 = sub_401120(v38, v2, v3);
  sub_408590(v4, v39);
  v5 = sub_401430(v37, (float *)&v27, (float *)&v24);
  v6 = sub_401430(v33, (float *)&v27, (float *)&v16);
  v7 = sub_401120(v40, v5, v6);
  sub_408590(v7, v38);
  v8 = sub_401430(v40, (float *)&v21, (float *)&v30);
  v9 = sub_401430(v33, (float *)&v21, (float *)&v24);
  v10 = sub_401120(v41, v8, v9);
  sub_408590(v10, v37);
  v11 = sub_401430(v41, (float *)&v24, (float *)&v21);
  v12 = sub_401430(v40, (float *)&v24, (float *)&v27);
  v13 = sub_401120(v42, v11, v12);
  sub_408590(v13, v33);
  dword_4D83C0 = v30;
  dword_4D83CC = LODWORD(v39[0]);
  dword_4D83C4 = v31;
  dword_4D83C8 = v32;
  dword_4D83D0 = LODWORD(v39[1]);
  dword_4D83D4 = LODWORD(v39[2]);
  qmemcpy(&unk_4D83D8, sub_40A320(v43, (int)&dword_4D83CC), 0x40u);
  flt_4D8418 = 0.0;
  flt_4D841C = 1.0;
  dword_4D8420 = v27;
  dword_4D842C = LODWORD(v38[0]);
  dword_4D8424 = v28;
  dword_4D8428 = v29;
  dword_4D8430 = LODWORD(v38[1]);
  dword_4D8434 = LODWORD(v38[2]);
  qmemcpy(&unk_4D8438, sub_40A320(v43, (int)&dword_4D842C), 0x40u);
  flt_4D8478 = 1.0;
  flt_4D847C = 1.0;
  dword_4D8480 = v24;
  dword_4D848C = LODWORD(v33[0]);
  dword_4D8484 = v25;
  dword_4D8488 = v26;
  dword_4D8490 = LODWORD(v33[1]);
  dword_4D8494 = LODWORD(v33[2]);
  qmemcpy(&unk_4D8498, sub_40A320(v43, (int)&dword_4D848C), 0x40u);
  flt_4D84D8 = 1.0;
  flt_4D84DC = 0.0;
  dword_4D84E0 = v21;
  dword_4D84EC = LODWORD(v37[0]);
  dword_4D84E4 = v22;
  dword_4D84E8 = v23;
  dword_4D84F0 = LODWORD(v37[1]);
  dword_4D84F4 = LODWORD(v37[2]);
  qmemcpy(&unk_4D84F8, sub_40A320(v43, (int)&dword_4D84EC), 0x40u);
  flt_4D8538 = 0.0;
  flt_4D853C = 0.0;
  dword_4D8540 = v16;
  dword_4D854C = v34;
  dword_4D8544 = v17;
  dword_4D8548 = v18;
  dword_4D8550 = v35;
  dword_4D8554 = v36;
  qmemcpy(&unk_4D8558, sub_40A320(v43, (int)&dword_4D854C), 0x40u);
  flt_4D8598 = flt_4D63B0;
  flt_4D859C = flt_4D63B0;
  sub_40CD30();
}
