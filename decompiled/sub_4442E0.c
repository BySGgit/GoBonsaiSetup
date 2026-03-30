_DWORD *__stdcall sub_4442E0(_DWORD *a1, void **Src)
{
  void *v2; // ebx
  char *v3; // eax

  v2 = Src;
  *a1 = &unk_4BBF70;
  a1[4] = &unk_4BBF78;
  a1[24] = &std::wios::`vftable';
  sub_444DD0(a1, (int)(a1 + 6));
  *(_DWORD *)((char *)a1 + *(_DWORD *)(*a1 + 4)) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  sub_446910(a1 + 6);
  a1[6] = &std::wstringbuf::`vftable';
  v3 = (char *)Src[4];
  if ( (unsigned int)Src[5] >= 8 )
    v2 = *Src;
  a1[21] = 0;
  a1[22] = 0;
  if ( v3 )
    sub_446B80((int)(a1 + 6), v2, v3);
  return a1;
}
