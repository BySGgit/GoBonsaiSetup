struct std::locale::_Locimp *__cdecl std::locale::_Init()
{
  std::locale::_Locimp *v0; // esi
  int v1; // edi
  std::locale::_Locimp *v2; // eax
  _BYTE v4[12]; // [esp+14h] [ebp-10h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  v0 = 0;
  v1 = dword_4D6DA0;
  if ( !dword_4D6DA0 )
  {
    std::_Lockit::_Lockit((std::_Lockit *)v4, 0);
    v5 = 0;
    v1 = dword_4D6DA0;
    if ( !dword_4D6DA0 )
    {
      v2 = (std::locale::_Locimp *)operator new(0x20u);
      if ( v2 )
        v0 = std::locale::_Locimp::_Locimp(v2, 0);
      v1 = (int)v0;
      std::locale::_Setgloballocale(v0);
      *((_DWORD *)v0 + 4) = 63;
      std::_Yarn<char>::operator=((void **)v0 + 6, "C");
      dword_4D6DA4 = (int)v0;
      sub_44DAA0(v0);
      dword_4D6DBC = dword_4D6DA4;
    }
    v5 = -1;
    std::_Lockit::~_Lockit((std::_Lockit *)v4);
  }
  return (struct std::locale::_Locimp *)v1;
}
