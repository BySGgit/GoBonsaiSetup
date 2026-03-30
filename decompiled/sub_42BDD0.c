int __stdcall sub_42BDD0(int a1, _DWORD *a2)
{
  _DWORD *v2; // eax
  int v3; // ecx
  _DWORD *v4; // edi
  void *v5; // esi
  _BYTE *v6; // esi
  unsigned int v7; // eax
  int v8; // ebp
  int v9; // esi
  int v10; // ecx
  int v11; // edx
  _DWORD *v12; // eax
  unsigned __int8 (__stdcall *v13)(_DWORD, int, _DWORD, int, bool, _DWORD); // eax
  _DWORD *v14; // eax
  _DWORD *v15; // esi
  bool v16; // cc
  char v18; // [esp+17h] [ebp-41h]
  int v19; // [esp+1Ch] [ebp-3Ch]
  int v20; // [esp+20h] [ebp-38h]
  _DWORD *v21; // [esp+24h] [ebp-34h]
  int v22; // [esp+28h] [ebp-30h]
  _DWORD *v23; // [esp+2Ch] [ebp-2Ch]
  unsigned int v24; // [esp+30h] [ebp-28h]
  int v25; // [esp+38h] [ebp-20h]
  int v26; // [esp+3Ch] [ebp-1Ch]
  int v27; // [esp+40h] [ebp-18h]
  int v28; // [esp+44h] [ebp-14h]
  int v29; // [esp+54h] [ebp-4h]

  v2 = a2;
  v3 = 0;
  v22 = 0;
  if ( (int)a2[140] <= 0 )
    return 0;
  while ( 1 )
  {
    v21 = *(_DWORD **)(v2[139] + 4 * v3);
    v20 = 0;
    if ( (int)v2[143] > 0 )
      break;
LABEL_42:
    v22 = ++v3;
    if ( v3 >= v2[140] )
      return 0;
  }
  v27 = 10;
  v28 = 24;
LABEL_4:
  v4 = *(_DWORD **)(v2[142] + 4 * v20);
  v23 = v4;
  v25 = 29;
  v26 = 28;
  if ( (dword_4D8E98 & 1) == 0 )
  {
    dword_4D8E98 |= 1u;
    v29 = 0;
    if ( !dword_4D7F04 )
    {
      v5 = operator new(0x1E80u);
      if ( v5 )
        sub_419430((int)v5);
      else
        v5 = 0;
      dword_4D7F04 = v5;
    }
    atexit(sub_4724C0);
    v29 = -1;
  }
  v6 = dword_4D7F04;
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v18 = v6[863];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v18 )
  {
    v25 = 28;
    v26 = 29;
  }
  v7 = 0;
  v24 = 0;
LABEL_18:
  v8 = *(&v25 + v7);
  v9 = 0;
  v19 = 0;
  while ( 1 )
  {
    if ( !v9 && !v21[27] )
      goto LABEL_38;
    v10 = v21[27];
    v11 = 0;
    if ( v10 <= 0 )
      goto LABEL_38;
    v12 = (_DWORD *)(v21[26] + 16);
    do
    {
      if ( v8 == *v12 )
        ++v11;
      v12 += 7;
      --v10;
    }
    while ( v10 );
    if ( !v11 )
      goto LABEL_38;
    v13 = *(unsigned __int8 (__stdcall **)(_DWORD, int, _DWORD, int, bool, _DWORD))(a1 + 4);
    if ( v13 )
    {
      if ( !v13(*a2, v22, v4[1], v8, v9 != 0, *(_DWORD *)(a1 + 8)) )
        goto LABEL_38;
    }
    v14 = operator new(0x38u);
    v15 = v14;
    if ( !v14 )
      return -2147024882;
    v14[5] = 0;
    v14[6] = 0;
    v14[7] = 0;
    v14[8] = 0;
    v14[9] = 0;
    v14[10] = 0;
    *v14 = *v4;
    v14[1] = v4[1];
    v14[2] = v8;
    v14[3] = v19 != 0;
    v14[4] = v21[1];
    v14[11] = a2;
    v14[12] = v4;
    v14[13] = v21;
    sub_42C1D0(v8, (int)v14);
    if ( sub_42DBC0(a2[146] + 1, (int)(a2 + 145)) < 0 )
    {
      if ( v15[8] )
      {
        free((void *)v15[8]);
        v15[8] = 0;
      }
      v15[10] = 0;
      v15[9] = 0;
      if ( v15[5] )
      {
        free((void *)v15[5]);
        v15[5] = 0;
      }
      v15[7] = 0;
      v15[6] = 0;
      operator delete(v15);
    }
    else
    {
      *(_DWORD *)(a2[145] + 4 * a2[146]++) = v15;
    }
    v9 = v19;
    v4 = v23;
LABEL_38:
    v19 = ++v9;
    if ( v9 >= 2 )
    {
      v7 = v24 + 1;
      v24 = v7;
      if ( v7 < 4 )
        goto LABEL_18;
      v16 = ++v20 < a2[143];
      v2 = a2;
      if ( !v16 )
      {
        v3 = v22;
        goto LABEL_42;
      }
      goto LABEL_4;
    }
  }
}
