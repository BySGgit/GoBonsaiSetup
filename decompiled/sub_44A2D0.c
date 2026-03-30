_DWORD *__userpurge sub_44A2D0@<eax>(_DWORD *a1@<esi>, _DWORD *a2, unsigned int a3, size_t Size)
{
  unsigned int v4; // eax
  size_t v5; // ebx
  size_t v6; // eax
  size_t v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  _DWORD *v10; // ecx
  _BYTE *v11; // eax
  bool v13; // cf

  v4 = a2[4];
  v5 = Size;
  if ( v4 < a3 )
    std::_Xout_of_range("invalid string position");
  v6 = v4 - a3;
  if ( v6 < Size )
    v5 = v6;
  v7 = a1[4];
  if ( -1 - v7 <= v5 )
    std::_Xlength_error("string too long");
  if ( !v5 )
    return a1;
  v8 = v7 + v5;
  if ( v7 + v5 == -1 )
    std::_Xlength_error("string too long");
  v9 = a1[5];
  if ( v9 < v8 )
  {
    sub_44C9E0((int)a1, v7 + v5, v7);
    if ( v8 )
    {
LABEL_12:
      v10 = a2;
      if ( a2[5] >= 0x10u )
        v10 = (_DWORD *)*a2;
      if ( a1[5] < 0x10u )
        v11 = a1;
      else
        v11 = (_BYTE *)*a1;
      memcpy_0(&v11[a1[4]], (char *)v10 + a3, v5);
      v13 = a1[5] < 0x10u;
      a1[4] = v8;
      if ( !v13 )
      {
        *(_BYTE *)(*a1 + v8) = 0;
        return a1;
      }
      *((_BYTE *)a1 + v8) = 0;
    }
    return a1;
  }
  if ( v8 )
    goto LABEL_12;
  a1[4] = 0;
  if ( v9 < 0x10 )
    *(_BYTE *)a1 = 0;
  else
    *(_BYTE *)*a1 = 0;
  return a1;
}
