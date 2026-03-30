void __thiscall sub_44CFA0(void *this)
{
  int *v2; // ebx
  int v3; // edi
  int v4; // eax
  int v5; // esi
  void (__thiscall ***v6)(_DWORD, int); // esi
  _BYTE v7[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = (int *)*((_DWORD *)this + 14);
  *(_DWORD *)this = &std::wstreambuf::`vftable';
  if ( v2 )
  {
    v3 = *v2;
    if ( *v2 )
    {
      std::_Lockit::_Lockit((std::_Lockit *)v7, 0);
      v4 = *(_DWORD *)(v3 + 4);
      if ( v4 && v4 != -1 )
        *(_DWORD *)(v3 + 4) = v4 - 1;
      v5 = -(*(_DWORD *)(v3 + 4) == 0);
      std::_Lockit::~_Lockit((std::_Lockit *)v7);
      v6 = (void (__thiscall ***)(_DWORD, int))(v3 & v5);
      if ( v6 )
        (**v6)(v6, 1);
    }
    operator delete(v2);
  }
  _Mtxdst(*((LPCRITICAL_SECTION *)this + 1));
  operator delete(*((void **)this + 1));
}
