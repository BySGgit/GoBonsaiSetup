_BYTE *__usercall sub_447330@<eax>(_BYTE *result@<eax>, __int16 a2@<dx>, _BYTE *a3@<edi>)
{
  _BYTE *v3; // ecx
  _BYTE *v4; // ecx
  int v5; // esi
  char v6; // dl

  *result = 37;
  v3 = result + 1;
  if ( (a2 & 0x20) != 0 )
  {
    *v3 = 43;
    v3 = result + 2;
  }
  if ( (a2 & 8) != 0 )
    *v3++ = 35;
  if ( *a3 == 76 )
  {
    *(_WORD *)v3 = 13897;
    v3[2] = 52;
    v4 = v3 + 3;
  }
  else
  {
    *v3 = *a3;
    v4 = v3 + 1;
  }
  v5 = a2 & 0xE00;
  if ( v5 == 1024 )
  {
    *v4 = 111;
    v4[1] = 0;
  }
  else
  {
    if ( v5 == 2048 )
      v6 = ~(8 * a2) & 0x20 | 0x58;
    else
      v6 = a3[1];
    *v4 = v6;
    v4[1] = 0;
  }
  return result;
}
