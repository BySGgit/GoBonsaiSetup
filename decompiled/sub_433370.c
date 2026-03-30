int __thiscall sub_433370(void **this)
{
  *this = &CDXUTComboBox::`vftable';
  sub_434340((int)this);
  if ( (int)*(this + 219) <= 0 || *(this + 218) )
  {
    if ( *(this + 218) )
    {
      free(*(this + 218));
      *(this + 218) = 0;
    }
  }
  *(this + 220) = 0;
  *(this + 219) = 0;
  *(this + 154) = &CDXUTScrollBar::`vftable';
  ((void (*)(void))sub_4325B0)();
  return sub_4325B0(this);
}
