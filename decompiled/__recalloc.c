void *__cdecl _recalloc(void *Block, size_t Count, size_t Size)
{
  size_t v3; // ebx
  size_t v5; // esi
  char *v6; // eax
  void *v7; // edi

  v3 = 0;
  if ( Count && 0xFFFFFFE0 / Count < Size )
  {
    *_errno() = 12;
    return 0;
  }
  else
  {
    v5 = Size * Count;
    if ( Block )
      v3 = _msize(Block);
    v6 = (char *)realloc(Block, v5);
    v7 = v6;
    if ( v6 )
    {
      if ( v3 < v5 )
        memset(&v6[v3], 0, v5 - v3);
    }
    return v7;
  }
}
