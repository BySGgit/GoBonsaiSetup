int __stdcall sub_42BC70(_DWORD *a1)
{
  _DWORD *v1; // ebx
  D3D10_DRIVER_TYPE v2; // esi
  IDXGIAdapter *v3; // edi
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // esi
  int v8; // [esp+34h] [ebp-14h] BYREF
  ID3D10Device *v9; // [esp+38h] [ebp-10h] BYREF
  int v10; // [esp+3Ch] [ebp-Ch]
  _DWORD v11[2]; // [esp+40h] [ebp-8h]

  v11[0] = 0;
  v11[1] = 1;
  v10 = 0;
  while ( 1 )
  {
    v1 = operator new(8u);
    if ( !v1 )
      return -2147024882;
    v2 = v11[v10];
    v3 = 0;
    *v1 = *a1;
    v1[1] = v2;
    v9 = 0;
    if ( v2 == D3D10_DRIVER_TYPE_HARDWARE )
      v3 = (IDXGIAdapter *)a1[138];
    if ( sub_4380B0() && D3D10CreateDevice && D3D10CreateDevice(v3, v2, 0, 0, 0x1Du, &v9) >= 0 )
    {
      if ( v2 )
      {
        v8 = 0;
        if ( v9->lpVtbl->QueryInterface(v9, &stru_4B8D0C, (void **)&v8) < 0 )
          goto LABEL_15;
        v4 = v8;
        if ( v8 )
        {
          v5 = a1[138];
          v6 = a1 + 138;
          if ( v5 )
          {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(a1[138]);
            v4 = v8;
            *v6 = 0;
          }
          (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)v4 + 28))(v4, v6);
LABEL_15:
          if ( v8 )
            (*(void (__stdcall **)(int))(*(_DWORD *)v8 + 8))(v8);
        }
      }
      if ( v9 )
      {
        v9->lpVtbl->Release(v9);
        v9 = 0;
      }
      if ( sub_42DBC0(a1[143] + 1, (int)(a1 + 142)) >= 0 )
        *(_DWORD *)(a1[142] + 4 * a1[143]++) = v1;
      goto LABEL_21;
    }
    operator delete(v1);
LABEL_21:
    if ( (unsigned int)++v10 >= 2 )
      return 0;
  }
}
