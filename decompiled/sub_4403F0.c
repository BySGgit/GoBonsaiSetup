_DWORD *__thiscall sub_4403F0(_DWORD **this, _DWORD *a2)
{
  void **v3; // edx
  void **v4; // eax
  unsigned __int16 *v5; // ecx
  unsigned __int16 *v6; // eax
  _DWORD *v7; // ecx
  unsigned int v9; // ecx
  void **v10; // edx
  void **v11; // edi
  void **v12; // eax
  unsigned int v13; // ebx
  void **v14; // ebp
  void **v15; // esi
  int v16; // edi
  void **v17; // eax
  unsigned int v18; // edx
  void **v19; // ecx
  int v20; // eax
  _DWORD *v21; // [esp+14h] [ebp-54h]
  _DWORD *v22; // [esp+18h] [ebp-50h] BYREF
  _DWORD *v23; // [esp+1Ch] [ebp-4Ch]
  void *v24[4]; // [esp+20h] [ebp-48h] BYREF
  unsigned int v25; // [esp+30h] [ebp-38h]
  unsigned int v26; // [esp+34h] [ebp-34h]
  void *v27[4]; // [esp+3Ch] [ebp-2Ch] BYREF
  unsigned int v28; // [esp+4Ch] [ebp-1Ch]
  unsigned int v29; // [esp+50h] [ebp-18h]
  int v30; // [esp+64h] [ebp-4h]

  LOWORD(v27[0]) = 0;
  v23 = this;
  v29 = 7;
  v28 = 0;
  sub_4037B0(0xFFFFFFFF, (int)v27, a2, 0);
  v30 = 0;
  v3 = (void **)v27[0];
  if ( v29 >= 8 )
  {
    v4 = (void **)v27[0];
  }
  else
  {
    v3 = v27;
    v4 = v27;
  }
  v5 = (unsigned __int16 *)v4 + v28;
  v6 = (unsigned __int16 *)v27[0];
  if ( v29 < 8 )
    v6 = (unsigned __int16 *)v27;
  if ( v6 != v5 )
    sub_44C210(v6, &v22, v5, v3);
  v7 = (_DWORD *)**this;
  v21 = v7;
  if ( v7 == *this )
  {
LABEL_8:
    if ( v29 >= 8 )
      operator delete(v27[0]);
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v22 = (_DWORD *)v7[2];
      LOWORD(v24[0]) = 0;
      v26 = 7;
      v25 = 0;
      sub_4037B0(0xFFFFFFFF, (int)v24, v22, 0);
      LOBYTE(v30) = 1;
      v9 = v26;
      v10 = (void **)v24[0];
      v11 = (void **)v24[0];
      if ( v26 >= 8 )
      {
        v12 = (void **)v24[0];
      }
      else
      {
        v11 = v24;
        v12 = v24;
      }
      v13 = v25;
      v14 = (void **)((char *)v12 + 2 * v25);
      v15 = (void **)v24[0];
      if ( v26 < 8 )
        v15 = v24;
      if ( v15 != v14 )
      {
        v16 = (char *)v11 - (char *)v15;
        do
        {
          *(_WORD *)((char *)v15 + v16) = tolower(*(unsigned __int16 *)v15);
          v15 = (void **)((char *)v15 + 2);
        }
        while ( v15 != v14 );
        v13 = v25;
        v10 = (void **)v24[0];
        v9 = v26;
      }
      v17 = v10;
      if ( v9 < 8 )
        v17 = v24;
      v18 = v28;
      if ( v28 >= v13 )
        v18 = v13;
      v19 = (void **)v27[0];
      if ( v29 < 8 )
        v19 = v27;
      if ( v18 )
      {
        while ( *(_WORD *)v19 == *(_WORD *)v17 )
        {
          v19 = (void **)((char *)v19 + 2);
          v17 = (void **)((char *)v17 + 2);
          if ( !--v18 )
            goto LABEL_33;
        }
        v20 = *(_WORD *)v19 < *(_WORD *)v17 ? -1 : 1;
      }
      else
      {
LABEL_33:
        v20 = v28 >= v13 ? v28 != v13 : -1;
      }
      if ( !v20 )
        break;
      LOBYTE(v30) = 0;
      if ( v26 >= 8 )
        operator delete(v24[0]);
      v21 = (_DWORD *)*v21;
      if ( v21 == (_DWORD *)*v23 )
        goto LABEL_8;
      v7 = v21;
    }
    if ( v26 >= 8 )
      operator delete(v24[0]);
    v26 = 7;
    v25 = 0;
    LOWORD(v24[0]) = 0;
    if ( v29 >= 8 )
      operator delete(v27[0]);
    return v22;
  }
}
