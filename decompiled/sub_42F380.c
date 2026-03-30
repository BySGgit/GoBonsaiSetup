int __stdcall sub_42F380(_DWORD *a1)
{
  int v1; // esi
  int result; // eax
  _DWORD *v3; // edx
  _BYTE *v4; // ecx
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  int v7; // edx
  int v8; // esi

  v1 = a1[18];
  result = 0;
  if ( v1 <= 0 )
  {
LABEL_7:
    v5 = operator new(0x228u);
    v6 = v5;
    if ( v5 )
    {
      memset(v5, 0, 0x228u);
      v6[1] = 0xFFFF;
      v6[2] = 0xFFFF;
      if ( sub_42DBC0(a1[18] + 1, (int)(a1 + 17)) >= 0 )
        *(_DWORD *)(a1[17] + 4 * a1[18]++) = v6;
      v8 = a1[18];
      if ( a1[15] )
        sub_431860(v8 - 1, v7, (int)a1);
      return v8 - 1;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    v3 = (_DWORD *)a1[17];
    while ( 1 )
    {
      v4 = (_BYTE *)*v3;
      if ( !*(_BYTE *)*v3 && *((_DWORD *)v4 + 1) == 0xFFFF && *((_DWORD *)v4 + 2) == 0xFFFF )
        break;
      ++result;
      ++v3;
      if ( result >= v1 )
        goto LABEL_7;
    }
  }
  return result;
}
