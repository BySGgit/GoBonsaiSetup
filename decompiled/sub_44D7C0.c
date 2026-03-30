int __thiscall sub_44D7C0(_DWORD **this)
{
  unsigned __int16 **v3; // esi
  unsigned __int16 *v4; // eax

  if ( ((unsigned __int16 (__thiscall *)(_DWORD **))(*this)[6])(this) == 0xFFFF )
    return 0xFFFF;
  --**(this + 12);
  v3 = (unsigned __int16 **)*(this + 8);
  v4 = (*v3)++;
  return *v4;
}
