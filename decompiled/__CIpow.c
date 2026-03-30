double __usercall _CIpow@<st0>(double x@<st0>, unsigned __int64 y@<st1>)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+Ch] [ebp-8h]

  if ( !dword_4DBF00 )
    goto __CIpow_default;
  v2 = _mm_getcsr() & 0x7F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
  {
    _CIpow_pentium4();
  }
  else
  {
__CIpow_default:
    start_0(LODWORD(x), HIDWORD(*(unsigned __int64 *)&x), y, HIDWORD(y));
    return *(double *)&y;
  }
  return x;
}
