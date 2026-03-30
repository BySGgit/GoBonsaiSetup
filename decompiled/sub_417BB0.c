int __fastcall sub_417BB0(const void *a1, int a2, int a3, float a4, int a5)
{
  double v5; // st7

  sub_413F50(a3, a2, a1, a5);
  *(_DWORD *)a3 = &TreeSectionTwig::`vftable';
  *(_BYTE *)(a3 + 512) = 0;
  if ( (dword_4D8CE0 & 1) == 0 )
  {
    dword_4D8CE0 |= 1u;
    sub_40FBA0();
  }
  *(_DWORD *)(a3 + 4) = 10;
  *(float *)(a3 + 452) = (*(float *)flt_4D85EC - *(float *)flt_4D85E8) * a4 + *(float *)flt_4D85E8;
  v5 = (double)rand();
  *(_DWORD *)(a3 + 192) = 1;
  *(float *)(a3 + 452) = (v5 / 32767.0 * 0.2000000476837158 + 0.8999999761581421) * *(float *)(a3 + 452);
  *(float *)(a3 + 428) = 1.0;
  return a3;
}
