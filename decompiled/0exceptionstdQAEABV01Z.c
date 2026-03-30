std::exception *__thiscall std::exception::exception(std::exception *this, const struct exception *a2)
{
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = &off_473664;
  *((_BYTE *)this + 8) = 0;
  std::exception::operator=((void **)this, (int)a2);
  return this;
}
