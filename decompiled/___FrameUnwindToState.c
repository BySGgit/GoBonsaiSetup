int __cdecl __FrameUnwindToState(int a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int result; // eax
  int v9; // [esp-4h] [ebp-34h]

  if ( *(int *)(a3 + 4) > 128 )
    v4 = *(_DWORD *)(a1 + 8);
  else
    v4 = *(char *)(a1 + 8);
  v5 = ((int (*)(void))_getptd)();
  ++*(_DWORD *)(v5 + 144);
  while ( v4 != a4 )
  {
    if ( v4 <= -1 || v4 >= *(_DWORD *)(a3 + 4) )
      _inconsistency();
    v6 = v4;
    v7 = *(_DWORD *)(a3 + 8);
    v4 = *(_DWORD *)(v7 + 8 * v4);
    if ( *(_DWORD *)(v7 + 8 * v6 + 4) )
    {
      *(_DWORD *)(a1 + 8) = v4;
      _CallSettingFrame(*(_DWORD *)(*(_DWORD *)(a3 + 8) + 8 * v6 + 4), a1, 259);
    }
  }
  result = _getptd(4546381);
  if ( *(int *)(result + 144) > 0 )
  {
    result = _getptd(v9);
    --*(_DWORD *)(result + 144);
  }
  if ( v4 != a4 )
    _inconsistency();
  *(_DWORD *)(a1 + 8) = v4;
  return result;
}
