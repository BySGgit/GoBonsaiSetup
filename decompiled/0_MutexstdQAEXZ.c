std::_Mutex *__thiscall std::_Mutex::_Mutex(std::_Mutex *this)
{
  struct _RTL_CRITICAL_SECTION *v2; // eax

  v2 = (struct _RTL_CRITICAL_SECTION *)operator new(0x18u);
  *(_DWORD *)this = v2;
  _Mtxinit(v2);
  return this;
}
