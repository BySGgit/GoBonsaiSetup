void __stdcall sub_438AC0(int a1)
{
  int v1; // edi
  int v2; // edx
  int v3; // eax
  int v4; // ecx
  _DWORD *v5; // esi
  int v6; // eax
  void *v7; // eax

  v1 = 0;
  v2 = *(_DWORD *)(a1 + 628);
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = *(_DWORD *)(a1 + 624);
    while ( 1 )
    {
      v5 = *(_DWORD **)v4;
      if ( *(_DWORD *)(*(_DWORD *)v4 + 44) == 32 && v5[12] == 4 )
        break;
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        goto LABEL_14;
    }
    if ( v5 )
    {
      v6 = v5[219];
      if ( v6 )
      {
        do
        {
          if ( v1 < 0 || v1 >= v6 )
            v7 = 0;
          else
            v7 = *(void **)(*(_DWORD *)(v5[218] + 4 * v1) + 512);
          operator delete(v7);
          v6 = v5[219];
          ++v1;
        }
        while ( v1 < (unsigned int)v6 );
      }
    }
  }
LABEL_14:
  sub_42DDA0(a1 + 768);
  sub_42DDA0(a1 + 16);
}
