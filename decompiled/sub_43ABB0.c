int __stdcall sub_43ABB0(int a1, int a2)
{
  int v3; // esi
  int v4; // eax
  int *v5; // ecx
  int v6; // edx
  void (__stdcall *v7)(int, _DWORD, int, _DWORD); // eax

  if ( (*(_DWORD *)(a2 + 1520))-- == 1 )
  {
    v3 = *(_DWORD *)(a2 + 1380);
    v4 = 0;
    if ( v3 <= 0 )
    {
LABEL_6:
      v6 = 0;
    }
    else
    {
      v5 = *(int **)(a2 + 1376);
      while ( 1 )
      {
        v6 = *v5;
        if ( *(_DWORD *)(*v5 + 44) == 44 )
          break;
        ++v4;
        ++v5;
        if ( v4 >= v3 )
          goto LABEL_6;
      }
    }
    v7 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(a2 + 1344);
    if ( v7 && *(_BYTE *)(a2 + 768) )
      v7(257, *(_DWORD *)(v6 + 44), v6, *(_DWORD *)(a2 + 1348));
  }
  return sub_43EDC0(a2, *(_DWORD *)(a2 + 1520));
}
