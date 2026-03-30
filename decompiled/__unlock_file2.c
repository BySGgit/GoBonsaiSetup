void __cdecl _unlock_file2(int a1, int a2)
{
  if ( a1 >= 20 )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 32));
  }
  else
  {
    *(_DWORD *)(a2 + 12) &= ~0x8000u;
    _unlock(a1 + 16);
  }
}
