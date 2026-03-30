BOOL __thiscall sub_44D8B0(int this, unsigned __int16 a2, wchar_t a3)
{
  return ((unsigned __int16)_Getwctype(a3, (const _Ctypevec *)(this + 8)) & a2) != 0;
}
