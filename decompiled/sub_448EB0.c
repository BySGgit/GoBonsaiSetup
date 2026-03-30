_DWORD *__userpurge sub_448EB0@<eax>(_DWORD *a1@<esi>, size_t Size, char a3)
{
  size_t v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // ecx
  int v6; // ecx
  _DWORD *v8; // eax
  bool v9; // cf

  v3 = a1[4];
  if ( -1 - v3 <= Size )
    std::_Xlength_error("string too long");
  if ( !Size )
    return a1;
  v4 = v3 + Size;
  if ( v3 + Size == -1 )
    std::_Xlength_error("string too long");
  v5 = a1[5];
  if ( v5 < v4 )
  {
    sub_44C9E0((int)a1, v3 + Size, v3);
    if ( v4 )
    {
LABEL_8:
      v6 = a1[4];
      if ( Size == 1 )
      {
        if ( a1[5] < 0x10u )
          *((_BYTE *)a1 + v6) = a3;
        else
          *(_BYTE *)(*a1 + v6) = a3;
      }
      else
      {
        if ( a1[5] < 0x10u )
          v8 = a1;
        else
          v8 = (_DWORD *)*a1;
        memset((char *)v8 + v6, a3, Size);
      }
      v9 = a1[5] < 0x10u;
      a1[4] = v4;
      if ( !v9 )
      {
        *(_BYTE *)(*a1 + v4) = 0;
        return a1;
      }
      *((_BYTE *)a1 + v4) = 0;
    }
    return a1;
  }
  if ( v4 )
    goto LABEL_8;
  a1[4] = 0;
  if ( v5 < 0x10 )
    *(_BYTE *)a1 = 0;
  else
    *(_BYTE *)*a1 = 0;
  return a1;
}
