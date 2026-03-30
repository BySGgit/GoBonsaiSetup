char __usercall sub_41CB90@<al>(_WORD *a1@<eax>, _DWORD *a2)
{
  _WORD *v2; // ecx
  _WORD *v3; // ebx
  _WORD *v4; // esi
  int v5; // edi
  _WORD *v6; // ecx
  _WORD *i; // ecx
  _WORD *v8; // edx

  v2 = (_WORD *)*a2;
  if ( *(_WORD *)*a2 == 58 )
  {
    v3 = v2 + 1;
    *a2 = v2 + 1;
    v4 = v2 + 1;
    v5 = 256;
    v6 = a1;
    while ( v5 != -2147483390 && *v4 )
    {
      *v6++ = *v4++;
      if ( !--v5 )
      {
        --v6;
        break;
      }
    }
    *v6 = 0;
    for ( i = a1; *i; ++i )
    {
      if ( *i <= 0x20u )
        break;
    }
    *i = 0;
    v8 = a1 + 1;
    while ( *a1++ )
      ;
    *a2 = &v3[a1 - v8];
    return 1;
  }
  else
  {
    *a1 = 0;
    return 0;
  }
}
