size_t *__thiscall sub_44C760(size_t *this, size_t *a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // edi
  unsigned int v6; // edi
  unsigned int v8; // eax
  size_t *v9; // ecx
  size_t *v10; // eax
  bool v11; // cf

  v4 = a2[4];
  if ( v4 < a3 )
    std::_Xout_of_range("invalid string position");
  v6 = v4 - a3;
  if ( a4 < v6 )
    v6 = a4;
  if ( this == a2 )
  {
    sub_44C6E0(this, a3 + v6, 0xFFFFFFFF);
    sub_44C6E0(this, 0, a3);
    return this;
  }
  if ( v6 == -1 )
    std::_Xlength_error("string too long");
  v8 = *(this + 5);
  if ( v8 < v6 )
  {
    sub_44C9E0((int)this, v6, *(this + 4));
    if ( !v6 )
      return this;
LABEL_11:
    if ( a2[5] < 0x10 )
      v9 = a2;
    else
      v9 = (size_t *)*a2;
    if ( *(this + 5) < 0x10 )
      v10 = this;
    else
      v10 = (size_t *)*this;
    memcpy_0(v10, (char *)v9 + a3, v6);
    v11 = *(this + 5) < 0x10;
    *(this + 4) = v6;
    if ( !v11 )
    {
      *(_BYTE *)(*this + v6) = 0;
      return this;
    }
    *((_BYTE *)this + v6) = 0;
    return this;
  }
  if ( v6 )
    goto LABEL_11;
  *(this + 4) = 0;
  if ( v8 < 0x10 )
    *(_BYTE *)this = 0;
  else
    *(_BYTE *)*this = 0;
  return this;
}
