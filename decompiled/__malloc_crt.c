void *__cdecl _malloc_crt(size_t Size)
{
  DWORD v1; // esi
  void *v2; // edi
  int v3; // eax

  v1 = 0;
  do
  {
    v2 = malloc(Size);
    if ( v2 || !dword_4D6F34 )
      break;
    Sleep(v1);
    v3 = v1 + 1000;
    if ( v1 + 1000 > dword_4D6F34 )
      v3 = -1;
    v1 = v3;
  }
  while ( v3 != -1 );
  return v2;
}
