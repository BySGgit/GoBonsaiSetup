int __stdcall sub_42B4F0(int a1, int a2)
{
  _DWORD *v2; // esi
  _DWORD *EngineInstance; // edi
  int v4; // ebp
  int (__stdcall *v6)(int, _DWORD, int *); // ecx
  int v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // ebp
  int v10; // eax
  int v11; // ebx
  int (__stdcall *v12)(int, int, int *); // eax
  int v13; // eax
  int v14; // edi
  const wchar_t *v15; // ebp
  _DWORD *v16; // edi
  int v17; // edx
  _WORD *v18; // eax
  __int16 v19; // cx
  int v20; // eax
  _WORD *v21; // ecx
  int v22; // edx
  bool v23; // zf
  int v24; // ecx
  char *v25; // eax
  int v26; // edi
  int v27; // ebx
  __int16 v28; // dx
  int v29; // [esp+Ch] [ebp-F0h]
  int i; // [esp+20h] [ebp-DCh] BYREF
  char v31; // [esp+27h] [ebp-D5h]
  int v32; // [esp+28h] [ebp-D4h]
  int v33; // [esp+2Ch] [ebp-D0h]
  wchar_t Buffer[100]; // [esp+30h] [ebp-CCh] BYREF

  v2 = dword_4D7F1C;
  sub_41F640();
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = EngineInstance[88];
  v33 = v4;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v4 )
    return -2147467259;
  *(_BYTE *)v2 = 1;
  v2[1] = a1;
  v2[2] = a2;
  sub_42C0E0((int)v2);
  v6 = *(int (__stdcall **)(int, _DWORD, int *))(*(_DWORD *)v4 + 28);
  v7 = 0;
  v32 = 0;
  i = 0;
  if ( v6(v4, 0, &i) >= 0 )
  {
    while ( 1 )
    {
      v8 = operator new(0x250u);
      v9 = v8;
      if ( !v8 )
      {
        if ( i )
          (*(void (__stdcall **)(int))(*(_DWORD *)i + 8))(i);
        return -2147024882;
      }
      v8[139] = 0;
      v8[140] = 0;
      v8[141] = 0;
      v8[142] = 0;
      v8[143] = 0;
      v8[144] = 0;
      v8[145] = 0;
      v8[146] = 0;
      v8[147] = 0;
      memset(v8, 0, 0x250u);
      *v9 = v7;
      (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)i + 32))(i, v9 + 1);
      v9[138] = i;
      v10 = sub_42BC70(v9);
      v29 = (int)v9;
      if ( v10 < 0 )
        goto LABEL_16;
      if ( sub_42B840((int)v2, v9) < 0 || (int)v9[140] <= 0 || sub_42BDD0((int)v2, v9) < 0 )
        break;
      v11 = sub_42DBC0(v2[15] + 1, (int)(v2 + 14));
      if ( v11 < 0 )
      {
        sub_42C400((int)v9);
        operator delete(v9);
        return v11;
      }
      *(_DWORD *)(v2[14] + 4 * v2[15]++) = v9;
      v7 = v32;
LABEL_17:
      ++v7;
      v12 = *(int (__stdcall **)(int, int, int *))(*(_DWORD *)v33 + 28);
      v32 = v7;
      i = 0;
      if ( v12(v33, v7, &i) < 0 )
        goto LABEL_18;
    }
    v29 = (int)v9;
LABEL_16:
    sub_42C400(v29);
    operator delete(v9);
    goto LABEL_17;
  }
LABEL_18:
  v13 = 0;
  v31 = 1;
  v32 = 0;
  if ( (int)v2[15] > 0 )
  {
    v14 = 1;
    i = 1;
    while ( v14 >= v2[15] )
    {
LABEL_25:
      ++v13;
      ++v14;
      v32 = v13;
      i = v14;
      if ( v13 >= v2[15] )
        goto LABEL_28;
    }
    v15 = (const wchar_t *)(*(_DWORD *)(v2[14] + 4 * v13) + 4);
    while ( wcsncmp(v15, (const wchar_t *)(*(_DWORD *)(v2[14] + 4 * v14) + 4), 0x80u) )
    {
      if ( ++v14 >= v2[15] )
      {
        v13 = v32;
        v14 = i;
        goto LABEL_25;
      }
    }
    v31 = 0;
  }
LABEL_28:
  for ( i = 0; i < v2[15]; ++i )
  {
    v16 = *(_DWORD **)(v2[14] + 4 * i);
    v17 = 100;
    v18 = v16 + 74;
    while ( v17 != -2147483546 )
    {
      v19 = *(v18 - 146);
      if ( !v19 )
        break;
      *v18++ = v19;
      if ( !--v17 )
      {
        --v18;
        break;
      }
    }
    *v18 = 0;
    if ( !v31 )
    {
      sub_419310(Buffer, (wchar_t *)L" (#%d)", *v16);
      v20 = 128;
      v21 = v16 + 74;
      while ( *v21 )
      {
        ++v21;
        if ( !--v20 )
          goto LABEL_48;
      }
      v22 = 128 - v20;
      v24 = v20;
      v23 = v20 == 0;
      v25 = (char *)v16 + 2 * (128 - v20) + 296;
      if ( v23 )
      {
LABEL_46:
        v25 -= 2;
      }
      else
      {
        v26 = v24 + v22 + 2147483519;
        v27 = (char *)Buffer - v25;
        while ( v26 )
        {
          v28 = *(_WORD *)&v25[v27];
          if ( !v28 )
            break;
          *(_WORD *)v25 = v28;
          v25 += 2;
          --v26;
          if ( !--v24 )
            goto LABEL_46;
        }
      }
      *(_WORD *)v25 = 0;
    }
LABEL_48:
    ;
  }
  return 0;
}
