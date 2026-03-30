int __fastcall sub_4159C0(const void *a1, int a2, int a3, int a4)
{
  double v4; // st7
  double v6; // [esp+Ch] [ebp-20h]
  double v7; // [esp+14h] [ebp-18h]

  sub_413F50(a3, a2, a1, a4);
  *(float *)(a3 + 512) = 0.0;
  *(_DWORD *)a3 = &TreeSectionBud::`vftable';
  *(_DWORD *)(a3 + 516) = 0;
  if ( (dword_4D8DA0 & 1) == 0 )
  {
    dword_4D8DA0 |= 1u;
    sub_415800();
  }
  *(_DWORD *)(a3 + 4) = 6;
  v6 = *(float *)flt_4D85F8;
  v7 = *(float *)flt_4D85F8 * 0.800000011920929;
  v4 = (double)rand();
  ++*(_DWORD *)(a3 + 416);
  *(float *)(a3 + 452) = v7 + (v6 - v7) * (v4 / 32767.0);
  *(float *)(a3 + 444) = 0.0099999998;
  *(float *)(a3 + 428) = 1.0;
  return a3;
}
