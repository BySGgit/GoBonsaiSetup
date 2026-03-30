void __thiscall sub_4440F0(_DWORD *this)
{
  _DWORD **v2; // ecx
  _DWORD *v3; // eax
  _DWORD *v4; // edi

  v2 = (_DWORD **)*this;
  v3 = *v2;
  *v2 = v2;
  *(_DWORD *)(*this + 4) = *this;
  *(this + 1) = 0;
  if ( v3 != (_DWORD *)*this )
  {
    do
    {
      v4 = (_DWORD *)*v3;
      operator delete(v3);
      v3 = v4;
    }
    while ( v4 != (_DWORD *)*this );
  }
  operator delete((void *)*this);
}
