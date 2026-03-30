double __stdcall sub_403BA0(int a1)
{
  int v1; // eax
  int v2; // esi

  v1 = *(_DWORD *)(a1 + 240);
  if ( !*(_DWORD *)(v1 + 172) )
    return 0.0;
  v2 = *(_DWORD *)(**(_DWORD **)(v1 + 168) + 8);
  if ( !v2 )
    return 0.0;
  if ( (dword_4D7CF8 & 1) == 0 )
  {
    dword_4D7CF8 |= 1u;
    sub_4079C0();
  }
  if ( !byte_4D8225[11 * *(_DWORD *)(v2 + 4)] )
    return 0.0;
  return (float)(*(float *)(v2 + 444) + *(float *)(v2 + 444));
}
