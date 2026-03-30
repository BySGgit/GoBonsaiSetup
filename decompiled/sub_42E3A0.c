int sub_42E3A0()
{
  int i; // esi
  int v1; // eax
  int result; // eax

  for ( i = 0; i < dword_4D8C8C; ++i )
  {
    v1 = *(_DWORD *)(dword_4D8C88 + 4 * i);
    if ( *(_DWORD *)(v1 + 528) )
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v1 + 528) + 64))(*(_DWORD *)(v1 + 528));
  }
  if ( dword_4D8C3C )
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D8C3C + 48))(dword_4D8C3C);
  result = dword_4D8C38;
  if ( dword_4D8C38 )
  {
    result = (*(int (__stdcall **)(int))(*(_DWORD *)dword_4D8C38 + 8))(dword_4D8C38);
    dword_4D8C38 = 0;
  }
  return result;
}
