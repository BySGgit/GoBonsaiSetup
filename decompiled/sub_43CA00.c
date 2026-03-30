int __stdcall sub_43CA00(int *a1)
{
  _DWORD *v1; // eax
  int v2; // edx
  int v3; // ecx
  _DWORD *j; // esi
  _DWORD *v5; // eax
  int result; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // ebx
  int k; // esi
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  _DWORD *v13; // edi
  void *v14; // eax
  int v15; // esi
  _BYTE *v16; // eax
  _DWORD *v17; // edi
  int v18; // ebx
  _DWORD *v19; // ebp
  int i; // esi
  _DWORD *v21; // ebp
  int v22; // esi
  int v23; // eax
  int v24; // edx
  _DWORD *v25; // esi
  int v26; // esi
  int v27; // eax
  int v28; // edx
  _DWORD *v29; // esi
  int v30; // eax
  int v31; // esi
  unsigned int v32; // esi
  int v33; // eax
  _DWORD *v34; // edi
  char v35; // [esp+14h] [ebp-14h]
  char v36; // [esp+15h] [ebp-13h]
  char v37; // [esp+16h] [ebp-12h]
  char v38; // [esp+17h] [ebp-11h]
  int v39; // [esp+18h] [ebp-10h]
  int v40; // [esp+18h] [ebp-10h]
  _DWORD *v41; // [esp+1Ch] [ebp-Ch]
  int v42; // [esp+1Ch] [ebp-Ch]
  int v43; // [esp+20h] [ebp-8h]
  int v44; // [esp+20h] [ebp-8h]
  int v45; // [esp+24h] [ebp-4h]

  if ( !dword_4D7DF0 )
  {
    dword_4D7E0C = sub_43E180((int)a1);
    v44 = dword_4D7DFC;
    v45 = dword_4D7E0C;
    v14 = sub_428650();
    v15 = sub_4295B0((int)v14, dword_4D7DF4, dword_4D7DF8);
    v40 = v15;
    if ( !v15 )
      return -2147467259;
    v16 = sub_428650();
    v35 = v16[56];
    v36 = v16[57];
    v37 = v16[58];
    v38 = v16[59];
    v42 = 0;
    if ( *(int *)(v15 + 316) <= 0 )
      return 0;
    while ( 1 )
    {
      v17 = *(_DWORD **)(*(_DWORD *)(v15 + 312) + 4 * v42);
      if ( v17[4] != (dword_4D7E24 == 1) || v17[2] != v44 || v17[3] != v45 )
        goto LABEL_85;
      v18 = (int)(a1 + 4);
      v19 = (_DWORD *)sub_4374E0((int)(a1 + 4), 15);
      sub_434340((int)v19);
      (*(void (__thiscall **)(_DWORD *, bool))(*v19 + 56))(v19, dword_4D7E28 == 1);
      if ( dword_4D7E28 )
      {
        for ( i = 0; i < v17[6]; ++i )
          sub_43E280(a1, *(_DWORD *)(v17[5] + 4 * i));
        sub_4344D0(v19, dword_4D7E2C);
      }
      else if ( sub_434450(v19, L"(not used)") == -1 )
      {
        sub_434240((int)L"(not used)", v19, 0);
      }
      result = sub_43CF10((int)a1);
      if ( result < 0 )
        return result;
      v21 = (_DWORD *)sub_4374E0(v18, 21);
      sub_434340((int)v21);
      if ( v35 )
        sub_43E680((int)a1, 32);
      if ( v36 && (*(_DWORD *)(v40 + 36) & 0x10000) != 0 )
      {
        v22 = a1[157];
        v23 = 0;
        if ( v22 <= 0 )
        {
LABEL_55:
          v25 = 0;
        }
        else
        {
          v24 = a1[156];
          while ( *(_DWORD *)(*(_DWORD *)v24 + 44) != 21 || *(_DWORD *)(*(_DWORD *)v24 + 48) != 4 )
          {
            ++v23;
            v24 += 4;
            if ( v23 >= v22 )
              goto LABEL_55;
          }
          v25 = *(_DWORD **)v24;
        }
        if ( sub_434450(v25, L"Hardware vertex processing") == -1 )
          sub_434240((int)L"Hardware vertex processing", v25, 64);
      }
      if ( v37 && (*(_DWORD *)(v40 + 36) & 0x100000) != 0 )
        sub_43E680((int)a1, 16);
      if ( v38 && (*(_DWORD *)(v40 + 36) & 0x10000) != 0 )
      {
        v26 = a1[157];
        v27 = 0;
        if ( v26 <= 0 )
        {
LABEL_68:
          v29 = 0;
        }
        else
        {
          v28 = a1[156];
          while ( *(_DWORD *)(*(_DWORD *)v28 + 44) != 21 || *(_DWORD *)(*(_DWORD *)v28 + 48) != 4 )
          {
            ++v27;
            v28 += 4;
            if ( v27 >= v26 )
              goto LABEL_68;
          }
          v29 = *(_DWORD **)v28;
        }
        if ( sub_434450(v29, L"Mixed vertex processing") == -1 )
          sub_434240((int)L"Mixed vertex processing", v29, 128);
      }
      v30 = *(_DWORD *)dword_4D7E00;
      if ( (dword_4D7E00[0] & 0x10) != 0 )
      {
        v31 = 16;
      }
      else if ( (dword_4D7E00[0] & 0x20) != 0 )
      {
        v31 = 32;
      }
      else if ( (dword_4D7E00[0] & 0x40) != 0 )
      {
        v31 = 64;
      }
      else
      {
        if ( dword_4D7E00[0] >= 0 )
          goto LABEL_82;
        v31 = 128;
      }
      sub_4344D0(v21, v31);
      v30 = *(_DWORD *)dword_4D7E00;
LABEL_82:
      v32 = v30 & 0xFFFFFF0F;
      v33 = sub_43E880((int)a1);
      if ( (v33 & 0x10) != 0 )
        v33 |= 0x40u;
      *(_DWORD *)dword_4D7E00 = v32 | v33;
      v34 = (_DWORD *)sub_4374E0(v18, 23);
      sub_434340((int)v34);
      sub_434240((int)L"On", v34, 0);
      sub_434240((int)L"Off", v34, 0x80000000);
      sub_4344D0(v34, dword_4D7E38);
      result = sub_43D710((int)a1);
      if ( result < 0 )
        return result;
LABEL_85:
      if ( ++v42 >= *(_DWORD *)(v40 + 316) )
        return 0;
      v15 = v40;
    }
  }
  if ( dword_4D7DF0 != 1 )
    return 0;
  dword_4D7E10 = sub_43E230((int)a1);
  v43 = dword_4D7E10;
  v1 = sub_42B3D0();
  v2 = v1[15];
  v3 = 0;
  if ( v2 <= 0 )
    return -2147467259;
  for ( j = (_DWORD *)v1[14]; ; ++j )
  {
    v5 = (_DWORD *)*j;
    v41 = (_DWORD *)*j;
    if ( *(_DWORD *)*j == dword_4D7DF4 )
      break;
    if ( ++v3 >= v2 )
      return -2147467259;
  }
  if ( !v5 )
    return -2147467259;
  v39 = 0;
  if ( (int)v5[146] <= 0 )
    return 0;
  while ( 1 )
  {
    v7 = *(_DWORD **)(v5[145] + 4 * v39);
    if ( v7[3] == (dword_4D7E30 == 1) && v7[2] == v43 && v7[1] == dword_4D7DF8 )
    {
      v8 = (_DWORD *)sub_4374E0((int)(a1 + 4), 36);
      sub_434340((int)v8);
      for ( k = 0; k < v7[6]; ++k )
        sub_43E4C0(a1, *(_DWORD *)(v7[5] + 4 * k));
      sub_4344D0(v8, *(int *)dword_4D7E1C);
      result = sub_43D1B0((int)a1);
      if ( result < 0 )
        return result;
      v10 = a1[157];
      v11 = 0;
      if ( v10 <= 0 )
      {
LABEL_23:
        v13 = 0;
      }
      else
      {
        v12 = a1[156];
        while ( 1 )
        {
          v13 = *(_DWORD **)v12;
          if ( *(_DWORD *)(*(_DWORD *)v12 + 44) == 40 && v13[12] == 4 )
            break;
          ++v11;
          v12 += 4;
          if ( v11 >= v10 )
            goto LABEL_23;
        }
      }
      sub_434340((int)v13);
      sub_434240((int)L"On", v13, 1);
      sub_434240((int)L"Off", v13, 0);
      sub_4344D0(v13, dword_4D7E40);
      if ( dword_4D7DF0 )
      {
        if ( dword_4D7DF0 == 1 )
          dword_4D7E40 = sub_43E920((int)a1);
      }
      else
      {
        dword_4D7E38 = sub_43E8D0((int)a1);
      }
      result = sub_43EB70(a1);
      if ( result < 0 )
        return result;
    }
    if ( ++v39 >= v41[146] )
      return 0;
    v5 = v41;
  }
}
