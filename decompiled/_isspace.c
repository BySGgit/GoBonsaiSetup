int __cdecl isspace(int C)
{
  if ( dword_4D6F30 )
    return _isspace_l(C, 0);
  else
    return off_4C9B50[C] & 8;
}
