int __stdcall sub_417220(int a1, int a2)
{
  sub_413F50(a1, a2, &unk_4D8BA8, (int)&flt_4D5348);
  *(_DWORD *)a1 = &TreeSectionSeed::`vftable';
  if ( (dword_4D8CD0 & 1) == 0 )
  {
    dword_4D8CD0 |= 1u;
    sub_40FA00();
  }
  *(_DWORD *)(a1 + 4) = 8;
  *(float *)(a1 + 428) = 1.0;
  *(_DWORD *)(a1 + 416) = 0;
  *(float *)(a1 + 196) = 0.0;
  *(float *)(a1 + 200) = 1.0;
  *(float *)(a1 + 208) = 1.0;
  *(float *)(a1 + 204) = 0.0;
  *(float *)(a1 + 212) = 1.0;
  return a1;
}
