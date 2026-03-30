char __thiscall sub_432CC0(_BYTE *this, int a2, int a3, int a4)
{
  void (__stdcall *v5)(BOOL, int); // eax
  BOOL v6; // [esp-8h] [ebp-8h]

  if ( !*(this + 60) || !*(this + 4) )
    return 0;
  if ( a2 == 256 )
  {
    if ( a3 == 32 )
    {
      *(this + 600) = 1;
      return 1;
    }
    return 0;
  }
  if ( a2 != 257 || a3 != 32 )
    return 0;
  if ( *(this + 600) == 1 )
  {
    v5 = *(void (__stdcall **)(BOOL, int))(*(_DWORD *)this + 80);
    v6 = *(this + 604) == 0;
    *(this + 600) = 0;
    v5(v6, 1);
  }
  return 1;
}
