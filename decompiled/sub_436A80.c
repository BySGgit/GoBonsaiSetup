char __fastcall sub_436A80(int a1, int a2, int a3)
{
  int v3; // eax
  int v5; // esi
  void *v6; // edi

  v3 = *(_DWORD *)(a3 + 4);
  if ( v3 == 0xFFFF )
    return 0;
  if ( a1 != -1 && a1 >= 2 * v3 )
  {
    v5 = 2 * a1;
    goto LABEL_6;
  }
  if ( v3 )
  {
    v5 = 2 * v3;
LABEL_6:
    if ( v5 > 0xFFFF )
      v5 = 0xFFFF;
    goto LABEL_8;
  }
  v5 = 256;
LABEL_8:
  v6 = operator new[](2 * v5);
  if ( !v6 )
    return 0;
  memset(v6, 0, 2 * v5);
  if ( *(_DWORD *)a3 )
  {
    memcpy_0(v6, *(const void **)a3, 2 * *(_DWORD *)(a3 + 4));
    operator delete[](*(void **)a3);
  }
  *(_DWORD *)a3 = v6;
  *(_DWORD *)(a3 + 4) = v5;
  return 1;
}
