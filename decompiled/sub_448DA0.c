_DWORD *__userpurge sub_448DA0@<eax>(_DWORD *a1@<eax>, _BYTE *Src, size_t Size)
{
  _DWORD *v3; // esi
  unsigned int v4; // ecx
  _DWORD *v5; // eax
  size_t v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  _DWORD *v10; // eax
  bool v11; // cf

  v3 = a1;
  if ( Src )
  {
    v4 = a1[5];
    if ( v4 >= 0x10 )
      a1 = (_DWORD *)*a1;
    if ( Src >= (_BYTE *)a1 )
    {
      v5 = v4 < 0x10 ? v3 : (_DWORD *)*v3;
      if ( (char *)v5 + v3[4] > Src )
      {
        if ( v4 < 0x10 )
          return sub_44A2D0(v3, v3, Src - (_BYTE *)v3, Size);
        else
          return sub_44A2D0(v3, v3, (unsigned int)&Src[-*v3], Size);
      }
    }
  }
  v7 = v3[4];
  if ( -1 - v7 <= Size )
    std::_Xlength_error("string too long");
  if ( !Size )
    return v3;
  v8 = v7 + Size;
  if ( v7 + Size == -1 )
    std::_Xlength_error("string too long");
  v9 = v3[5];
  if ( v9 < v8 )
  {
    sub_44C9E0((int)v3, v7 + Size, v7);
    if ( v8 )
    {
LABEL_19:
      if ( v3[5] < 0x10u )
        v10 = v3;
      else
        v10 = (_DWORD *)*v3;
      memcpy_0((char *)v10 + v3[4], Src, Size);
      v11 = v3[5] < 0x10u;
      v3[4] = v8;
      if ( !v11 )
      {
        *(_BYTE *)(*v3 + v8) = 0;
        return v3;
      }
      *((_BYTE *)v3 + v8) = 0;
    }
    return v3;
  }
  if ( v8 )
    goto LABEL_19;
  v3[4] = 0;
  if ( v9 < 0x10 )
    *(_BYTE *)v3 = 0;
  else
    *(_BYTE *)*v3 = 0;
  return v3;
}
