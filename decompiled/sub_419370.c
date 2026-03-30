int __usercall sub_419370@<eax>(int a1@<edx>, _WORD *a2@<ecx>, _DWORD *a3@<edi>)
{
  int result; // eax
  int v4; // esi

  result = 0;
  if ( a1 <= 0 )
    result = -2147024809;
  if ( result < 0 )
  {
    *a3 = 0;
  }
  else
  {
    result = 0;
    v4 = a1;
    if ( !a1 )
      goto LABEL_9;
    while ( *a2 )
    {
      ++a2;
      if ( !--v4 )
        goto LABEL_9;
    }
    if ( !v4 )
LABEL_9:
      result = -2147024809;
    if ( a3 )
    {
      if ( result < 0 )
        *a3 = 0;
      else
        *a3 = a1 - v4;
    }
  }
  return result;
}
