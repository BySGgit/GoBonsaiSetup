_DWORD *__thiscall sub_44C6E0(_DWORD *this, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // edx
  _DWORD *v8; // ebx
  _DWORD *v9; // edx
  unsigned int v10; // eax
  bool v11; // cf

  v4 = *(this + 4);
  if ( v4 < a2 )
    std::_Xout_of_range("invalid string position");
  v5 = a3;
  v6 = v4 - a2;
  if ( v6 < a3 )
    v5 = v6;
  if ( v5 )
  {
    v7 = *(this + 5);
    if ( v7 < 0x10 )
      v8 = this;
    else
      v8 = (_DWORD *)*this;
    if ( v7 < 0x10 )
      v9 = this;
    else
      v9 = (_DWORD *)*this;
    memcpy((char *)v9 + a2, (char *)v8 + a2 + v5, v6 - v5);
    v10 = *(this + 4) - v5;
    v11 = *(this + 5) < 0x10u;
    *(this + 4) = v10;
    if ( !v11 )
    {
      *(_BYTE *)(*this + v10) = 0;
      return this;
    }
    *((_BYTE *)this + v10) = 0;
  }
  return this;
}
