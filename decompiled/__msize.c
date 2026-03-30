size_t __cdecl _msize(void *Block)
{
  if ( Block )
    return HeapSize(hHeap, 0, Block);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}
