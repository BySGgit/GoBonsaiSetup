double __cdecl cos(double X)
{
  int v1; // ecx
  int v2; // eax
  bool v3; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( dword_4DBF00 )
  {
    v2 = _mm_getcsr() & 0x7F80;
    v3 = v2 == 8064;
    if ( v2 == 8064 )
      v3 = (v5 & 0x7F) == 127;
    if ( v3 )
      return start_6(X);
  }
  _fload_withFB(v1);
  return start_2(X);
}
