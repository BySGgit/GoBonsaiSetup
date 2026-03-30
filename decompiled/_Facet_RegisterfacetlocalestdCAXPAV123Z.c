void __cdecl std::locale::facet::_Facet_Register(struct std::locale::facet *a1)
{
  std::_Fac_node *v1; // eax

  v1 = (std::_Fac_node *)operator new(8u);
  if ( v1 )
  {
    *(_DWORD *)v1 = dword_4D6D9C;
    *((_DWORD *)v1 + 1) = a1;
  }
  else
  {
    v1 = 0;
  }
  dword_4D6D9C = v1;
}
