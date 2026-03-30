int __stdcall sub_452750(int a1)
{
  _DWORD *v1; // esi
  void *v2; // edi
  int v3; // eax

  sub_42E3A0();
  if ( dword_4D53C8 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D53C8 + 8))(dword_4D53C8);
    dword_4D53C8 = 0;
  }
  if ( dword_4D82C0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D82C0 + 64))(dword_4D82C0);
  if ( dword_4D82C8 )
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D82C8 + 276))(dword_4D82C8);
  if ( dword_4D82C4 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D82C4 + 8))(dword_4D82C4);
    dword_4D82C4 = 0;
  }
  if ( dword_4D82BC )
  {
    v1 = (char *)dword_4D82BC + 44;
    v2 = dword_4D82BC;
    v3 = *((_DWORD *)dword_4D82BC + 11);
    if ( v3 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
      *v1 = 0;
    }
    operator delete(v2);
    dword_4D82BC = 0;
  }
  return sub_412660();
}
