int __fastcall LcidFromHexString(int a1, char *a2)
{
  int i; // esi
  char v3; // cl

  for ( i = 0; ; i = v3 + 16 * i - 48 )
  {
    v3 = *a2;
    if ( !*a2 )
      break;
    ++a2;
    if ( (unsigned __int8)(v3 - 97) > 5u )
    {
      if ( (unsigned __int8)(v3 - 65) <= 5u )
        v3 -= 7;
    }
    else
    {
      v3 -= 39;
    }
  }
  return i;
}
