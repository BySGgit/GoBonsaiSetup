_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, struct localeinfo_struct *a2)
{
  _DWORD *v3; // eax
  int v4; // eax

  *((_BYTE *)this + 12) = 0;
  if ( a2 )
  {
    *(_DWORD *)this = *(_DWORD *)a2;
    *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  }
  else
  {
    v3 = (_DWORD *)_getptd();
    *((_DWORD *)this + 2) = v3;
    *(_DWORD *)this = v3[27];
    *((_DWORD *)this + 1) = v3[26];
    if ( *(volatile LONG **)this != off_4C9B60 && (dword_4C9918 & v3[28]) == 0 )
      *(_DWORD *)this = __updatetlocinfo();
    if ( *((volatile LONG **)this + 1) != lpAddend && (dword_4C9918 & *(_DWORD *)(*((_DWORD *)this + 2) + 112)) == 0 )
      *((_DWORD *)this + 1) = __updatetmbcinfo();
    v4 = *((_DWORD *)this + 2);
    if ( (*(_BYTE *)(v4 + 112) & 2) == 0 )
    {
      *(_DWORD *)(v4 + 112) |= 2u;
      *((_BYTE *)this + 12) = 1;
    }
  }
  return this;
}
