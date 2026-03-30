int sub_42E410()
{
  int v0; // edi
  int v1; // esi
  int v2; // eax
  int i; // edi
  int v4; // esi
  int v5; // eax
  int result; // eax

  v0 = 0;
  for ( dword_4D8C74 = 0; v0 < dword_4D8C8C; ++v0 )
  {
    v1 = *(_DWORD *)(dword_4D8C88 + 4 * v0);
    v2 = *(_DWORD *)(v1 + 528);
    if ( v2 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(v1 + 528));
      *(_DWORD *)(v1 + 528) = 0;
    }
  }
  for ( i = 0; i < dword_4D8C80; ++i )
  {
    v4 = *(_DWORD *)(dword_4D8C7C + 4 * i);
    v5 = *(_DWORD *)(v4 + 540);
    if ( v5 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(*(_DWORD *)(v4 + 540));
      *(_DWORD *)(v4 + 540) = 0;
    }
  }
  result = dword_4D8C3C;
  if ( dword_4D8C3C )
  {
    result = (*(int (__stdcall **)(int))(*(_DWORD *)dword_4D8C3C + 8))(dword_4D8C3C);
    dword_4D8C3C = 0;
  }
  return result;
}
