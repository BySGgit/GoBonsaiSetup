void __cdecl _Atexit(PVOID Ptr)
{
  if ( !dword_4C9150 )
    abort();
  --dword_4C9150;
  dword_4D6EE0[dword_4C9150] = EncodePointer(Ptr);
}
