int __cdecl _initptd(int a1, int a2)
{
  int savedregs; // [esp+28h] [ebp+0h]

  GetModuleHandleW(&off_474084);
  *(_DWORD *)(a1 + 92) = &unk_474EA8;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 20) = 1;
  *(_DWORD *)(a1 + 112) = 1;
  *(_BYTE *)(a1 + 200) = 67;
  *(_BYTE *)(a1 + 331) = 67;
  *(_DWORD *)(a1 + 104) = &unk_4C93F8;
  _lock(13);
  InterlockedIncrement(*(volatile LONG **)(a1 + 104));
  _unlock(13);
  _lock(12);
  *(_DWORD *)(a1 + 108) = a2;
  if ( !a2 )
    *(_DWORD *)(a1 + 108) = off_4C9B60;
  __addlocaleref(*(volatile LONG **)(a1 + 108));
  savedregs = 4563500;
  return _unlock(12);
}
