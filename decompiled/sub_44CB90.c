int *__userpurge sub_44CB90@<eax>(unsigned int a1@<eax>, int *a2@<edi>, unsigned int Size, char a4)
{
  size_t v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int v9; // ecx
  int *v11; // eax
  bool v12; // cf

  v5 = a2[4];
  if ( v5 < a1 )
    std::_Xout_of_range("invalid string position");
  if ( -1 - v5 <= Size )
    std::_Xlength_error("string too long");
  if ( !Size )
    return a2;
  v6 = v5 + Size;
  if ( v5 + Size == -1 )
    std::_Xlength_error("string too long");
  v7 = a2[5];
  if ( v7 < v6 )
  {
    sub_44C9E0((int)a2, v5 + Size, v5);
    if ( v6 )
    {
LABEL_10:
      v8 = a2[5];
      if ( v8 < 0x10 )
        v9 = (int)a2;
      else
        v9 = *a2;
      if ( v8 < 0x10 )
        v11 = a2;
      else
        v11 = (int *)*a2;
      memcpy((char *)v11 + a1 + Size, (const void *)(a1 + v9), a2[4] - a1);
      sub_44CB50(Size, a4, a1, a2);
      v12 = (unsigned int)a2[5] < 0x10;
      a2[4] = v6;
      if ( !v12 )
      {
        *(_BYTE *)(*a2 + v6) = 0;
        return a2;
      }
      *((_BYTE *)a2 + v6) = 0;
    }
    return a2;
  }
  if ( v6 )
    goto LABEL_10;
  a2[4] = 0;
  if ( v7 < 0x10 )
    *(_BYTE *)a2 = 0;
  else
    *(_BYTE *)*a2 = 0;
  return a2;
}
