char __thiscall sub_432940(int this, int a2, int a3, int a4)
{
  int v5; // eax
  void (__stdcall *v6)(int, _DWORD, int, _DWORD); // edx

  if ( !*(_BYTE *)(this + 60) || !*(_BYTE *)(this + 4) )
    return 0;
  if ( a2 == 256 )
  {
    if ( a3 == 32 )
    {
      *(_BYTE *)(this + 600) = 1;
      return 1;
    }
    return 0;
  }
  if ( a2 != 257 || a3 != 32 )
    return 0;
  if ( *(_BYTE *)(this + 600) == 1 )
  {
    v5 = *(_DWORD *)(this + 24);
    *(_BYTE *)(this + 600) = 0;
    v6 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v5 + 576);
    if ( v6 )
      v6(257, *(_DWORD *)(this + 44), this, *(_DWORD *)(v5 + 580));
  }
  return 1;
}
