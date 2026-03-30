void __thiscall std::exception::_Copy_str(std::exception *this, char *Str)
{
  size_t v3; // esi
  char *v4; // eax

  if ( Str )
  {
    v3 = strlen(Str) + 1;
    v4 = (char *)malloc(v3);
    *((_DWORD *)this + 1) = v4;
    if ( v4 )
    {
      strcpy_s(v4, v3, Str);
      *((_BYTE *)this + 8) = 1;
    }
  }
}
