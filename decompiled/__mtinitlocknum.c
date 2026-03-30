int __cdecl _mtinitlocknum(int a1)
{
  struct _RTL_CRITICAL_SECTION *v2; // edi
  int v3; // [esp+10h] [ebp-1Ch]

  v3 = 1;
  if ( !hHeap )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(30);
    __crtExitProcess(0xFFu);
  }
  if ( *(&lpCriticalSection + 2 * a1) )
    return 1;
  v2 = (struct _RTL_CRITICAL_SECTION *)_malloc_crt(0x18u);
  if ( v2 )
  {
    _lock(10);
    if ( *(&lpCriticalSection + 2 * a1) )
    {
      free(v2);
    }
    else if ( InitializeCriticalSectionAndSpinCount(v2, 0xFA0u) )
    {
      *(&lpCriticalSection + 2 * a1) = v2;
    }
    else
    {
      free(v2);
      *_errno() = 12;
      v3 = 0;
    }
    _unlock(10);
    return v3;
  }
  else
  {
    *_errno() = 12;
    return 0;
  }
}
