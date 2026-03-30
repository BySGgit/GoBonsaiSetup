int __cdecl _calloc_crt(int a1, int a2)
{
  DWORD v2; // esi
  int v3; // edi
  int v4; // eax

  v2 = 0;
  do
  {
    v3 = _calloc_impl(a1, a2, 0);
    if ( v3 || !dword_4D6F34 )
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
