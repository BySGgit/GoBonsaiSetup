std::exception *__thiscall sub_44DD00(std::exception *this, struct exception *a2)
{
  std::exception::exception(this, a2);
  *(_DWORD *)this = &std::system_error::`vftable';
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)this + 4) = *((_DWORD *)a2 + 4);
  *(_DWORD *)this = &std::ios_base::failure::`vftable';
  return this;
}
