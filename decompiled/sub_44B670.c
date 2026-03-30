int __cdecl sub_44B670(int a1, __int16 *a2)
{
  int *v2; // ecx
  unsigned int v3; // edi
  int v4; // ecx
  __int16 v5; // ax
  int v6; // ebx
  int v7; // ebp
  __int16 i; // ax
  void **v9; // eax
  void **v10; // eax
  char v11; // cl
  __int16 v12; // ax
  int v13; // ecx
  __int16 **v14; // eax
  __int16 v15; // ax
  void **v16; // eax
  int v17; // ecx
  int *v18; // eax
  __int16 **v19; // ecx
  __int16 *v20; // eax
  __int16 v21; // ax
  char v23; // [esp+17h] [ebp-41h]
  unsigned int v24; // [esp+18h] [ebp-40h]
  int v25; // [esp+1Ch] [ebp-3Ch]
  unsigned int v26; // [esp+20h] [ebp-38h]
  int *v27; // [esp+28h] [ebp-30h]
  void *v28[5]; // [esp+2Ch] [ebp-2Ch] BYREF
  unsigned int v29; // [esp+40h] [ebp-18h]
  int v30; // [esp+54h] [ebp-4h]

  v27 = v2;
  v3 = 2;
  v4 = 0;
  v26 = 2;
  if ( *a2 )
  {
    v5 = *a2;
    do
    {
      if ( v5 == *a2 )
        ++v3;
      v5 = a2[++v4];
    }
    while ( v5 );
    v26 = v3;
  }
  v29 = 15;
  v28[4] = 0;
  LOBYTE(v28[0]) = 0;
  sub_44A3B0(v3, (int)v28, 0);
  v30 = 0;
  v25 = -2;
  v24 = 1;
LABEL_8:
  v6 = 0;
  v7 = 0;
  v23 = 0;
  if ( v26 )
  {
    while ( 1 )
    {
      for ( i = a2[v7]; i; i = a2[++v7] )
      {
        if ( i == *a2 )
          break;
      }
      v9 = (void **)v28[0];
      if ( v29 < 0x10 )
        v9 = v28;
      if ( *((_BYTE *)v9 + v6) )
      {
        v10 = (void **)v28[0];
        if ( v29 < 0x10 )
          v10 = v28;
        v7 += *((char *)v10 + v6);
        goto LABEL_43;
      }
      v11 = v24;
      v7 += v24;
      v12 = a2[v7];
      if ( v12 == *a2 || !v12 )
        break;
      if ( (unsigned __int8)sub_44BB00(v27, (int *)a1) )
        goto LABEL_33;
      if ( !*(_BYTE *)(a1 + 4) )
      {
        v13 = *(_DWORD *)a1;
        if ( !*(_DWORD *)a1
          || ((v14 = *(__int16 ***)(v13 + 32), !*v14) || **(int **)(v13 + 48) <= 0
            ? (v15 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 24))(v13))
            : (v15 = **v14),
              v15 == -1) )
        {
          *(_DWORD *)a1 = 0;
        }
        else
        {
          *(_WORD *)(a1 + 6) = v15;
        }
        *(_BYTE *)(a1 + 4) = 1;
      }
      if ( a2[v7] != *(_WORD *)(a1 + 6) )
      {
LABEL_33:
        v11 = v24;
        if ( v24 >= 0x7F )
          v11 = 127;
        v16 = (void **)v28[0];
        if ( v29 < 0x10 )
          v16 = v28;
LABEL_42:
        *((_BYTE *)v16 + v6) = v11;
        goto LABEL_43;
      }
      v23 = 1;
LABEL_43:
      if ( ++v6 >= v26 )
      {
        if ( v23 && !(unsigned __int8)sub_44BB00(v27, (int *)a1) )
        {
          v17 = *(_DWORD *)a1;
          ++v24;
          if ( !*(_DWORD *)a1
            || (!**(_DWORD **)(v17 + 32) || (v18 = *(int **)(v17 + 48), *v18 <= 0)
              ? (v21 = (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 28))(v17))
              : (--*v18, v19 = *(__int16 ***)(v17 + 32), v20 = *v19, ++*v19, v21 = *v20),
                v21 == -1) )
          {
            *(_DWORD *)a1 = 0;
            *(_BYTE *)(a1 + 4) = 1;
            v25 = -1;
          }
          else
          {
            *(_BYTE *)(a1 + 4) = 0;
            v25 = -1;
          }
          goto LABEL_8;
        }
        goto LABEL_54;
      }
    }
    if ( v24 >= 0x7F )
      v11 = 127;
    v16 = (void **)v28[0];
    if ( v29 < 0x10 )
      v16 = v28;
    v25 = v6;
    goto LABEL_42;
  }
LABEL_54:
  if ( v29 >= 0x10 )
    operator delete(v28[0]);
  return v25;
}
