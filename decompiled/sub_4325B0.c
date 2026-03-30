void __thiscall sub_4325B0(void *this)
{
  int v2; // edi

  v2 = 0;
  for ( *(_DWORD *)this = &CDXUTControl::`vftable'; v2 < *((_DWORD *)this + 9); ++v2 )
    operator delete(*(void **)(*((_DWORD *)this + 8) + 4 * v2));
  if ( *((_DWORD *)this + 8) )
  {
    free(*((void **)this + 8));
    *((_DWORD *)this + 8) = 0;
  }
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 9) = 0;
  if ( *((_DWORD *)this + 8) )
  {
    free(*((void **)this + 8));
    *((_DWORD *)this + 8) = 0;
  }
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
}
