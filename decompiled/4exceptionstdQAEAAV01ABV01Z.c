void **__thiscall std::exception::operator=(void **this, int a2)
{
  if ( this != (void **)a2 )
  {
    std::exception::_Tidy(this);
    if ( *(_BYTE *)(a2 + 8) )
      std::exception::_Copy_str((std::exception *)this, *(char **)(a2 + 4));
    else
      *(this + 1) = *(void **)(a2 + 4);
  }
  return this;
}
