void __usercall sub_40D1A0(int a1@<edi>)
{
  float *v1; // eax
  int *v2; // eax
  float v3[3]; // [esp+8h] [ebp-18h] BYREF
  float v4[3]; // [esp+14h] [ebp-Ch] BYREF

  dword_4D5304 = *(_DWORD *)a1;
  dword_4D5308 = *(_DWORD *)(a1 + 4);
  dword_4D530C = *(_DWORD *)(a1 + 8);
  flt_4D5300 = sub_4084F0((float *)&dword_4D5304);
  v1 = sub_401500(v3, (float *)&dword_4D52F4, *(float *)flt_4D52F0);
  v2 = (int *)sub_4013F0(v4, v1, (float *)a1);
  dword_4D5314 = *v2;
  dword_4D5318 = v2[1];
  dword_4D531C = v2[2];
  flt_4D5310 = sub_4084F0((float *)&dword_4D5314);
}
