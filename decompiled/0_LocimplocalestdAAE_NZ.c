std::locale::_Locimp *__thiscall std::locale::_Locimp::_Locimp(std::locale::_Locimp *this, bool a2)
{
  void **v3; // ecx

  *((_BYTE *)this + 20) = a2;
  v3 = (void **)((char *)this + 24);
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &off_4735B8;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *v3 = 0;
  *((_BYTE *)v3 + 4) = 0;
  std::_Yarn<char>::operator=(v3, byte_4735B0);
  return this;
}
