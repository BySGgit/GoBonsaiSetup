int __cdecl __init_ctype(int a1)
{
  int v1; // ebx
  void *v2; // eax
  int i; // eax
  BYTE *v4; // eax
  int v5; // ecx
  int v6; // edi
  char *v7; // eax
  _BYTE *v8; // edi
  char *v9; // ecx
  bool v10; // cc
  _BYTE *v11; // edx
  BYTE *v12; // ecx
  BYTE v13; // dl
  int v14; // ecx
  char *j; // ecx
  void *v16; // eax
  UINT v18; // [esp-Ch] [ebp-64h]
  int v19[2]; // [esp+Ch] [ebp-4Ch] BYREF
  _BYTE *v20; // [esp+14h] [ebp-44h]
  char *v21; // [esp+18h] [ebp-40h]
  char *v22; // [esp+1Ch] [ebp-3Ch]
  char *v23; // [esp+20h] [ebp-38h]
  char *v24; // [esp+24h] [ebp-34h]
  int MaxCharSize_low; // [esp+28h] [ebp-30h]
  void *v26; // [esp+2Ch] [ebp-2Ch]
  void *v27; // [esp+30h] [ebp-28h]
  void *Block; // [esp+34h] [ebp-24h]
  void *v29; // [esp+38h] [ebp-20h]
  void *v30; // [esp+3Ch] [ebp-1Ch]
  struct _cpinfo CPInfo; // [esp+40h] [ebp-18h] BYREF

  v1 = 0;
  v26 = 0;
  v30 = 0;
  v29 = 0;
  v27 = 0;
  Block = 0;
  v19[0] = a1;
  v19[1] = 0;
  if ( *(_DWORD *)(a1 + 20) )
  {
    if ( !*(_DWORD *)(a1 + 4) && __getlocaleinfo((int)v19, 0, *(unsigned __int16 *)(a1 + 48), 0x1004u, a1 + 4) )
      goto $error_cleanup$28227;
    v26 = (void *)_malloc_crt(4u);
    v30 = (void *)_calloc_crt(384, 2);
    v29 = (void *)_calloc_crt(384, 1);
    v27 = (void *)_calloc_crt(384, 1);
    v2 = (void *)_calloc_crt(257, 1);
    Block = v2;
    if ( !v26 )
      goto $error_cleanup$28227;
    if ( !v30 )
      goto $error_cleanup$28227;
    if ( !v2 )
      goto $error_cleanup$28227;
    if ( !v29 )
      goto $error_cleanup$28227;
    if ( !v27 )
      goto $error_cleanup$28227;
    *(_DWORD *)v26 = 0;
    for ( i = 0; i < 256; ++i )
      *((_BYTE *)Block + i) = i;
    if ( !GetCPInfo(*(_DWORD *)(a1 + 4), &CPInfo) || CPInfo.MaxCharSize > 5 )
      goto $error_cleanup$28227;
    MaxCharSize_low = LOWORD(CPInfo.MaxCharSize);
    if ( LOWORD(CPInfo.MaxCharSize) > 1u && CPInfo.LeadByte[0] )
    {
      v4 = &CPInfo.LeadByte[1];
      do
      {
        LOBYTE(v5) = *v4;
        if ( !*v4 )
          break;
        v6 = *(v4 - 1);
        v5 = (unsigned __int8)v5;
        while ( v6 <= v5 )
        {
          *((_BYTE *)Block + v6) = 32;
          v5 = *v4;
          ++v6;
        }
        v4 += 2;
      }
      while ( *(v4 - 1) );
    }
    v18 = *(_DWORD *)(a1 + 4);
    v21 = (char *)v30 + 256;
    if ( __crtGetStringTypeA(0, 1u, (LPCCH)Block, 256, (LPWORD)v30 + 128, v18, 0, 0)
      && __crtLCMapStringA(
           0,
           *(_DWORD *)(a1 + 20),
           0x100u,
           (LPCCH)Block + 1,
           255,
           (LPWSTR)((char *)v29 + 129),
           255,
           *(_DWORD *)(a1 + 4),
           0)
      && __crtLCMapStringA(
           0,
           *(_DWORD *)(a1 + 20),
           0x200u,
           (LPCCH)Block + 1,
           255,
           (LPWSTR)((char *)v27 + 129),
           255,
           *(_DWORD *)(a1 + 4),
           0) )
    {
      v7 = (char *)v30;
      v8 = v29;
      v9 = (char *)v30 + 254;
      v10 = MaxCharSize_low <= 1;
      *((_WORD *)v30 + 127) = 0;
      v11 = v27;
      v22 = v9;
      v8[127] = 0;
      v11[127] = 0;
      v8[128] = 0;
      v20 = v8 + 128;
      v23 = v11 + 128;
      v11[128] = 0;
      if ( !v10 && CPInfo.LeadByte[0] )
      {
        v12 = &CPInfo.LeadByte[1];
        v30 = &CPInfo.LeadByte[1];
        do
        {
          v13 = *v12;
          if ( !*v12 )
            break;
          v14 = *(v12 - 1);
          v29 = (void *)v14;
          if ( v14 <= v13 )
          {
            for ( j = &v7[2 * v14 + 256]; ; j = v24 )
            {
              v29 = (char *)v29 + 1;
              *(_WORD *)j = 0x8000;
              v24 = j + 2;
              if ( (int)v29 > *(unsigned __int8 *)v30 )
                break;
            }
          }
          v12 = (BYTE *)v30 + 2;
          v30 = v12;
        }
        while ( *(v12 - 1) );
      }
      memcpy_0(v7, v7 + 512, 0xFEu);
      memcpy_0(v8, v8 + 256, 0x7Fu);
      memcpy_0(v27, (char *)v27 + 256, 0x7Fu);
      if ( *(_DWORD *)(a1 + 192) )
      {
        if ( !InterlockedDecrement(*(volatile LONG **)(a1 + 192)) )
        {
          free((void *)(*(_DWORD *)(a1 + 196) - 254));
          free((void *)(*(_DWORD *)(a1 + 204) - 128));
          free((void *)(*(_DWORD *)(a1 + 208) - 128));
          free(*(void **)(a1 + 192));
        }
      }
      v16 = v26;
      *(_DWORD *)v26 = 1;
      *(_DWORD *)(a1 + 192) = v16;
      *(_DWORD *)(a1 + 200) = v21;
      *(_DWORD *)(a1 + 196) = v22;
      *(_DWORD *)(a1 + 204) = v20;
      *(_DWORD *)(a1 + 208) = v23;
      *(_DWORD *)(a1 + 172) = MaxCharSize_low;
    }
    else
    {
$error_cleanup$28227:
      free(v26);
      free(v30);
      free(v29);
      free(v27);
      v1 = 1;
    }
    free(Block);
    return v1;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 192) )
      InterlockedDecrement(*(volatile LONG **)(a1 + 192));
    *(_DWORD *)(a1 + 192) = 0;
    *(_DWORD *)(a1 + 196) = 0;
    *(_DWORD *)(a1 + 200) = asc_473948;
    *(_DWORD *)(a1 + 204) = &unk_473DD0;
    *(_DWORD *)(a1 + 208) = &unk_473F50;
    *(_DWORD *)(a1 + 172) = 1;
    return 0;
  }
}
