_BYTE *__cdecl sub_44AB70(_BYTE *a1, const unsigned __int16 *a2)
{
  int v2; // edx
  unsigned int v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // ebx
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  _DWORD *v12; // ecx
  int v13; // edx
  int *v14; // eax
  _WORD **v15; // ecx
  _WORD *v16; // eax
  __int16 v17; // ax
  int v18; // ecx
  int v19; // eax
  int v20; // edx
  int v21; // eax
  _DWORD *v22; // ecx
  int v23; // eax
  int v24; // eax
  bool v25; // al
  _BYTE *v26; // esi
  int v27; // ecx
  int v29; // et0
  int v30; // eax
  _DWORD *v31; // ecx
  int v32; // edx
  int *v33; // eax
  _WORD **v34; // ecx
  _WORD *v35; // eax
  __int16 v36; // ax
  int v37; // et0
  int v38; // [esp+0h] [ebp-38h] BYREF
  _BYTE *v39; // [esp+10h] [ebp-28h]
  bool v40; // [esp+14h] [ebp-24h]
  int v41; // [esp+1Ch] [ebp-1Ch]
  unsigned int v42; // [esp+20h] [ebp-18h]
  int v43; // [esp+24h] [ebp-14h]
  int *v44; // [esp+28h] [ebp-10h]
  int v45; // [esp+34h] [ebp-4h]

  v44 = &v38;
  v43 = 0;
  v42 = wcslen(a2);
  v2 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  v3 = *(_DWORD *)&a1[v2 + 36];
  v4 = *(_DWORD *)&a1[v2 + 32];
  if ( __SPAIR64__(v3, v4) <= 0 || __SPAIR64__(v3, v4) <= v42 )
  {
    v5 = 0;
    v41 = 0;
  }
  else
  {
    v41 = (__PAIR64__(v3, v4) - v42) >> 32;
    v5 = v4 - v42;
  }
  v6 = *(_DWORD *)&a1[v2 + 56];
  v39 = a1;
  if ( v6 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(v6);
  v45 = 0;
  v7 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  if ( !*(_DWORD *)&a1[v7 + 12] )
  {
    v8 = *(_DWORD *)&a1[v7 + 60];
    if ( v8 )
      sub_44DE80(v8);
  }
  v9 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  v40 = *(_DWORD *)&a1[v9 + 12] == 0;
  v45 = 1;
  if ( v40 )
  {
    LOBYTE(v45) = 2;
    if ( (*(_DWORD *)&a1[v9 + 20] & 0x1C0) == 0x40 )
      goto LABEL_23;
    while ( v41 >= 0 && (v41 > 0 || v5) )
    {
      v11 = *(_DWORD *)(*(_DWORD *)a1 + 4);
      v12 = *(_DWORD **)&a1[v11 + 56];
      v13 = *(unsigned __int16 *)&a1[v11 + 64];
      if ( *(_DWORD *)v12[9] && (v14 = (int *)v12[13], *v14 > 0) )
      {
        --*v14;
        v15 = (_WORD **)v12[9];
        v16 = (*v15)++;
        *v16 = v13;
        v17 = v13;
      }
      else
      {
        v17 = (*(int (__thiscall **)(_DWORD *, int))(*v12 + 12))(v12, v13);
      }
      if ( v17 == -1 )
      {
        v43 |= 4u;
        break;
      }
      v29 = (__PAIR64__(v41, v5--) - 1) >> 32;
      v41 = v29;
    }
    if ( !v43 )
    {
LABEL_23:
      v18 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
      v19 = (*(int (__thiscall **)(int, const unsigned __int16 *, unsigned int, _DWORD))(*(_DWORD *)v18 + 36))(
              v18,
              a2,
              v42,
              0);
      if ( v19 == v42 && !v20 )
      {
        while ( v41 >= 0 && (v41 > 0 || v5) )
        {
          v30 = *(_DWORD *)(*(_DWORD *)a1 + 4);
          v31 = *(_DWORD **)&a1[v30 + 56];
          v32 = *(unsigned __int16 *)&a1[v30 + 64];
          if ( *(_DWORD *)v31[9] && (v33 = (int *)v31[13], *v33 > 0) )
          {
            --*v33;
            v34 = (_WORD **)v31[9];
            v35 = (*v34)++;
            *v35 = v32;
            v36 = v32;
          }
          else
          {
            v36 = (*(int (__thiscall **)(_DWORD *, int))(*v31 + 12))(v31, v32);
          }
          if ( v36 == -1 )
          {
            v43 |= 4u;
            break;
          }
          v37 = (__PAIR64__(v41, v5--) - 1) >> 32;
          v41 = v37;
        }
      }
      else
      {
        v43 = 4;
      }
    }
    v21 = *(_DWORD *)(*(_DWORD *)a1 + 4);
    *(_DWORD *)&a1[v21 + 32] = 0;
    *(_DWORD *)&a1[v21 + 36] = 0;
    v45 = 1;
    v10 = v43;
  }
  else
  {
    v10 = 4;
  }
  v22 = &a1[*(_DWORD *)(*(_DWORD *)a1 + 4)];
  if ( v10 )
  {
    v23 = v10 | v22[3];
    if ( !v22[14] )
      LOBYTE(v23) = v23 | 4;
    v24 = v23 & 0x17;
    v22[3] = v24;
    if ( (v24 & v22[4]) != 0 )
      sub_44DDA0(0);
  }
  v45 = 4;
  v25 = __uncaught_exception();
  v26 = v39;
  if ( !v25 )
    sub_44DBA0(v39);
  v45 = -1;
  v27 = *(_DWORD *)&v26[*(_DWORD *)(*(_DWORD *)v26 + 4) + 56];
  if ( v27 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v27 + 8))(v27);
  return a1;
}
