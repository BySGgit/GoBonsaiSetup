_DWORD *__cdecl sub_44C4D0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *Src; // ecx
  _DWORD *i; // edi

  for ( i = Src; i != a1; i += 7 )
  {
    if ( a2 )
    {
      a2[5] = 7;
      a2[4] = 0;
      *(_WORD *)a2 = 0;
      if ( a2 != i )
      {
        if ( a2[5] >= 8u )
          operator delete((void *)*a2);
        a2[5] = 7;
        a2[4] = 0;
        *(_WORD *)a2 = 0;
        if ( i[5] >= 8u )
        {
          *a2 = *i;
          *i = 0;
        }
        else
        {
          memcpy(a2, i, 2 * i[4] + 2);
        }
        a2[4] = i[4];
        a2[5] = i[5];
        i[5] = 7;
        i[4] = 0;
        *(_WORD *)i = 0;
      }
    }
    a2 += 7;
  }
  return a2;
}
