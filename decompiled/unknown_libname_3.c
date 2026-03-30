// Microsoft VisualC 2-14/net runtime
void unknown_libname_3()
{
  std::_Fac_node *v0; // esi
  std::_Fac_node *v1; // ecx
  _BYTE v2[12]; // [esp+10h] [ebp-10h] BYREF
  int v3; // [esp+1Ch] [ebp-4h]

  std::_Lockit::_Lockit((std::_Lockit *)v2, 0);
  v3 = 0;
  while ( dword_4D6D9C )
  {
    v0 = dword_4D6D9C;
    v1 = dword_4D6D9C;
    dword_4D6D9C = *(std::_Fac_node **)dword_4D6D9C;
    std::_Fac_node::~_Fac_node(v1);
    operator delete(v0);
  }
  v3 = -1;
  std::_Lockit::~_Lockit((std::_Lockit *)v2);
}
