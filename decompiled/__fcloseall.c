int __cdecl _fcloseall()
{
  int i; // edi
  int v1; // eax
  int v3; // [esp+14h] [ebp-1Ch]

  v3 = 0;
  _lock(1);
  for ( i = 3; i < dword_4DCF20; ++i )
  {
    if ( *(_DWORD *)(dword_4DBF04 + 4 * i) )
    {
      v1 = *(_DWORD *)(dword_4DBF04 + 4 * i);
      if ( (*(_BYTE *)(v1 + 12) & 0x83) != 0 && fclose((FILE *)v1) != -1 )
        ++v3;
      if ( i >= 20 )
      {
        DeleteCriticalSection((LPCRITICAL_SECTION)(*(_DWORD *)(dword_4DBF04 + 4 * i) + 32));
        free(*(void **)(dword_4DBF04 + 4 * i));
        *(_DWORD *)(dword_4DBF04 + 4 * i) = 0;
      }
    }
  }
  _unlock(1);
  return v3;
}
