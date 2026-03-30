void *__cdecl _realloc_crt(void *Block, size_t Size)
{
  DWORD v2; // esi
  void *v3; // edi
  int v4; // eax

  v2 = 0;
  do
  {
    v3 = realloc(Block, Size);
    if ( v3 || !Size || !dword_4D6F34 )
      break;
    Sleep(v2);
    v4 = v2 + 1000;
    if ( v2 + 1000 > dword_4D6F34 )
      v4 = -1;
    v2 = v4;
  }
  while ( v4 != -1 );
  return v3;
}
