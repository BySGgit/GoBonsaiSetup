void __thiscall std::_Fac_node::~_Fac_node(std::_Fac_node *this)
{
  void (__thiscall ***v1)(_DWORD, int); // eax

  v1 = (void (__thiscall ***)(_DWORD, int))sub_44DAD0(*((_DWORD *)this + 1));
  if ( v1 )
    (**v1)(v1, 1);
}
