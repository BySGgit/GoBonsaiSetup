int __thiscall sub_43B270(int *this, char a2)
{
  int *v2; // edi
  int v3; // esi
  _DWORD *v4; // eax
  int v5; // edx
  _DWORD *v6; // ebx
  int v7; // eax
  int *v8; // esi
  int v9; // ebp
  int *v10; // eax
  int v11; // ecx
  const unsigned __int16 *v12; // edi
  int v13; // eax
  int v14; // esi
  _DWORD *v15; // esi
  int v16; // esi
  int v17; // eax
  int v18; // edx
  _DWORD *v19; // ecx
  int result; // eax
  int v21; // esi
  _DWORD *v22; // eax
  int v23; // edx
  _DWORD *v24; // ebx
  int v25; // ebp
  int v26; // eax
  int *v27; // esi
  int *v28; // eax
  int v29; // ecx
  const unsigned __int16 *v30; // edi
  int v31; // eax
  int v32; // esi
  _DWORD *v33; // esi
  _DWORD *v34; // [esp+14h] [ebp-5Ch]
  _DWORD *v35; // [esp+14h] [ebp-5Ch]
  int v37; // [esp+1Ch] [ebp-54h]
  int v38; // [esp+1Ch] [ebp-54h]
  int Val[19]; // [esp+20h] [ebp-50h] BYREF

  v2 = this;
  dword_4D7DF0 = sub_43D880((int)this);
  sub_439AA0(dword_4D7DF0, (int)v2);
  if ( dword_4D7DF0 )
  {
    if ( dword_4D7DF0 == 1 )
    {
      if ( !a2 )
      {
        v3 = dword_4D7E3C;
        memset(&dword_4D7DF0, 0, 0x60u);
        dword_4D7E3C = v3;
        dword_4D7DF0 = 1;
        memset(Val, 0, 0x44u);
        Val[0] = 1;
        sub_4283D0(Val, &dword_4D7DF0, &dword_4D7DF0);
      }
      v4 = sub_42B3D0();
      v5 = v2[157];
      v6 = v4;
      v7 = 0;
      if ( v5 <= 0 )
      {
LABEL_10:
        v34 = 0;
        sub_434340(0);
      }
      else
      {
        v8 = (int *)v2[156];
        while ( *(_DWORD *)(*v8 + 44) != 3 || *(_DWORD *)(*v8 + 48) != 4 )
        {
          ++v7;
          ++v8;
          if ( v7 >= v5 )
            goto LABEL_10;
        }
        v34 = (_DWORD *)*v8;
        sub_434340(*v8);
      }
      v9 = 0;
      if ( (int)v6[15] > 0 )
      {
        do
        {
          v10 = *(int **)(v6[14] + 4 * v9);
          v37 = *v10;
          v11 = *(this + 157);
          v12 = (const unsigned __int16 *)(v10 + 74);
          v13 = 0;
          if ( v11 <= 0 )
          {
LABEL_17:
            v15 = 0;
          }
          else
          {
            v14 = *(this + 156);
            while ( *(_DWORD *)(*(_DWORD *)v14 + 44) != 3 || *(_DWORD *)(*(_DWORD *)v14 + 48) != 4 )
            {
              ++v13;
              v14 += 4;
              if ( v13 >= v11 )
                goto LABEL_17;
            }
            v15 = *(_DWORD **)v14;
          }
          if ( sub_434450(v15, v12) == -1 )
            sub_434240((int)v12, v15, v37);
          ++v9;
        }
        while ( v9 < v6[15] );
        v2 = this;
      }
      sub_4344D0(v34, dword_4D7DF4);
      v16 = v2[157];
      v17 = 0;
      if ( v16 <= 0 )
      {
LABEL_27:
        v19 = 0;
      }
      else
      {
        v18 = v2[156];
        while ( 1 )
        {
          v19 = *(_DWORD **)v18;
          if ( *(_DWORD *)(*(_DWORD *)v18 + 44) == 42 && v19[12] == 2 )
            break;
          ++v17;
          v18 += 4;
          if ( v17 >= v16 )
            goto LABEL_27;
        }
      }
      (*(void (__thiscall **)(_DWORD *, bool, _DWORD))(*v19 + 80))(v19, (dword_4D7E3C & 2) != 0, 0);
      result = sub_43B5A0(v2);
      if ( result < 0 )
        return result;
    }
    return 0;
  }
  if ( !a2 )
  {
    v21 = dword_4D7E3C;
    memset(&dword_4D7DF0, 0, 0x60u);
    dword_4D7E3C = v21;
    dword_4D7DF0 = 0;
    memset(Val, 0, 0x44u);
    Val[0] = 1;
    sub_4283D0(Val, &dword_4D7DF0, &dword_4D7DF0);
  }
  v22 = sub_428650();
  v23 = v2[157];
  v24 = v22;
  v25 = 0;
  v26 = 0;
  if ( v23 <= 0 )
  {
LABEL_39:
    v35 = 0;
    sub_434340(0);
  }
  else
  {
    v27 = (int *)v2[156];
    while ( *(_DWORD *)(*v27 + 44) != 3 || *(_DWORD *)(*v27 + 48) != 4 )
    {
      ++v26;
      ++v27;
      if ( v26 >= v23 )
        goto LABEL_39;
    }
    v35 = (_DWORD *)*v27;
    sub_434340(*v27);
  }
  if ( (int)v24[23] > 0 )
  {
    do
    {
      v28 = *(int **)(v24[22] + 4 * v25);
      v38 = *v28;
      v29 = *(this + 157);
      v30 = (const unsigned __int16 *)(v28 + 276);
      v31 = 0;
      if ( v29 <= 0 )
      {
LABEL_46:
        v33 = 0;
      }
      else
      {
        v32 = *(this + 156);
        while ( *(_DWORD *)(*(_DWORD *)v32 + 44) != 3 || *(_DWORD *)(*(_DWORD *)v32 + 48) != 4 )
        {
          ++v31;
          v32 += 4;
          if ( v31 >= v29 )
            goto LABEL_46;
        }
        v33 = *(_DWORD **)v32;
      }
      if ( sub_434450(v33, v30) == -1 )
        sub_434240((int)v30, v33, v38);
      ++v25;
    }
    while ( v25 < v24[23] );
    v2 = this;
  }
  sub_4344D0(v35, dword_4D7DF4);
  result = sub_43B5A0(v2);
  if ( result >= 0 )
    return 0;
  return result;
}
