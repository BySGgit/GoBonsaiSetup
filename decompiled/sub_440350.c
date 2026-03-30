void __thiscall sub_440350(char *this)
{
  struct std::ios_base *v1; // [esp+Ch] [ebp-10h]

  v1 = (struct std::ios_base *)(this + 96);
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*(_DWORD *)this + 4) - 96) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  sub_4443F0(this + 24);
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*((_DWORD *)v1 - 24) + 4) - 96) = &std::wiostream::`vftable';
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*((_DWORD *)v1 - 20) + 4) - 80) = &std::wostream::`vftable';
  *(_DWORD *)((char *)v1 + *(_DWORD *)(*((_DWORD *)v1 - 24) + 4) - 96) = &std::wistream::`vftable';
  *(_DWORD *)v1 = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(v1);
}
