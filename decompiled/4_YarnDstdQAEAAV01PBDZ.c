void **__thiscall std::_Yarn<char>::operator=(void **this, _BYTE *Src)
{
  _BYTE *i; // eax
  size_t v4; // ebx
  void *v5; // eax

  if ( *this != Src )
  {
    if ( *this )
      free(*this);
    *this = 0;
    if ( Src )
    {
      for ( i = Src; *i; ++i )
        ;
      v4 = i - Src + 1;
      v5 = malloc(v4);
      *this = v5;
      if ( v5 )
        memcpy_0(v5, Src, v4);
    }
  }
  return this;
}
