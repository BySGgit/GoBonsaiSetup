void *__cdecl _recalloc_crt(void *Block, size_t Count, size_t Size)
{
  DWORD v3; // esi
  void *v4; // edi
  int v5; // eax

  v3 = 0;
  do
  {
    v4 = _recalloc(Block, Count, Size);
    if ( v4 || !Size || !dword_4D6F34 )
      break;
    Sleep(v3);
    v5 = v3 + 1000;
    if ( v3 + 1000 > dword_4D6F34 )
      v5 = -1;
    v3 = v5;
  }
  while ( v5 != -1 );
  return v4;
}
