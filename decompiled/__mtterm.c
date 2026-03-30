int _mtterm()
{
  void (__stdcall *v0)(int); // eax
  int v2; // [esp-4h] [ebp-4h]

  if ( dword_4C93F0 != -1 )
  {
    v2 = dword_4C93F0;
    v0 = (void (__stdcall *)(int))DecodePointer(dword_4D72B4);
    v0(v2);
    dword_4C93F0 = -1;
  }
  if ( dwTlsIndex != -1 )
  {
    TlsFree(dwTlsIndex);
    dwTlsIndex = -1;
  }
  return _mtdeletelocks();
}
