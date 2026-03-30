int __thiscall sub_4372D0(_DWORD *this)
{
  if ( *(_BYTE *)(*(this + 6) + 1)
    && (_DWORD *)dword_4D7F28 != this
    && (*(unsigned __int8 (__thiscall **)(_DWORD *))(*this + 28))(this) )
  {
    if ( dword_4D7F28 )
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_4D7F28 + 36))(dword_4D7F28);
    (*(void (__thiscall **)(_DWORD *))(*this + 32))(this);
    dword_4D7F28 = (int)this;
  }
  return (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 84))(this, 1, 1, 1);
}
