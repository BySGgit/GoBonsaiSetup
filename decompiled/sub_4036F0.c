BOOL __userpurge sub_4036F0@<eax>(void **a1@<eax>, unsigned int a2, char a3)
{
  void **v3; // esi
  unsigned int v4; // eax
  unsigned int v6; // edi
  void **v7; // ebx

  v3 = a1;
  if ( a2 > 0x7FFFFFFE )
    std::_Xlength_error("string too long");
  v4 = (unsigned int)a1[5];
  if ( v4 >= a2 )
  {
    if ( a3 && a2 < 8 )
    {
      v6 = (unsigned int)v3[4];
      if ( a2 < v6 )
        v6 = a2;
      if ( v4 >= 8 )
      {
        v7 = (void **)*v3;
        if ( v6 )
          memcpy_0(v3, v7, 2 * v6);
        operator delete(v7);
      }
      v3[4] = (void *)v6;
      v3[5] = (void *)7;
      *((_WORD *)v3 + v6) = 0;
      return a2 != 0;
    }
    else
    {
      if ( !a2 )
      {
        v3[4] = 0;
        if ( v4 >= 8 )
          v3 = (void **)*v3;
        *(_WORD *)v3 = 0;
      }
      return a2 != 0;
    }
  }
  else
  {
    sub_403580((const void **)v3, a2, v3[4]);
    return a2 != 0;
  }
}
