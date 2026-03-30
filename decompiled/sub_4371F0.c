int __usercall sub_4371F0@<eax>(_DWORD *a1@<eax>, int a2@<edi>, int a3@<esi>)
{
  float v4; // [esp+0h] [ebp-14h]

  *(_DWORD *)a3 = 0;
  if ( a1 )
  {
    *(_DWORD *)(a3 + 12) = *a1;
    *(_DWORD *)(a3 + 16) = a1[1];
    *(_DWORD *)(a3 + 20) = a1[2];
    *(_DWORD *)(a3 + 24) = a1[3];
  }
  else
  {
    SetRectEmpty((LPRECT)(a3 + 12));
  }
  *(_DWORD *)(a3 + 28) = a2;
  *(_DWORD *)(a3 + 40) = a2;
  *(_DWORD *)(a3 + 44) = a2;
  *(_DWORD *)(a3 + 48) = a2;
  v4 = 0.003921568859368563 * 0.0;
  *(_DWORD *)(a3 + 32) = -931102592;
  *(_DWORD *)(a3 + 36) = 0;
  *(float *)(a3 + 52) = v4;
  *(float *)(a3 + 56) = v4;
  *(float *)(a3 + 60) = v4;
  *(float *)(a3 + 64) = v4;
  return LODWORD(v4);
}
