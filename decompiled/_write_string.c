__int16 __usercall write_string@<ax>(_DWORD *a1@<eax>, int a2@<ebx>, int *a3@<edi>, wchar_t *a4, int a5)
{
  __int16 result; // ax
  int v7; // [esp+4h] [ebp-4h]

  v7 = *a3;
  if ( (*(_BYTE *)(a2 + 12) & 0x40) == 0 || *(_DWORD *)(a2 + 8) )
  {
    *a3 = 0;
    if ( a5 <= 0 )
      goto LABEL_10;
    do
    {
      --a5;
      result = write_char(a2, a1, *a4++);
      if ( *a1 == -1 )
      {
        if ( *a3 != 42 )
          break;
        result = write_char(a2, a1, 0x3Fu);
      }
    }
    while ( a5 > 0 );
    if ( !*a3 )
    {
LABEL_10:
      *a3 = v7;
      return v7;
    }
  }
  else
  {
    *a1 += a5;
    return a5;
  }
  return result;
}
