_BYTE *__cdecl sub_44A8C0(_BYTE *a1, _DWORD *a2)
{
  unsigned int v2; // esi
  int v3; // eax
  unsigned int v4; // edx
  _BYTE *v5; // ecx
  _BYTE *v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  _DWORD *v13; // ecx
  int v14; // edx
  int *v15; // eax
  _WORD **v16; // ecx
  _WORD *v17; // eax
  __int16 v18; // ax
  int v19; // eax
  _DWORD *v20; // ecx
  int v21; // edx
  int *v22; // eax
  _WORD **v23; // ecx
  _WORD *v24; // eax
  __int16 v25; // ax
  _DWORD *v26; // eax
  int v27; // ecx
  int v28; // eax
  int v29; // edx
  int v30; // eax
  _DWORD *v31; // ecx
  int v32; // eax
  int v33; // eax
  bool v34; // al
  _BYTE *v35; // esi
  int v36; // ecx
  int v38; // [esp+0h] [ebp-38h] BYREF
  _BYTE *v39; // [esp+10h] [ebp-28h]
  unsigned int v40; // [esp+14h] [ebp-24h]
  unsigned int v41; // [esp+1Ch] [ebp-1Ch]
  int v42; // [esp+20h] [ebp-18h]
  _BYTE *v43; // [esp+24h] [ebp-14h]
  int *v44; // [esp+28h] [ebp-10h]
  int v45; // [esp+34h] [ebp-4h]

  v44 = &v38;
  v2 = a2[4];
  v3 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  v4 = *(_DWORD *)&a1[v3 + 36];
  v5 = *(_BYTE **)&a1[v3 + 32];
  v42 = 0;
  v41 = v2;
  if ( __SPAIR64__(v4, (unsigned int)v5) <= 0 || (v39 = v5, v40 = v4, (unsigned int)v5 <= v2) )
  {
    v43 = 0;
    v6 = 0;
  }
  else
  {
    v6 = &v5[-v2];
    v40 = v4;
    v43 = &v5[-v2];
  }
  v7 = *(_DWORD *)&a1[v3 + 56];
  v39 = a1;
  if ( v7 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(v7);
  v45 = 0;
  v8 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  if ( !*(_DWORD *)&a1[v8 + 12] )
  {
    v9 = *(_DWORD *)&a1[v8 + 60];
    if ( v9 )
      sub_44DE80(v9);
  }
  v10 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  LOBYTE(v40) = *(_DWORD *)&a1[v10 + 12] == 0;
  v45 = 1;
  if ( (_BYTE)v40 )
  {
    LOBYTE(v45) = 2;
    if ( (*(_DWORD *)&a1[v10 + 20] & 0x1C0) == 0x40 )
    {
      v11 = v42;
    }
    else
    {
      while ( v6 )
      {
        v12 = *(_DWORD *)(*(_DWORD *)a1 + 4);
        v13 = *(_DWORD **)&a1[v12 + 56];
        v14 = *(unsigned __int16 *)&a1[v12 + 64];
        if ( *(_DWORD *)v13[9] && (v15 = (int *)v13[13], *v15 > 0) )
        {
          --*v15;
          v16 = (_WORD **)v13[9];
          v17 = (*v16)++;
          *v17 = v14;
          v18 = v14;
        }
        else
        {
          v18 = (*(int (__thiscall **)(_DWORD *, int))(*v13 + 12))(v13, v14);
        }
        if ( v18 == -1 )
        {
          v11 = v42 | 4;
          v42 |= 4u;
          goto LABEL_22;
        }
        v43 = --v6;
      }
      v11 = v42;
LABEL_22:
      if ( v11 )
        goto LABEL_23;
    }
    v26 = a2;
    if ( a2[5] >= 8u )
      v26 = (_DWORD *)*a2;
    v27 = *(_DWORD *)&a1[*(_DWORD *)(*(_DWORD *)a1 + 4) + 56];
    v28 = (*(int (__thiscall **)(int, _DWORD *, unsigned int, _DWORD))(*(_DWORD *)v27 + 36))(v27, v26, v41, 0);
    if ( v28 == v41 && !v29 )
    {
LABEL_23:
      while ( v43 )
      {
        v19 = *(_DWORD *)(*(_DWORD *)a1 + 4);
        v20 = *(_DWORD **)&a1[v19 + 56];
        v21 = *(unsigned __int16 *)&a1[v19 + 64];
        if ( *(_DWORD *)v20[9] && (v22 = (int *)v20[13], *v22 > 0) )
        {
          --*v22;
          v23 = (_WORD **)v20[9];
          v24 = (*v23)++;
          *v24 = v21;
          v25 = v21;
        }
        else
        {
          v25 = (*(int (__thiscall **)(_DWORD *, int))(*v20 + 12))(v20, v21);
        }
        if ( v25 == -1 )
        {
          v11 |= 4u;
          break;
        }
        --v43;
      }
    }
    else
    {
      v11 = 4;
    }
    v30 = *(_DWORD *)(*(_DWORD *)a1 + 4);
    *(_DWORD *)&a1[v30 + 32] = 0;
    *(_DWORD *)&a1[v30 + 36] = 0;
    v45 = 1;
  }
  else
  {
    v11 = 4;
  }
  v31 = &a1[*(_DWORD *)(*(_DWORD *)a1 + 4)];
  if ( v11 )
  {
    v32 = v11 | v31[3];
    if ( !v31[14] )
      LOBYTE(v32) = v32 | 4;
    v33 = v32 & 0x17;
    v31[3] = v33;
    if ( (v33 & v31[4]) != 0 )
      sub_44DDA0(0);
  }
  v45 = 4;
  v34 = __uncaught_exception();
  v35 = v39;
  if ( !v34 )
    sub_44DBA0(v39);
  v45 = -1;
  v36 = *(_DWORD *)&v35[*(_DWORD *)(*(_DWORD *)v35 + 4) + 56];
  if ( v36 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v36 + 8))(v36);
  return a1;
}
