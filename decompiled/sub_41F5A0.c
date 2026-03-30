char __usercall sub_41F5A0@<al>(_DWORD *a1@<edi>, _DWORD *a2@<esi>, int a3, int a4)
{
  if ( a2 && *a2 == *a1 )
  {
    if ( *a1 )
    {
      if ( sub_41B550()
        && (!a4 || a4 == sub_41B550())
        && a2[1] == a1[1]
        && a2[2] == a1[2]
        && a2[19] == a1[19]
        && a2[11] == a1[11]
        && a2[12] == a1[12] )
      {
        return 1;
      }
    }
    else if ( sub_41B510() && (!a3 || a3 == sub_41B510()) && a2[1] == a1[1] && a2[2] == a1[2] && a2[4] == a1[4] )
    {
      return 1;
    }
  }
  return 0;
}
