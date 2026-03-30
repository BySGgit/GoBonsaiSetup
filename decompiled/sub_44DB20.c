void __thiscall sub_44DB20(int *this)
{
  int v1; // edi
  int v2; // eax
  int v3; // esi
  void (__thiscall ***v4)(_DWORD, int); // esi
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  v1 = *this;
  if ( *this )
  {
    std::_Lockit::_Lockit((std::_Lockit *)v5, 0);
    v2 = *(_DWORD *)(v1 + 4);
    if ( v2 && v2 != -1 )
      *(_DWORD *)(v1 + 4) = v2 - 1;
    v3 = -(*(_DWORD *)(v1 + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)v5);
    v4 = (void (__thiscall ***)(_DWORD, int))(v1 & v3);
    if ( v4 )
      (**v4)(v4, 1);
  }
}
