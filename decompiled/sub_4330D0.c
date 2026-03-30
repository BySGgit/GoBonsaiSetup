char __thiscall sub_4330D0(int this, int a2, int a3, int a4)
{
  int v6; // edi
  int v7; // eax
  void (__stdcall *v8)(int, _DWORD, int, _DWORD); // ecx
  int v9; // [esp-8h] [ebp-Ch]

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
    v6 = *(_DWORD *)(this + 24);
    v9 = *(_DWORD *)(this + 640);
    *(_BYTE *)(this + 600) = 0;
    sub_430250(v6, v9);
    v7 = *(_DWORD *)(this + 24);
    *(_BYTE *)(this + 604) = *(_BYTE *)(this + 604) == 0;
    v8 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v7 + 576);
    if ( v8 )
      v8(769, *(_DWORD *)(this + 44), this, *(_DWORD *)(v7 + 580));
  }
  return 1;
}
