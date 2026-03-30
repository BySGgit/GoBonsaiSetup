int __cdecl _callnewh(size_t Size)
{
  int (__cdecl *v1)(size_t); // eax

  v1 = (int (__cdecl *)(size_t))DecodePointer(dword_4D726C);
  return v1 && v1(Size);
}
