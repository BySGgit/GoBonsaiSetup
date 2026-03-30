char __stdcall sub_431620(int a1, char a2)
{
  int v2; // eax
  _DWORD *v3; // ebp
  int v4; // ecx
  int v5; // edx
  int *v6; // ecx
  int v7; // esi
  int v8; // ebx
  int v10; // ecx
  int v11; // eax
  int *v12; // ecx
  int v13; // eax
  int v14; // edi
  _DWORD *v15; // ecx
  int v16; // eax
  int v17; // esi
  _DWORD *v18; // ecx
  int v19; // eax
  _DWORD *v21; // eax
  int v22; // ecx
  int v23; // eax
  void (__thiscall *v24)(_DWORD *); // eax
  int v25; // [esp+Ch] [ebp-4h]

  v2 = dword_4D7F28;
  v3 = 0;
  if ( !dword_4D7F28 )
  {
    if ( a2 )
    {
      v4 = *(_DWORD *)(a1 + 572);
      v5 = *(_DWORD *)(v4 + 52);
      if ( v5 > 0 )
      {
        v6 = *(int **)(v4 + 48);
        while ( 1 )
        {
          v7 = *v6;
          v8 = *v6;
          if ( *v6 )
          {
            if ( *(int *)(v7 + 612) > 0 )
              break;
          }
          ++v2;
          ++v6;
          if ( v2 >= v5 )
            goto LABEL_10;
        }
        v3 = **(_DWORD ***)(v7 + 608);
        goto LABEL_10;
      }
    }
    else
    {
      v10 = *(_DWORD *)(a1 + 572);
      v11 = *(_DWORD *)(v10 + 52) - 1;
      if ( v11 >= 0 )
      {
        v12 = (int *)(*(_DWORD *)(v10 + 48) + 4 * v11);
        while ( 1 )
        {
          v7 = *v12;
          v8 = *v12;
          if ( *v12 )
          {
            if ( *(int *)(v7 + 612) > 0 )
              break;
          }
          --v12;
          if ( --v11 < 0 )
            goto LABEL_10;
        }
        v3 = *(_DWORD **)(*(_DWORD *)(v7 + 608) + 4 * *(_DWORD *)(v7 + 612) - 4);
LABEL_10:
        if ( !v7 || !v3 )
          return 1;
        goto LABEL_26;
      }
    }
    return 1;
  }
  v7 = *(_DWORD *)(dword_4D7F28 + 24);
  if ( v7 != a1 )
    return 0;
  if ( a2 )
    v13 = sub_4301D0(dword_4D7F28);
  else
    v13 = sub_430210(dword_4D7F28);
  v3 = (_DWORD *)v13;
  v8 = *(_DWORD *)(v13 + 24);
LABEL_26:
  v25 = 0;
  while ( 1 )
  {
    v14 = *(_DWORD *)(a1 + 572);
    if ( *(int *)(v14 + 52) <= 0 )
    {
LABEL_31:
      v17 = -1;
    }
    else
    {
      v15 = *(_DWORD **)(v14 + 48);
      v16 = 0;
      while ( v7 != *v15 )
      {
        ++v16;
        ++v15;
        if ( v16 >= *(_DWORD *)(v14 + 52) )
          goto LABEL_31;
      }
      v17 = v16;
    }
    if ( *(int *)(v14 + 52) <= 0 )
    {
LABEL_36:
      v19 = -1;
    }
    else
    {
      v18 = *(_DWORD **)(v14 + 48);
      v19 = 0;
      while ( v8 != *v18 )
      {
        ++v19;
        ++v18;
        if ( v19 >= *(_DWORD *)(v14 + 52) )
          goto LABEL_36;
      }
    }
    if ( a2 ? v19 < v17 : v17 < v19 )
      break;
    if ( v3 == (_DWORD *)dword_4D7F28 )
      return 1;
    if ( *(_BYTE *)(v3[6] + 1) && (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v3 + 28))(v3) )
    {
      if ( dword_4D7F28 )
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_4D7F28 + 36))(dword_4D7F28);
      v24 = *(void (__thiscall **)(_DWORD *))(*v3 + 32);
      dword_4D7F28 = (int)v3;
      v24(v3);
      return 1;
    }
    v7 = v8;
    if ( a2 )
    {
      v21 = (_DWORD *)v3[6];
      v22 = v3[7] + 1;
      if ( v22 >= v21[153] )
      {
        v22 = 0;
        do
          v21 = (_DWORD *)v21[185];
        while ( (int)v21[153] <= 0 );
      }
      v23 = *(_DWORD *)(v21[152] + 4 * v22);
    }
    else
    {
      v23 = sub_430210((int)v3);
    }
    v3 = (_DWORD *)v23;
    v8 = *(_DWORD *)(v23 + 24);
    if ( ++v25 >= 0xFFFF )
      return 0;
  }
  if ( dword_4D7F28 )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_4D7F28 + 36))(dword_4D7F28);
  dword_4D7F28 = 0;
  return 1;
}
