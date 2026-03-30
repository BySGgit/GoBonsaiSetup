void *__cdecl GetEngineInstance()
{
  void *v0; // esi

  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    if ( !dword_4D7F04 )
    {
      v0 = operator new(0x1E80u);
      if ( v0 )
        sub_419430((int)v0);
      else
        v0 = 0;
      dword_4D7F04 = v0;
    }
    atexit(sub_4724C0);
  }
  return dword_4D7F04;
}
