int __stdcall sub_43CF10(int a1)
{
  int v1; // eax
  void *v2; // eax
  int v3; // ebx
  int v5; // esi
  int v6; // eax
  int *v7; // edx
  int v8; // ecx
  int v9; // ebx
  int v10; // esi
  int v11; // ecx
  _DWORD *v12; // eax
  int v13; // esi
  int v14; // eax
  int v15; // edx
  _DWORD *v16; // esi
  const unsigned __int16 *v17; // eax
  const wchar_t *v18; // eax
  int v19; // esi
  int v20; // eax
  int v21; // edx
  _DWORD *v22; // eax
  int v23; // eax
  int v24; // [esp+14h] [ebp-Ch]
  _DWORD *v25; // [esp+18h] [ebp-8h]
  int v26; // [esp+1Ch] [ebp-4h]

  v1 = sub_43E2E0(a1);
  v26 = v1;
  if ( dword_4D7E28 )
    dword_4D7E2C = v1;
  v2 = sub_428650();
  v3 = sub_429610(dword_4D7DF8, (int)v2, dword_4D7DF4, dword_4D7DFC, dword_4D7E0C, dword_4D7E24 == 1);
  v25 = (_DWORD *)v3;
  if ( !v3 )
    return -2147467259;
  v5 = *(_DWORD *)(a1 + 628);
  v6 = 0;
  if ( v5 <= 0 )
  {
LABEL_10:
    v8 = 0;
  }
  else
  {
    v7 = *(int **)(a1 + 624);
    while ( 1 )
    {
      v8 = *v7;
      if ( *(_DWORD *)(*v7 + 44) == 17 && *(_DWORD *)(v8 + 48) == 4 )
        break;
      ++v6;
      ++v7;
      if ( v6 >= v5 )
        goto LABEL_10;
    }
  }
  sub_434340(v8);
  v24 = 0;
  if ( *(int *)(v3 + 36) > 0 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(*(_DWORD *)(v3 + 32) + 4 * v24);
      v10 = v25[18];
      v11 = 0;
      if ( v10 <= 0 )
      {
LABEL_19:
        v13 = *(_DWORD *)(a1 + 628);
        v14 = 0;
        if ( v13 <= 0 )
        {
LABEL_24:
          v16 = 0;
        }
        else
        {
          v15 = *(_DWORD *)(a1 + 624);
          while ( *(_DWORD *)(*(_DWORD *)v15 + 44) != 17 || *(_DWORD *)(*(_DWORD *)v15 + 48) != 4 )
          {
            ++v14;
            v15 += 4;
            if ( v14 >= v13 )
              goto LABEL_24;
          }
          v16 = *(_DWORD **)v15;
        }
        switch ( v9 )
        {
          case 0:
            v17 = L"D3DMULTISAMPLE_NONE";
            break;
          case 1:
            v17 = L"D3DMULTISAMPLE_NONMASKABLE";
            break;
          case 2:
            v17 = L"D3DMULTISAMPLE_2_SAMPLES";
            break;
          case 3:
            v17 = L"D3DMULTISAMPLE_3_SAMPLES";
            break;
          case 4:
            v17 = L"D3DMULTISAMPLE_4_SAMPLES";
            break;
          case 5:
            v17 = L"D3DMULTISAMPLE_5_SAMPLES";
            break;
          case 6:
            v17 = L"D3DMULTISAMPLE_6_SAMPLES";
            break;
          case 7:
            v17 = L"D3DMULTISAMPLE_7_SAMPLES";
            break;
          case 8:
            v17 = L"D3DMULTISAMPLE_8_SAMPLES";
            break;
          case 9:
            v17 = L"D3DMULTISAMPLE_9_SAMPLES";
            break;
          case 10:
            v17 = L"D3DMULTISAMPLE_10_SAMPLES";
            break;
          case 11:
            v17 = L"D3DMULTISAMPLE_11_SAMPLES";
            break;
          case 12:
            v17 = L"D3DMULTISAMPLE_12_SAMPLES";
            break;
          case 13:
            v17 = L"D3DMULTISAMPLE_13_SAMPLES";
            break;
          case 14:
            v17 = L"D3DMULTISAMPLE_14_SAMPLES";
            break;
          case 15:
            v17 = L"D3DMULTISAMPLE_15_SAMPLES";
            break;
          case 16:
            v17 = L"D3DMULTISAMPLE_16_SAMPLES";
            break;
          default:
            v17 = L"Unknown Multisample Type";
            break;
        }
        if ( sub_434450(v16, v17) == -1 )
        {
          v18 = sub_43EE70(v9);
          sub_434240((int)v18, v16, v9);
        }
      }
      else
      {
        v12 = (_DWORD *)v25[17];
        while ( *v12 != v26 || v12[1] != v9 )
        {
          ++v11;
          v12 += 2;
          if ( v11 >= v10 )
            goto LABEL_19;
        }
      }
      if ( ++v24 >= v25[9] )
        break;
      v3 = (int)v25;
    }
  }
  v19 = *(_DWORD *)(a1 + 628);
  v20 = 0;
  if ( v19 <= 0 )
  {
LABEL_53:
    v22 = 0;
  }
  else
  {
    v21 = *(_DWORD *)(a1 + 624);
    while ( *(_DWORD *)(*(_DWORD *)v21 + 44) != 17 || *(_DWORD *)(*(_DWORD *)v21 + 48) != 4 )
    {
      ++v20;
      v21 += 4;
      if ( v20 >= v19 )
        goto LABEL_53;
    }
    v22 = *(_DWORD **)v21;
  }
  sub_4344D0(v22, dword_4D7E14);
  v23 = sub_43D1B0(a1);
  return v23 >= 0 ? 0 : v23;
}
