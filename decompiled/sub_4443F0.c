void __thiscall sub_4443F0(void *this)
{
  bool v2; // zf

  v2 = (*((_BYTE *)this + 64) & 1) == 0;
  *(_DWORD *)this = &std::wstringbuf::`vftable';
  if ( !v2 )
    operator delete(**((void ***)this + 4));
  **((_DWORD **)this + 4) = 0;
  **((_DWORD **)this + 8) = 0;
  **((_DWORD **)this + 12) = 0;
  **((_DWORD **)this + 5) = 0;
  **((_DWORD **)this + 9) = 0;
  **((_DWORD **)this + 13) = 0;
  *((_DWORD *)this + 16) &= ~1u;
  *((_DWORD *)this + 15) = 0;
  sub_44CFA0(this);
}
