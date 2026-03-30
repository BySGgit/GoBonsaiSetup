size_t *__thiscall sub_44C850(size_t *this, _BYTE *Src, size_t Size)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  size_t *v6; // eax
  size_t v8; // eax
  size_t *v9; // eax
  bool v10; // cf

  if ( Src )
  {
    v4 = *(this + 5);
    v5 = v4 < 0x10 ? (unsigned int)this : *this;
    if ( (unsigned int)Src >= v5 )
    {
      v6 = v4 < 0x10 ? this : (size_t *)*this;
      if ( (char *)v6 + *(this + 4) > Src )
      {
        if ( v4 < 0x10 )
          return sub_44C760(this, this, Src - (_BYTE *)this, Size);
        else
          return sub_44C760(this, this, (unsigned int)&Src[-*this], Size);
      }
    }
  }
  if ( Size == -1 )
    std::_Xlength_error("string too long");
  v8 = *(this + 5);
  if ( v8 < Size )
  {
    sub_44C9E0((int)this, Size, *(this + 4));
    if ( !Size )
      return this;
LABEL_17:
    if ( *(this + 5) < 0x10 )
      v9 = this;
    else
      v9 = (size_t *)*this;
    memcpy_0(v9, Src, Size);
    v10 = *(this + 5) < 0x10;
    *(this + 4) = Size;
    if ( !v10 )
    {
      *(_BYTE *)(*this + Size) = 0;
      return this;
    }
    *((_BYTE *)this + Size) = 0;
    return this;
  }
  if ( Size )
    goto LABEL_17;
  *(this + 4) = 0;
  if ( v8 < 0x10 )
    *(_BYTE *)this = 0;
  else
    *(_BYTE *)*this = 0;
  return this;
}
