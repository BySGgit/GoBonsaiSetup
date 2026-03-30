int __cdecl __init_monetary(int a1)
{
  int v1; // esi
  char **v2; // ebx
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  LCID v6; // esi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  int v22; // edi
  int v23; // edi
  int v24; // edi
  int v25; // edi
  int v26; // edi
  char *v27; // eax
  char v28; // cl
  char *v29; // esi
  _DWORD *v30; // ecx
  int v31[2]; // [esp+Ch] [ebp-10h] BYREF
  void *Block; // [esp+14h] [ebp-8h]
  void *v33; // [esp+18h] [ebp-4h]

  v1 = a1;
  v33 = 0;
  v31[0] = a1;
  v31[1] = 0;
  if ( *(_DWORD *)(a1 + 24) || *(_DWORD *)(a1 + 28) )
  {
    v2 = (char **)_calloc_crt(1, 80);
    if ( !v2 )
      return 1;
    v4 = _malloc_crt(4u);
    Block = v4;
    if ( !v4 )
    {
      free(v2);
      return 1;
    }
    *v4 = 0;
    if ( !*(_DWORD *)(a1 + 24) )
    {
      qmemcpy(v2, &off_4C91D8, 0x50u);
LABEL_25:
      *v2 = **(char ***)(a1 + 188);
      v1 = a1;
      v2[1] = *(char **)(*(_DWORD *)(a1 + 188) + 4);
      v2[2] = *(char **)(*(_DWORD *)(a1 + 188) + 8);
      v2[12] = *(char **)(*(_DWORD *)(a1 + 188) + 48);
      v30 = Block;
      v2[13] = *(char **)(*(_DWORD *)(a1 + 188) + 52);
      *v30 = 1;
      if ( v33 )
        *(_DWORD *)v33 = 1;
      goto LABEL_27;
    }
    v5 = _malloc_crt(4u);
    v33 = v5;
    if ( !v5 )
    {
      free(v2);
      free(Block);
      return 1;
    }
    *v5 = 0;
    v6 = *(unsigned __int16 *)(a1 + 56);
    v7 = __getlocaleinfo((struct localeinfo_struct *)v31, 1, v6, 0x15u, (void **)v2 + 3);
    v8 = __getlocaleinfo((struct localeinfo_struct *)v31, 1, v6, 0x14u, (void **)v2 + 4) | v7;
    v9 = __getlocaleinfo((struct localeinfo_struct *)v31, 1, v6, 0x16u, (void **)v2 + 5) | v8;
    v10 = __getlocaleinfo((struct localeinfo_struct *)v31, 1, v6, 0x17u, (void **)v2 + 6) | v9;
    v11 = __getlocaleinfo((struct localeinfo_struct *)v31, 1, v6, 0x18u, (void **)v2 + 7) | v10;
    v12 = __getlocaleinfo((struct localeinfo_struct *)v31, 1, v6, 0x50u, (void **)v2 + 8) | v11;
    v13 = __getlocaleinfo((struct localeinfo_struct *)v31, 1, v6, 0x51u, (void **)v2 + 9) | v12;
    v14 = __getlocaleinfo((struct localeinfo_struct *)v31, 0, v6, 0x1Au, (void **)v2 + 10) | v13;
    v15 = __getlocaleinfo((struct localeinfo_struct *)v31, 0, v6, 0x19u, (void **)((char *)v2 + 41)) | v14;
    v16 = __getlocaleinfo((struct localeinfo_struct *)v31, 0, v6, 0x54u, (void **)((char *)v2 + 42)) | v15;
    v17 = __getlocaleinfo((struct localeinfo_struct *)v31, 0, v6, 0x55u, (void **)((char *)v2 + 43)) | v16;
    v18 = __getlocaleinfo((struct localeinfo_struct *)v31, 0, v6, 0x56u, (void **)v2 + 11) | v17;
    v19 = __getlocaleinfo((struct localeinfo_struct *)v31, 0, v6, 0x57u, (void **)((char *)v2 + 45)) | v18;
    v20 = __getlocaleinfo((struct localeinfo_struct *)v31, 0, v6, 0x52u, (void **)((char *)v2 + 46)) | v19;
    v21 = __getlocaleinfo((struct localeinfo_struct *)v31, 0, v6, 0x53u, (void **)((char *)v2 + 47)) | v20;
    v22 = __getlocaleinfo((struct localeinfo_struct *)v31, 2, v6, 0x15u, (void **)v2 + 14) | v21;
    v23 = __getlocaleinfo((struct localeinfo_struct *)v31, 2, v6, 0x14u, (void **)v2 + 15) | v22;
    v24 = __getlocaleinfo((struct localeinfo_struct *)v31, 2, v6, 0x16u, (void **)v2 + 16) | v23;
    v25 = __getlocaleinfo((struct localeinfo_struct *)v31, 2, v6, 0x17u, (void **)v2 + 17) | v24;
    v26 = __getlocaleinfo((struct localeinfo_struct *)v31, 2, v6, 0x50u, (void **)v2 + 18) | v25;
    if ( v26 | __getlocaleinfo((struct localeinfo_struct *)v31, 2, v6, 0x51u, (void **)v2 + 19) )
    {
      __free_lconv_mon((int)v2);
      free(v2);
      free(Block);
      free(v33);
      return 1;
    }
    v27 = v2[7];
    while ( 1 )
    {
      if ( !*v27 )
        goto LABEL_25;
      v28 = *v27;
      if ( *v27 >= 48 && v28 <= 57 )
        break;
      if ( v28 == 59 )
      {
        v29 = v27;
        do
        {
          *v29 = v29[1];
          ++v29;
        }
        while ( *v29 );
      }
      else
      {
LABEL_17:
        ++v27;
      }
    }
    *v27 = v28 - 48;
    goto LABEL_17;
  }
  v33 = 0;
  Block = 0;
  v2 = &off_4C91D8;
LABEL_27:
  if ( *(_DWORD *)(v1 + 184) )
    InterlockedDecrement(*(volatile LONG **)(v1 + 184));
  if ( *(_DWORD *)(v1 + 176) )
  {
    if ( !InterlockedDecrement(*(volatile LONG **)(v1 + 176)) )
    {
      free(*(void **)(v1 + 188));
      free(*(void **)(v1 + 176));
    }
  }
  *(_DWORD *)(v1 + 184) = v33;
  *(_DWORD *)(v1 + 176) = Block;
  *(_DWORD *)(v1 + 188) = v2;
  return 0;
}
