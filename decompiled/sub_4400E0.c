void __userpurge sub_4400E0(int a1@<edi>, float a2)
{
  double v2; // st7
  _DWORD *v3; // eax
  _DWORD *v4; // esi

  if ( *(_BYTE *)(a1 + 112) )
    v2 = a2 * 30.0 + *(float *)(a1 + 116);
  else
    v2 = *(float *)(a1 + 116) - a2 * 30.0;
  *(float *)(a1 + 116) = v2;
  if ( *(float *)(a1 + 116) >= 0.0 )
  {
    if ( *(float *)(a1 + 116) > 1.0 )
      *(float *)(a1 + 116) = 1.0;
  }
  else
  {
    *(float *)(a1 + 116) = 0.0;
  }
  *(float *)(a1 + 116) = *(float *)(a1 + 116);
  sub_440D50((_DWORD **)a1);
  while ( *(_DWORD *)(a1 + 40) > 0x20u )
  {
    v3 = *(_DWORD **)(a1 + 36);
    v4 = (_DWORD *)v3[1];
    if ( v4 != v3 )
    {
      *(_DWORD *)v4[1] = *v4;
      *(_DWORD *)(*v4 + 4) = v4[1];
      if ( v4[7] >= 8u )
        operator delete((void *)v4[2]);
      v4[7] = 7;
      v4[6] = 0;
      *((_WORD *)v4 + 4) = 0;
      operator delete(v4);
      --*(_DWORD *)(a1 + 40);
    }
  }
}
