int sub_42E330()
{
  int i; // esi
  int v1; // eax
  int v2; // eax

  for ( i = 0; i < dword_4D8C8C; ++i )
  {
    v1 = *(_DWORD *)(dword_4D8C88 + 4 * i);
    if ( *(_DWORD *)(v1 + 528) )
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v1 + 528) + 68))(*(_DWORD *)(v1 + 528));
  }
  if ( dword_4D8C3C )
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D8C3C + 52))(dword_4D8C3C);
  v2 = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)dword_4D8C74 + 236))(dword_4D8C74, 1, &dword_4D8C38);
  return v2 >= 0 ? 0 : v2;
}
