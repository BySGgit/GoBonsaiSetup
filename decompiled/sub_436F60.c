int __userpurge sub_436F60@<eax>(int a1@<eax>, int a2, int *a3)
{
  int result; // eax
  int v5; // edi
  char v6; // cl

  *a3 = a2;
  if ( !*(_BYTE *)(a1 + 12) || (result = sub_436B30(a1), result >= 0) )
  {
    result = off_4D5258[0](*(_DWORD *)(a1 + 16));
    v5 = result;
    if ( result )
    {
      result = off_4D525C(*(_DWORD *)(a1 + 16));
      if ( result )
      {
        result = *(_DWORD *)off_4D525C(*(_DWORD *)(a1 + 16));
        if ( a2 - 1 < result )
          result = a2 - 1;
        if ( result <= 0 )
        {
LABEL_12:
          *a3 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = *(_BYTE *)(result + v5);
            if ( (v6 & 8) != 0 || (v6 & 2) == 0 && (*(_BYTE *)(result + v5 - 1) & 2) != 0 )
              break;
            if ( --result <= 0 )
              goto LABEL_12;
          }
          *a3 = result;
        }
      }
    }
  }
  return result;
}
