int __stdcall sub_43D1B0(int a1)
{
  int v1; // ebx
  void *v2; // eax
  _DWORD *v3; // eax
  int v4; // edx
  int v5; // ecx
  _DWORD *v6; // esi
  int v7; // esi
  int v8; // eax
  int v9; // edx
  _DWORD *v10; // esi
  unsigned int j; // ebx
  int v12; // edi
  int v13; // eax
  int v14; // edx
  _DWORD *v15; // edi
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  void (__stdcall *v19)(int, _DWORD, _DWORD *, _DWORD); // ecx
  int v20; // eax
  int v21; // esi
  int v22; // edx
  _DWORD *v23; // ecx
  int v24; // eax
  int v25; // esi
  int v26; // ecx
  int v27; // edx
  _DWORD *v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // edi
  void *v32; // eax
  _DWORD *v33; // eax
  int v35; // edx
  unsigned int v36; // ebp
  int v37; // ecx
  _DWORD *v38; // esi
  int v39; // esi
  int v40; // eax
  int v41; // edx
  _DWORD *v42; // esi
  unsigned int i; // ebx
  int v44; // edi
  int v45; // eax
  int v46; // edx
  _DWORD *v47; // edi
  int v48; // eax
  int v49; // ecx
  int v50; // eax
  void (__stdcall *v51)(int, _DWORD, _DWORD *, _DWORD); // ecx
  int v52; // esi
  int v53; // ecx
  int v54; // edx
  _DWORD *v55; // eax
  int v56; // ecx
  int v57; // esi
  int v58; // eax
  int v59; // edx
  _DWORD *v60; // ecx
  int v61; // eax
  unsigned int v62; // [esp+14h] [ebp-74h]
  wchar_t Buffer[54]; // [esp+18h] [ebp-70h] BYREF

  if ( !dword_4D7DF0 )
  {
    v31 = sub_43E390(a1);
    dword_4D7E14 = v31;
    v32 = sub_428650();
    v33 = (_DWORD *)sub_429610(dword_4D7DF8, (int)v32, dword_4D7DF4, dword_4D7DFC, dword_4D7E0C, dword_4D7E24 == 1);
    if ( v33 )
    {
      v35 = v33[9];
      v36 = 0;
      v37 = 0;
      if ( v35 > 0 )
      {
        v38 = (_DWORD *)v33[8];
        while ( *v38 != v31 )
        {
          ++v37;
          ++v38;
          if ( v37 >= v35 )
            goto LABEL_63;
        }
        v36 = *(_DWORD *)(v33[11] + 4 * v37);
      }
LABEL_63:
      v39 = *(_DWORD *)(a1 + 628);
      v40 = 0;
      if ( v39 <= 0 )
      {
LABEL_68:
        v42 = 0;
      }
      else
      {
        v41 = *(_DWORD *)(a1 + 624);
        while ( *(_DWORD *)(*(_DWORD *)v41 + 44) != 19 || *(_DWORD *)(*(_DWORD *)v41 + 48) != 4 )
        {
          ++v40;
          v41 += 4;
          if ( v40 >= v39 )
            goto LABEL_68;
        }
        v42 = *(_DWORD **)v41;
      }
      sub_434340((int)v42);
      for ( i = 0; i < v36; ++i )
      {
        v44 = *(_DWORD *)(a1 + 628);
        v45 = 0;
        if ( v44 <= 0 )
        {
LABEL_75:
          v47 = 0;
        }
        else
        {
          v46 = *(_DWORD *)(a1 + 624);
          while ( *(_DWORD *)(*(_DWORD *)v46 + 44) != 19 || *(_DWORD *)(*(_DWORD *)v46 + 48) != 4 )
          {
            ++v45;
            v46 += 4;
            if ( v45 >= v44 )
              goto LABEL_75;
          }
          v47 = *(_DWORD **)v46;
        }
        sub_419310(Buffer, (wchar_t *)L"%d", i);
        if ( sub_434450(v47, Buffer) == -1 )
          sub_434240((int)Buffer, v47, i);
      }
      v48 = 0;
      if ( (int)v42[219] > 0 )
      {
        v49 = v42[218];
        while ( *(_DWORD *)(*(_DWORD *)v49 + 512) != *(_DWORD *)dword_4D7E18 )
        {
          ++v48;
          v49 += 4;
          if ( v48 >= v42[219] )
            goto LABEL_89;
        }
        v42[151] = v48;
        v42[152] = v48;
        v50 = v42[6];
        v51 = *(void (__stdcall **)(int, _DWORD, _DWORD *, _DWORD))(v50 + 576);
        if ( v51 && *(_BYTE *)v50 )
          v51(513, v42[11], v42, *(_DWORD *)(v50 + 580));
      }
LABEL_89:
      if ( dword_4D7DF0 )
      {
        if ( dword_4D7DF0 == 1 )
        {
          v52 = *(_DWORD *)(a1 + 628);
          v53 = 0;
          if ( v52 <= 0 )
          {
LABEL_96:
            v55 = 0;
          }
          else
          {
            v54 = *(_DWORD *)(a1 + 624);
            while ( 1 )
            {
              v55 = *(_DWORD **)v54;
              if ( *(_DWORD *)(*(_DWORD *)v54 + 44) == 38 && v55[12] == 4 )
                break;
              ++v53;
              v54 += 4;
              if ( v53 >= v52 )
                goto LABEL_96;
            }
          }
          v56 = v55[151];
          if ( v56 >= 0 )
            *(_DWORD *)dword_4D7E20 = *(_DWORD *)(*(_DWORD *)(v55[218] + 4 * v56) + 512);
          else
            *(_DWORD *)dword_4D7E20 = 0;
        }
        return 0;
      }
      v57 = *(_DWORD *)(a1 + 628);
      v58 = 0;
      if ( v57 <= 0 )
      {
LABEL_105:
        v60 = 0;
      }
      else
      {
        v59 = *(_DWORD *)(a1 + 624);
        while ( 1 )
        {
          v60 = *(_DWORD **)v59;
          if ( *(_DWORD *)(*(_DWORD *)v59 + 44) == 19 && v60[12] == 4 )
            break;
          ++v58;
          v59 += 4;
          if ( v58 >= v57 )
            goto LABEL_105;
        }
      }
      v61 = v60[151];
      if ( v61 >= 0 )
      {
        v30 = *(_DWORD *)(*(_DWORD *)(v60[218] + 4 * v61) + 512);
        goto LABEL_109;
      }
      goto LABEL_107;
    }
    return -2147467259;
  }
  if ( dword_4D7DF0 == 1 )
  {
    v1 = sub_43E550(a1);
    *(_DWORD *)dword_4D7E1C = v1;
    v2 = sub_42B3D0();
    v3 = (_DWORD *)sub_42C300((int)v2, dword_4D7DF4, dword_4D7E10, dword_4D7E30 == 1);
    if ( v3 )
    {
      v4 = v3[6];
      v5 = 0;
      v62 = 0;
      if ( v4 > 0 )
      {
        v6 = (_DWORD *)v3[5];
        while ( *v6 != v1 )
        {
          ++v5;
          ++v6;
          if ( v5 >= v4 )
            goto LABEL_10;
        }
        v62 = *(_DWORD *)(v3[8] + 4 * v5);
      }
LABEL_10:
      v7 = *(_DWORD *)(a1 + 628);
      v8 = 0;
      if ( v7 <= 0 )
      {
LABEL_15:
        v10 = 0;
      }
      else
      {
        v9 = *(_DWORD *)(a1 + 624);
        while ( *(_DWORD *)(*(_DWORD *)v9 + 44) != 38 || *(_DWORD *)(*(_DWORD *)v9 + 48) != 4 )
        {
          ++v8;
          v9 += 4;
          if ( v8 >= v7 )
            goto LABEL_15;
        }
        v10 = *(_DWORD **)v9;
      }
      sub_434340((int)v10);
      for ( j = 0; j < v62; ++j )
      {
        v12 = *(_DWORD *)(a1 + 628);
        v13 = 0;
        if ( v12 <= 0 )
        {
LABEL_22:
          v15 = 0;
        }
        else
        {
          v14 = *(_DWORD *)(a1 + 624);
          while ( *(_DWORD *)(*(_DWORD *)v14 + 44) != 38 || *(_DWORD *)(*(_DWORD *)v14 + 48) != 4 )
          {
            ++v13;
            v14 += 4;
            if ( v13 >= v12 )
              goto LABEL_22;
          }
          v15 = *(_DWORD **)v14;
        }
        sub_419310(Buffer, (wchar_t *)L"%d", j);
        if ( sub_434450(v15, Buffer) == -1 )
          sub_434240((int)Buffer, v15, j);
      }
      v16 = 0;
      if ( (int)v10[219] > 0 )
      {
        v17 = v10[218];
        while ( *(_DWORD *)(*(_DWORD *)v17 + 512) != *(_DWORD *)dword_4D7E20 )
        {
          ++v16;
          v17 += 4;
          if ( v16 >= v10[219] )
            goto LABEL_36;
        }
        v10[151] = v16;
        v10[152] = v16;
        v18 = v10[6];
        v19 = *(void (__stdcall **)(int, _DWORD, _DWORD *, _DWORD))(v18 + 576);
        if ( v19 && *(_BYTE *)v18 )
          v19(513, v10[11], v10, *(_DWORD *)(v18 + 580));
      }
LABEL_36:
      if ( dword_4D7DF0 )
      {
        v20 = dword_4D7DF0 - 1;
        if ( dword_4D7DF0 == 1 )
        {
          v21 = *(_DWORD *)(a1 + 628);
          if ( v21 <= 0 )
          {
LABEL_43:
            v23 = 0;
          }
          else
          {
            v22 = *(_DWORD *)(a1 + 624);
            while ( 1 )
            {
              v23 = *(_DWORD **)v22;
              if ( *(_DWORD *)(*(_DWORD *)v22 + 44) == 38 && v23[12] == 4 )
                break;
              ++v20;
              v22 += 4;
              if ( v20 >= v21 )
                goto LABEL_43;
            }
          }
          v24 = v23[151];
          if ( v24 >= 0 )
            *(_DWORD *)dword_4D7E20 = *(_DWORD *)(*(_DWORD *)(v23[218] + 4 * v24) + 512);
          else
            *(_DWORD *)dword_4D7E20 = 0;
        }
        return 0;
      }
      v25 = *(_DWORD *)(a1 + 628);
      v26 = 0;
      if ( v25 <= 0 )
      {
LABEL_52:
        v28 = 0;
      }
      else
      {
        v27 = *(_DWORD *)(a1 + 624);
        while ( 1 )
        {
          v28 = *(_DWORD **)v27;
          if ( *(_DWORD *)(*(_DWORD *)v27 + 44) == 19 && v28[12] == 4 )
            break;
          ++v26;
          v27 += 4;
          if ( v26 >= v25 )
            goto LABEL_52;
        }
      }
      v29 = v28[151];
      if ( v29 >= 0 )
      {
        v30 = *(_DWORD *)(*(_DWORD *)(v28[218] + 4 * v29) + 512);
LABEL_109:
        *(_DWORD *)dword_4D7E18 = v30;
        return 0;
      }
LABEL_107:
      v30 = 0;
      goto LABEL_109;
    }
    return -2147467259;
  }
  return 0;
}
