int __cdecl _setmbcp(int CodePage)
{
  DWORD *v1; // edi
  DWORD v2; // ebx
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int v5; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  int v10; // [esp+14h] [ebp-20h]
  UINT CodePagea; // [esp+3Ch] [ebp+8h]

  v10 = -1;
  v1 = _getptd();
  __updatetmbcinfo();
  v2 = v1[26];
  CodePagea = getSystemCP(CodePage);
  if ( CodePagea == *(_DWORD *)(v2 + 4) )
    return 0;
  v3 = _malloc_crt(0x220u);
  v4 = v3;
  if ( v3 )
  {
    qmemcpy(v3, (const void *)v1[26], 0x220u);
    *v3 = 0;
    v5 = _setmbcp_nolock(CodePagea, v3);
    v10 = v5;
    if ( v5 )
    {
      if ( v5 == -1 )
      {
        if ( v4 != (_DWORD *)&unk_4C93F8 )
          free(v4);
        *_errno() = 22;
      }
    }
    else
    {
      if ( !InterlockedDecrement((volatile LONG *)v1[26]) && (_UNKNOWN *)v1[26] != &unk_4C93F8 )
        free((void *)v1[26]);
      v1[26] = (DWORD)v4;
      InterlockedIncrement(v4);
      if ( (v1[28] & 2) == 0 && (dword_4C9918 & 1) == 0 )
      {
        _lock(13);
        dword_4D72D0 = v4[1];
        dword_4D72D4 = v4[2];
        dword_4D72D8 = v4[3];
        for ( i = 0; i < 5; ++i )
          word_4D72C4[i] = *((_WORD *)v4 + i + 8);
        for ( j = 0; j < 257; ++j )
          byte_4C9618[j] = *((_BYTE *)v4 + j + 28);
        for ( k = 0; k < 256; ++k )
          byte_4C9720[k] = *((_BYTE *)v4 + k + 285);
        if ( !InterlockedDecrement(lpAddend) && lpAddend != (volatile LONG *)&unk_4C93F8 )
          free((void *)lpAddend);
        lpAddend = v4;
        InterlockedIncrement(v4);
        _unlock(13);
      }
    }
  }
  return v10;
}
