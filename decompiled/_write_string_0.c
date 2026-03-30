int __usercall write_string_0@<eax>(_DWORD *a1@<eax>, int a2@<ebx>, int *a3@<edi>, _BYTE *a4, int a5)
{
  int result; // eax
  int v7; // eax
  int v8; // [esp+4h] [ebp-4h]

  v8 = *a3;
  if ( (*(_BYTE *)(a2 + 12) & 0x40) == 0 || *(_DWORD *)(a2 + 8) )
  {
    *a3 = 0;
    if ( a5 <= 0 )
      goto LABEL_10;
    do
    {
      v7 = (int)a4;
      LOBYTE(v7) = *a4;
      --a5;
      result = write_char_0((FILE *)a2, v7, a1);
      ++a4;
      if ( *a1 == -1 )
      {
        if ( *a3 != 42 )
          break;
        LOBYTE(result) = 63;
        result = write_char_0((FILE *)a2, result, a1);
      }
    }
    while ( a5 > 0 );
    if ( !*a3 )
    {
LABEL_10:
      *a3 = v8;
      return v8;
    }
  }
  else
  {
    *a1 += a5;
    return a5;
  }
  return result;
}
