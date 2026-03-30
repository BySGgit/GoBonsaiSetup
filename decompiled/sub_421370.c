int __cdecl sub_421370(int a1)
{
  HICON hIcon; // ecx
  int v2; // ebp
  UINT v3; // edi
  unsigned int v4; // esi
  UINT v5; // ebx
  HDC CompatibleDC; // ebp
  HDC v7; // eax
  HDC v8; // ebp
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  char *v12; // ebp
  unsigned int v13; // edi
  char *v14; // ecx
  int *v15; // eax
  int v16; // ecx
  int v17; // edx
  bool v18; // zf
  char v20; // [esp+3Fh] [ebp-9Dh]
  char *lpvBits; // [esp+40h] [ebp-9Ch]
  int v22; // [esp+44h] [ebp-98h] BYREF
  LPVOID v23; // [esp+48h] [ebp-94h]
  _DWORD *v24; // [esp+4Ch] [ebp-90h]
  HGDIOBJ h; // [esp+50h] [ebp-8Ch]
  HDC hdc; // [esp+54h] [ebp-88h]
  _DWORD *v27; // [esp+58h] [ebp-84h]
  ICONINFO piconinfo; // [esp+5Ch] [ebp-80h] BYREF
  int v29; // [esp+70h] [ebp-6Ch]
  HDC v30; // [esp+74h] [ebp-68h]
  int v31; // [esp+78h] [ebp-64h]
  HDC v32; // [esp+7Ch] [ebp-60h]
  int v33; // [esp+80h] [ebp-5Ch]
  int v34; // [esp+84h] [ebp-58h]
  char *i; // [esp+88h] [ebp-54h]
  char v36[4]; // [esp+8Ch] [ebp-50h] BYREF
  _DWORD *v37; // [esp+90h] [ebp-4Ch]
  int pv; // [esp+94h] [ebp-48h] BYREF
  unsigned int v39; // [esp+98h] [ebp-44h]
  UINT cLines; // [esp+9Ch] [ebp-40h]
  struct tagBITMAPINFO bmi; // [esp+ACh] [ebp-30h] BYREF

  v29 = a1;
  v2 = -2147467259;
  v22 = 0;
  v32 = 0;
  v30 = 0;
  hdc = 0;
  v23 = 0;
  lpvBits = 0;
  memset(&piconinfo, 0, sizeof(piconinfo));
  if ( GetIconInfo(hIcon, &piconinfo) && GetObjectW(piconinfo.hbmMask, 24, &pv) )
  {
    v3 = cLines;
    v4 = v39;
    v5 = cLines;
    if ( piconinfo.hbmColor )
    {
      v20 = 0;
    }
    else
    {
      v20 = 1;
      v3 = cLines >> 1;
    }
    v2 = (*(int (__stdcall **)(int, unsigned int, UINT, int, int, int *, _DWORD))(*(_DWORD *)v29 + 144))(
           v29,
           v39,
           v3,
           21,
           3,
           &v22,
           0);
    if ( v2 >= 0 )
    {
      lpvBits = (char *)operator new[](4 * v4 * v5);
      memset(&bmi, 0, sizeof(bmi));
      bmi.bmiHeader.biSize = 40;
      bmi.bmiHeader.biWidth = v4;
      bmi.bmiHeader.biHeight = v5;
      *(_DWORD *)&bmi.bmiHeader.biPlanes = 2097153;
      bmi.bmiHeader.biCompression = 0;
      hdc = GetDC(0);
      CompatibleDC = CreateCompatibleDC(hdc);
      v30 = CompatibleDC;
      if ( !CompatibleDC )
      {
        v2 = -2147467259;
        goto LABEL_29;
      }
      h = SelectObject(CompatibleDC, piconinfo.hbmMask);
      GetDIBits(CompatibleDC, piconinfo.hbmMask, 0, v5, lpvBits, &bmi, 0);
      SelectObject(CompatibleDC, h);
      if ( !v20 )
      {
        v23 = operator new[](4 * v4 * v3);
        v7 = CreateCompatibleDC(hdc);
        v8 = v7;
        v32 = v7;
        if ( !v7 )
        {
          v2 = -2147467259;
          goto LABEL_29;
        }
        SelectObject(v7, piconinfo.hbmColor);
        GetDIBits(v8, piconinfo.hbmColor, 0, v3, v23, &bmi, 0);
      }
      (*(void (__stdcall **)(int, char *, _DWORD, _DWORD))(*(_DWORD *)v22 + 52))(v22, v36, 0, 0);
      if ( v3 )
      {
        v27 = v37;
        v9 = v4 * (v5 - 1);
        v10 = -4 * v4;
        v11 = -v4;
        v12 = &lpvBits[v4 * (4 * v3 - 4)];
        v34 = -v4;
        v33 = -4 * v4;
        v31 = v9;
        h = (HGDIOBJ)v3;
        do
        {
          v13 = 0;
          if ( v4 )
          {
            v24 = v27;
            v14 = (char *)((_BYTE *)v23 - lpvBits);
            v15 = (int *)v12;
            for ( i = (char *)((_BYTE *)v23 - lpvBits); ; v14 = i )
            {
              if ( v20 )
              {
                v16 = *v15;
                v17 = *(_DWORD *)&lpvBits[4 * v13 + 4 * v9];
                v9 = v31;
              }
              else
              {
                v16 = *(int *)((char *)v15 + (_DWORD)v14);
                v17 = *v15;
              }
              *v24++ = v17 ? 0 : v16 | 0xFF000000;
              ++v13;
              ++v15;
              if ( v13 >= v4 )
                break;
            }
            v11 = v34;
            v10 = v33;
          }
          v27 += v4;
          v9 += v11;
          v12 += v10;
          v18 = h == (HGDIOBJ)1;
          h = (char *)h - 1;
          v31 = v9;
        }
        while ( !v18 );
      }
      (*(void (__stdcall **)(int))(*(_DWORD *)v22 + 56))(v22);
      v2 = (*(int (__stdcall **)(int, DWORD, DWORD, int))(*(_DWORD *)v29 + 40))(
             v29,
             piconinfo.xHotspot,
             piconinfo.yHotspot,
             v22);
      if ( v2 >= 0 )
        v2 = 0;
    }
  }
LABEL_29:
  if ( piconinfo.hbmMask )
    DeleteObject(piconinfo.hbmMask);
  if ( piconinfo.hbmColor )
    DeleteObject(piconinfo.hbmColor);
  if ( hdc )
    ReleaseDC(0, hdc);
  if ( v32 )
    DeleteDC(v32);
  if ( v30 )
    DeleteDC(v30);
  if ( v23 )
    operator delete[](v23);
  if ( lpvBits )
    operator delete[](lpvBits);
  if ( v22 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v22 + 8))(v22);
  return v2;
}
