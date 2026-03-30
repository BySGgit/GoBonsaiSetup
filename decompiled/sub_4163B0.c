int __thiscall sub_4163B0(void *this, int a2, float a3, const void *a4)
{
  bool v4; // zf
  const void *v5; // eax
  const void *v6; // edx
  char *v7; // edi
  _DWORD *v8; // eax

  sub_413F50(a2, (int)this, a4, (int)&dword_4D82D4);
  v4 = (dword_4D8CD8 & 1) == 0;
  *(_DWORD *)a2 = &TreeSectionLeaf::`vftable';
  *(float *)(a2 + 512) = 1.0;
  *(float *)(a2 + 516) = 1.0;
  *(float *)(a2 + 520) = 1.0;
  *(float *)(a2 + 524) = 1.0;
  if ( v4 )
  {
    dword_4D8CD8 |= 1u;
    sub_40FAD0();
  }
  *(_DWORD *)(a2 + 4) = 7;
  *(float *)(a2 + 452) = (*(float *)flt_4D85F4 - *(float *)flt_4D85F0) * a3 + *(float *)flt_4D85F0;
  v5 = (const void *)rand();
  a4 = v5;
  v6 = *(const void **)(a2 + 184);
  *(_DWORD *)(a2 + 192) = 2;
  a4 = v6;
  *(float *)(a2 + 452) = ((double)(int)v5 / 32767.0 * 0.2000000476837158 + 0.8999999761581421) * *(float *)(a2 + 452);
  *(float *)(a2 + 428) = 0.0;
  v7 = dword_4D866C + 4;
  v8 = sub_40FD70(dword_4D866C, *((_DWORD *)dword_4D866C + 1), &a4);
  if ( dword_4D8670 == 1073741822 )
    std::_Xlength_error("list<T> too long");
  ++dword_4D8670;
  *(_DWORD *)v7 = v8;
  *(_DWORD *)v8[1] = v8;
  return a2;
}
