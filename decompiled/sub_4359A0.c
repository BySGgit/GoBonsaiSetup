HGLOBAL __stdcall sub_4359A0(int a1)
{
  HGLOBAL result; // eax
  int v2; // eax
  HGLOBAL v3; // eax
  void *v4; // edi
  void *v5; // ebp
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // esi

  result = *(HGLOBAL *)(a1 + 292);
  if ( result != *(HGLOBAL *)(a1 + 300) )
  {
    result = (HGLOBAL)OpenClipboard(0);
    if ( result )
    {
      EmptyClipboard();
      v2 = lstrlenW(*(LPCWSTR *)(a1 + 80));
      v3 = GlobalAlloc(2u, 2 * v2 + 2);
      v4 = v3;
      if ( v3 )
      {
        v5 = GlobalLock(v3);
        if ( v5 )
        {
          v6 = *(_DWORD *)(a1 + 292);
          v7 = *(_DWORD *)(a1 + 300);
          v8 = v6;
          if ( v6 < v7 || (v8 = *(_DWORD *)(a1 + 300), v6 <= v7) )
            v6 = *(_DWORD *)(a1 + 300);
          v9 = v6 - v8;
          if ( v6 - v8 > 0 )
            memcpy_0(v5, (const void *)(*(_DWORD *)(a1 + 80) + 2 * v8), 2 * v9);
          *((_WORD *)v5 + v9) = 0;
          GlobalUnlock(v4);
        }
        SetClipboardData(0xDu, v4);
      }
      result = (HGLOBAL)CloseClipboard();
      if ( v4 )
        return GlobalFree(v4);
    }
  }
  return result;
}
