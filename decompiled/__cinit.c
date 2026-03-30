int __cdecl _cinit(int a1)
{
  int result; // eax
  void (**v2)(void); // edi

  if ( _fpmath && _IsNonwritableInCurrentImage(&off_474050) )
    _fpmath(a1);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e((_PIFV *)&First, (_PIFV *)&Last);
  if ( !result )
  {
    atexit(sub_45DE99);
    v2 = (void (**)(void))&unk_473340;
    if ( &unk_473340 < (_UNKNOWN *)&dword_473460 )
    {
      do
      {
        if ( *v2 )
          (*v2)();
        ++v2;
      }
      while ( v2 < &dword_473460 );
    }
    if ( dword_4DD050 )
    {
      if ( _IsNonwritableInCurrentImage(&dword_4DD050) )
        dword_4DD050(0, 2, 0);
    }
    return 0;
  }
  return result;
}
