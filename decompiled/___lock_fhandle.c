BOOL __cdecl __lock_fhandle(int a1)
{
  int v1; // esi
  BOOL v3; // [esp+10h] [ebp-1Ch]

  v1 = dword_4DCF40[a1 >> 5] + ((a1 & 0x1F) << 6);
  v3 = 1;
  if ( !*(_DWORD *)(v1 + 8) )
  {
    _lock(10);
    if ( !*(_DWORD *)(v1 + 8) )
    {
      v3 = InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(v1 + 12), 0xFA0u);
      ++*(_DWORD *)(v1 + 8);
    }
    _unlock(10);
  }
  if ( v3 )
    EnterCriticalSection((LPCRITICAL_SECTION)(dword_4DCF40[a1 >> 5] + ((a1 & 0x1F) << 6) + 12));
  return v3;
}
