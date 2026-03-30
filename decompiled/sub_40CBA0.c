int __cdecl sub_40CBA0(int a1, float *a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  char v4; // bl
  int v5; // edx
  int result; // eax
  float v7[55]; // [esp+10h] [ebp-E4h] BYREF

  sub_40B740(a2, (int)v7);
  v2 = *(_DWORD **)(a1 + 168);
  v3 = (_DWORD *)*v2;
  v4 = 0;
  if ( (_DWORD *)*v2 == v2 )
    return sub_40BB50(v7);
  do
  {
    v5 = v3[2];
    result = *(_DWORD *)(v5 + 4) - 6;
    switch ( *(_DWORD *)(v5 + 4) )
    {
      case 7:
        result = sub_40CAB0((float *)v3[2]);
        break;
      case 9:
        result = sub_40C320(a1, v5, v7);
        goto LABEL_6;
      case 0xA:
        result = sub_40CBA0(v5, v7);
LABEL_6:
        v4 = 1;
        break;
      default:
        break;
    }
    v3 = (_DWORD *)*v3;
  }
  while ( v3 != *(_DWORD **)(a1 + 168) );
  if ( !v4 )
    return sub_40BB50(v7);
  return result;
}
