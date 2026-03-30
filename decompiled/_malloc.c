void *__cdecl malloc(size_t Size)
{
  SIZE_T v1; // eax
  void *v2; // edi

  if ( Size > 0xFFFFFFE0 )
  {
    _callnewh(Size);
    *_errno() = 12;
    return 0;
  }
  else
  {
    while ( 1 )
    {
      if ( !hHeap )
      {
        _FF_MSGBANNER();
        _NMSG_WRITE(30);
        __crtExitProcess(0xFFu);
      }
      v1 = Size ? Size : 1;
      v2 = HeapAlloc(hHeap, 0, v1);
      if ( v2 )
        return v2;
      if ( !dword_4D72DC )
      {
        *_errno() = 12;
LABEL_12:
        *_errno() = 12;
        return v2;
      }
      if ( !_callnewh(Size) )
        goto LABEL_12;
    }
  }
}
