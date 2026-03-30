int __initstdio()
{
  int v0; // eax
  int v1; // eax
  int v3; // edx
  _UNKNOWN **v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int v7; // eax

  v0 = dword_4DCF20;
  if ( !dword_4DCF20 )
  {
    v0 = 512;
LABEL_5:
    dword_4DCF20 = v0;
    goto LABEL_6;
  }
  if ( dword_4DCF20 < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = _calloc_crt(v0, 4);
  dword_4DBF04 = v1;
  if ( !v1 )
  {
    dword_4DCF20 = 20;
    v1 = _calloc_crt(20, 4);
    dword_4DBF04 = v1;
    if ( !v1 )
      return 26;
  }
  v3 = 0;
  v4 = &off_4C9F00;
  while ( 1 )
  {
    *(_DWORD *)(v3 + v1) = v4;
    v4 += 8;
    v3 += 4;
    if ( (int)v4 >= (int)&dword_4CA180 )
      break;
    v1 = dword_4DBF04;
  }
  v5 = 0;
  v6 = &unk_4C9F10;
  do
  {
    v7 = *(_DWORD *)(((v5 & 0x1F) << 6) + dword_4DCF40[v5 >> 5]);
    if ( v7 == -1 || v7 == -2 || !v7 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_4C9F70 );
  return 0;
}
