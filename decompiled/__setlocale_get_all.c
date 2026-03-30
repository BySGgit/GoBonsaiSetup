int __usercall _setlocale_get_all@<eax>(int a1@<esi>)
{
  int result; // eax
  char *v2; // edi
  const char **v3; // eax
  const char *v4; // [esp-8h] [ebp-1Ch]
  void *Block; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  const char **v7; // [esp+Ch] [ebp-8h]
  char **v8; // [esp+10h] [ebp-4h]

  v6 = 1;
  result = _malloc_crt(0x355u);
  Block = (void *)result;
  if ( result )
  {
    v2 = (char *)(result + 4);
    *(_BYTE *)(result + 4) = 0;
    *(_DWORD *)result = 1;
    _strcats((char *)(result + 4), 0x351u, 3);
    v8 = off_473774;
    v7 = (const char **)(a1 + 88);
    do
    {
      if ( strcat_s(v2, 0x351u, ";") )
        _invoke_watson(0, 0, 0, 0, 0);
      v3 = v7;
      v4 = v7[4];
      v7 += 4;
      if ( strcmp(*v3, v4) )
        v6 = 0;
      v8 += 3;
      _strcats(v2, 0x351u, 3);
    }
    while ( (int)v8 < (int)off_4737A4 );
    if ( v6 )
    {
      free(Block);
      if ( *(_DWORD *)(a1 + 80) && !InterlockedDecrement(*(volatile LONG **)(a1 + 80)) )
        free(*(void **)(a1 + 80));
      if ( *(_DWORD *)(a1 + 84) && !InterlockedDecrement(*(volatile LONG **)(a1 + 84)) )
        free(*(void **)(a1 + 84));
      result = *(_DWORD *)(a1 + 104);
      *(_DWORD *)(a1 + 84) = 0;
      *(_DWORD *)(a1 + 76) = 0;
      *(_DWORD *)(a1 + 80) = 0;
      *(_DWORD *)(a1 + 72) = 0;
    }
    else
    {
      if ( *(_DWORD *)(a1 + 80) && !InterlockedDecrement(*(volatile LONG **)(a1 + 80)) )
        free(*(void **)(a1 + 80));
      if ( *(_DWORD *)(a1 + 84) )
      {
        if ( !InterlockedDecrement(*(volatile LONG **)(a1 + 84)) )
          free(*(void **)(a1 + 84));
      }
      *(_DWORD *)(a1 + 84) = 0;
      *(_DWORD *)(a1 + 76) = 0;
      *(_DWORD *)(a1 + 80) = Block;
      *(_DWORD *)(a1 + 72) = v2;
      return (int)v2;
    }
  }
  return result;
}
