int __stdcall sub_401C10(int a1, float a2, float a3, float a4, float a5)
{
  sub_401830(a1);
  *(float *)(a1 + 196) = a2;
  *(_DWORD *)a1 = &Camera::`vftable';
  *(float *)(a1 + 200) = a3;
  *(float *)(a1 + 204) = a4;
  *(float *)(a1 + 208) = a5;
  *(float *)(a1 + 212) = 0.0;
  *(float *)(a1 + 216) = 0.0;
  *(float *)(a1 + 220) = 0.0;
  qmemcpy((void *)(a1 + 224), &unk_4D8BA8, 0x40u);
  qmemcpy((void *)(a1 + 288), &unk_4D8BA8, 0x40u);
  return a1;
}
