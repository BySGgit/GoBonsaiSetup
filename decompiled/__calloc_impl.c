LPVOID __cdecl _calloc_impl(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  LPVOID result; // eax
  SIZE_T v4; // esi

  if ( a1 && 0xFFFFFFE0 / a1 < a2 )
  {
    *_errno() = 12;
    return 0;
  }
  else
  {
    v4 = a2 * a1;
    if ( !(a2 * a1) )
      v4 = 1;
    while ( 1 )
    {
      result = 0;
      if ( v4 <= 0xFFFFFFE0 )
      {
        result = HeapAlloc(hHeap, 8u, v4);
        if ( result )
          break;
      }
      if ( !dword_4D72DC )
      {
        if ( a3 )
          *a3 = 12;
        return result;
      }
      if ( !_callnewh(v4) )
      {
        if ( a3 )
          *a3 = 12;
        return 0;
      }
    }
  }
  return result;
}
