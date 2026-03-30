wint_t __usercall _whiteout@<ax>(_DWORD *a1@<esi>, FILE *Stream)
{
  wint_t v2; // di

  do
  {
    ++*a1;
    v2 = _fgetwc_nolock(Stream);
  }
  while ( v2 != 0xFFFF && iswctype(v2, 8u) );
  return v2;
}
