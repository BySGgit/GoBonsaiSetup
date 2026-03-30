char __stdcall sub_44D8E0(int a1)
{
  int v1; // ecx
  int v2; // eax
  _DWORD *v3; // ecx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  _DWORD *v7; // edi
  struct std::locale::facet *v8; // esi
  int v9; // ecx
  unsigned __int16 **v10; // eax
  unsigned __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  _DWORD *v14; // ecx
  char v15; // al
  int v16; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp+0h] [ebp-24h] BYREF
  int v21[2]; // [esp+10h] [ebp-14h] BYREF
  int v22; // [esp+20h] [ebp-4h]

  v21[1] = (int)&v20;
  v1 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  v2 = *(_DWORD *)(v1 + a1 + 12);
  v3 = (_DWORD *)(a1 + v1);
  if ( !v2 )
  {
    v4 = v3[15];
    if ( v4 )
      sub_44DE80(v4);
    v5 = *(_DWORD *)(*(_DWORD *)a1 + 4);
    v6 = *(_DWORD *)(v5 + a1 + 20);
    if ( (v6 & 1) != 0 )
    {
      v7 = sub_44DB70(a1 + v5, v6, v21);
      v22 = 0;
      v8 = sub_44D670((int)v7);
      sub_44DB20(v21);
      v22 = 1;
      v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1 + 56);
      v10 = *(unsigned __int16 ***)(v9 + 32);
      if ( *v10 && **(int **)(v9 + 48) > 0 )
        v11 = **v10;
      else
        v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 24))(v9);
      while ( v11 != 0xFFFF )
      {
        if ( !(*(unsigned __int8 (__thiscall **)(struct std::locale::facet *, int, _DWORD))(*(_DWORD *)v8 + 8))(
                v8,
                72,
                v11) )
          goto LABEL_15;
        v11 = sub_44D820(*(int ***)(*(_DWORD *)(*(_DWORD *)a1 + 4) + a1 + 56));
      }
      v12 = *(_DWORD *)(*(_DWORD *)a1 + 4);
      v13 = *(_DWORD *)(v12 + a1 + 12);
      v14 = (_DWORD *)(a1 + v12);
      v15 = v13 | 1;
      if ( !v14[14] )
        v15 |= 4u;
      v16 = v15 & 0x17;
      v14[3] = v16;
      if ( (v16 & v14[4]) != 0 )
        sub_44DDA0(0);
LABEL_15:
      v22 = -1;
    }
    v3 = (_DWORD *)(a1 + *(_DWORD *)(*(_DWORD *)a1 + 4));
    if ( !v3[3] )
      return 1;
  }
  v18 = v3[3] | 2;
  if ( !v3[14] )
    v18 = v3[3] | 6;
  v19 = v18 & 0x17;
  v3[3] = v19;
  if ( (v19 & v3[4]) != 0 )
    sub_44DDA0(0);
  return 0;
}
