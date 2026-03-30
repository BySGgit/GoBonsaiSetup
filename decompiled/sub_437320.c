int __thiscall sub_437320(_BYTE *this)
{
  if ( *(_BYTE *)(*((_DWORD *)this + 6) + 1)
    && (_BYTE *)dword_4D7F28 != this
    && (*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)this + 28))(this) )
  {
    if ( dword_4D7F28 )
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_4D7F28 + 36))(dword_4D7F28);
    (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)this + 32))(this);
    dword_4D7F28 = (int)this;
  }
  return (*(int (__thiscall **)(_BYTE *, bool, int))(*(_DWORD *)this + 80))(this, *(this + 604) == 0, 1);
}
