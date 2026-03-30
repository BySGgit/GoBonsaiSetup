int __thiscall sub_417550(void *this, int a2, float a3, const void *a4)
{
  int v4; // edx

  sub_413F50(a2, (int)this, a4, (int)&dword_4D82D4);
  *(_BYTE *)(a2 + 516) = 0;
  *(_DWORD *)a2 = &TreeSectionStump::`vftable';
  if ( (dword_4D8CF8 & 1) == 0 )
  {
    dword_4D8CF8 |= 1u;
    sub_413C20();
  }
  v4 = *(_DWORD *)(a2 + 180);
  *(float *)(a2 + 428) = a3;
  *(_DWORD *)(a2 + 4) = 9;
  *(float *)(a2 + 512) = a3 / *(float *)(v4 + 428);
  *(_DWORD *)(a2 + 520) = (int)(*(float *)(a2 + 444) * 3.0 + 1.0);
  return a2;
}
