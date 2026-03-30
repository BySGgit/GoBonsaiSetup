void __thiscall std::exception::_Tidy(void **this)
{
  if ( *((_BYTE *)this + 8) )
    free(*(this + 1));
  *(this + 1) = 0;
  *((_BYTE *)this + 8) = 0;
}
