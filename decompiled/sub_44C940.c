size_t *__thiscall sub_44C940(size_t *this, char *Src)
{
  *(this + 5) = 15;
  *(this + 4) = 0;
  *(_BYTE *)this = 0;
  sub_44C850(this, Src, strlen(Src));
  return this;
}
