void __usercall sub_42E570(int a1@<esi>)
{
  int v1; // ecx
  int v2; // ecx
  int v3; // edi
  int v4; // ecx
  int v5; // eax
  int *i; // edx
  int v7; // edi
  void (__thiscall *v8)(int); // eax

  if ( dword_4D7F28 )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_4D7F28 + 36))(dword_4D7F28);
  v1 = *(_DWORD *)(a1 + 16);
  if ( v1 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 44))(v1);
  v2 = 0;
  v3 = 0;
  dword_4D7F28 = 0;
  dword_4D7F2C = 0;
  *(_DWORD *)(a1 + 16) = 0;
  if ( *(int *)(a1 + 612) > 0 )
  {
    do
    {
      v4 = *(_DWORD *)(*(_DWORD *)(a1 + 608) + 4 * v3);
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4);
      ++v3;
    }
    while ( v3 < *(_DWORD *)(a1 + 612) );
    v2 = dword_4D7F28;
  }
  if ( *(_BYTE *)(a1 + 1) )
  {
    v5 = 0;
    if ( *(int *)(a1 + 612) > 0 )
    {
      for ( i = *(int **)(a1 + 608); ; ++i )
      {
        v7 = *i;
        if ( *(_BYTE *)(*i + 7) )
          break;
        if ( ++v5 >= *(_DWORD *)(a1 + 612) )
          return;
      }
      if ( v2 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 36))(v2);
        dword_4D7F28 = 0;
      }
      ReleaseCapture();
      v8 = *(void (__thiscall **)(int))(*(_DWORD *)v7 + 32);
      dword_4D7F28 = v7;
      v8(v7);
    }
  }
}
