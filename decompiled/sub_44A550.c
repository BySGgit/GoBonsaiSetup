int __thiscall sub_44A550(void *this, int a2)
{
  _DWORD *v2; // eax
  struct std::locale::facet *v3; // eax
  int v4; // edi
  struct std::locale::facet *v5; // ebx
  int v6; // eax
  int v7; // esi
  void (__thiscall ***v8)(_DWORD, int); // esi
  _BYTE v10[4]; // [esp+10h] [ebp-10h] BYREF
  int v11; // [esp+1Ch] [ebp-4h]

  v2 = sub_44DB70(a2, (int)this, &a2);
  v3 = sub_44D670((int)v2);
  v11 = -1;
  v4 = a2;
  v5 = v3;
  if ( a2 )
  {
    std::_Lockit::_Lockit((std::_Lockit *)v10, 0);
    v6 = *(_DWORD *)(v4 + 4);
    if ( v6 && v6 != -1 )
      *(_DWORD *)(v4 + 4) = v6 - 1;
    v7 = -(*(_DWORD *)(v4 + 4) == 0);
    std::_Lockit::~_Lockit((std::_Lockit *)v10);
    v8 = (void (__thiscall ***)(_DWORD, int))(v4 & v7);
    if ( v8 )
      (**v8)(v8, 1);
  }
  return (*(int (__thiscall **)(struct std::locale::facet *, int))(*(_DWORD *)v5 + 40))(v5, 32);
}
