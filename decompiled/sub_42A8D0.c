void __cdecl sub_42A8D0(void *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // ecx
  _DWORD *v4; // edi
  int *EngineInstance; // esi
  int v6; // esi
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  int *v16; // esi
  int v17; // ebp
  int v18; // eax
  int v19; // edi
  int v20; // eax
  int v21; // eax
  _DWORD *v22; // edi
  _DWORD *v23; // ecx
  int v24; // ebx
  int v25; // ebp
  int v26; // eax
  int v27; // ecx
  int v28; // esi
  int v29; // eax
  int v30; // eax
  _DWORD *v31; // ebp
  int v32; // ebx
  int j; // ecx
  int v34; // esi
  unsigned int v35; // eax
  int v36; // edx
  int v37; // edi
  int v38; // esi
  int v39; // eax
  int v40; // edx
  char v41; // dl
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // ebp
  int v47; // edi
  _DWORD *v48; // ecx
  signed int v49; // eax
  int v50; // eax
  int v51; // ebx
  _DWORD *v52; // ecx
  int v53; // eax
  _DWORD *v54; // edi
  int v55; // eax
  int v56; // ecx
  void *v57; // esi
  _DWORD *v58; // esi
  int v59; // esi
  void *v60; // esi
  _DWORD *v61; // esi
  bool v62; // cc
  int v63; // eax
  int v64; // edx
  void *v65; // eax
  int v66; // [esp+18h] [ebp-78h]
  int v67; // [esp+18h] [ebp-78h]
  unsigned __int8 v68; // [esp+1Fh] [ebp-71h]
  _DWORD *v69; // [esp+24h] [ebp-6Ch]
  int v70; // [esp+28h] [ebp-68h]
  int v71; // [esp+2Ch] [ebp-64h]
  int v72; // [esp+2Ch] [ebp-64h]
  int v73; // [esp+30h] [ebp-60h]
  int v74; // [esp+34h] [ebp-5Ch]
  int v75; // [esp+38h] [ebp-58h]
  void *Block; // [esp+3Ch] [ebp-54h] BYREF
  int v77; // [esp+40h] [ebp-50h]
  int v78; // [esp+44h] [ebp-4Ch]
  int v79; // [esp+48h] [ebp-48h]
  int i; // [esp+4Ch] [ebp-44h]
  int v81; // [esp+50h] [ebp-40h] BYREF
  int v82; // [esp+54h] [ebp-3Ch]
  int v83; // [esp+58h] [ebp-38h]
  int v84; // [esp+60h] [ebp-30h]
  void *v85; // [esp+64h] [ebp-2Ch]
  int v86; // [esp+68h] [ebp-28h]
  _DWORD v87[2]; // [esp+6Ch] [ebp-24h] BYREF
  int v88; // [esp+74h] [ebp-1Ch]
  int v89; // [esp+78h] [ebp-18h]
  int v90; // [esp+8Ch] [ebp-4h]

  v4 = v3;
  v85 = a1;
  v69 = v3;
  sub_41F750();
  EngineInstance = (int *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = *EngineInstance;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  (*(void (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)v6 + 32))(v6, *a2, v87);
  v7 = a3[6];
  if ( v7 == 1 )
  {
    v70 = v4[3];
  }
  else if ( v7 )
  {
    v8 = v4[3];
    v70 = v8;
    if ( (*(_DWORD *)(a2[21] + 36) & 0x10000) == 0 && (v8 & 0xC0) != 0 )
    {
      v8 = v8 & 0xFFFFFF1F | 0x20;
      v70 = v8;
    }
    if ( (v8 & 0xE0) == 0 )
    {
      if ( (*(_DWORD *)(a2[21] + 36) & 0x10000) != 0 )
        v70 |= 0x40u;
      else
        v70 |= 0x20u;
    }
  }
  else
  {
    v70 = (*(_DWORD *)(a2[21] + 36) & 0x10000) != 0 ? 64 : 32;
  }
  v9 = a3[7];
  if ( v9 == 1 )
  {
    v10 = v4[5];
    v81 = v4[4];
    v82 = v10;
  }
  else
  {
    if ( v9 == 2 && v4 )
    {
      v11 = v4[4];
      v12 = v4[5];
    }
    else if ( a2[4] )
    {
      v11 = 640;
      v12 = 480;
    }
    else
    {
      v11 = v87[0];
      v12 = v87[1];
    }
    sub_42B200(&v81, v11, v12, v88, v89);
  }
  v13 = a3[9];
  if ( v13 == 1 )
  {
    v75 = v4[7];
    goto LABEL_32;
  }
  if ( !v13 )
    goto LABEL_31;
  v14 = v4[7];
  v75 = v14;
  if ( v14 > 3 )
  {
    v75 = 3;
    goto LABEL_32;
  }
  if ( !v14 )
LABEL_31:
    v75 = 1;
LABEL_32:
  if ( v4 && v4[10] != 1 )
    goto LABEL_45;
  v15 = a3[10];
  if ( v15 == 1 )
  {
    v74 = v4[8];
    v73 = v4[9];
    goto LABEL_46;
  }
  if ( v15 == 2 )
  {
    v74 = 0;
    v73 = 0;
    v71 = 0;
    v79 = a2[9];
    if ( v79 > 0 )
    {
      v16 = (int *)a2[11];
      v17 = v4[8];
      v18 = a2[8] - (_DWORD)v16;
      for ( i = v18; ; v18 = i )
      {
        v19 = *v16;
        if ( (int)abs32(*(int *)((char *)v16 + v18) - v17) < (int)abs32(v74 - v17) )
        {
          v74 = *(int *)((char *)v16 + v18);
          v73 = v19 - 1;
          if ( (unsigned int)(v19 - 1) >= v69[9] )
            v73 = v69[9];
        }
        ++v16;
        if ( ++v71 >= v79 )
          break;
      }
    }
  }
  else
  {
LABEL_45:
    v74 = 0;
    v73 = 0;
  }
LABEL_46:
  v20 = a3[11];
  if ( v20 == 1 )
  {
    v72 = v69[10];
  }
  else if ( !v20 || (v21 = v69[10], v72 = v21, v21 != 1) && v21 != 2 && v21 != 3 )
  {
    v72 = 1;
  }
  Block = 0;
  v77 = 0;
  v78 = 0;
  v22 = a2;
  v90 = 0;
  sub_42D980(a2[6], (int)&Block);
  switch ( a2[3] )
  {
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x20:
      v66 = 8;
      break;
    case 0x17:
    case 0x18:
    case 0x19:
      v66 = 5;
      break;
    case 0x1A:
    case 0x1E:
      v66 = 4;
      break;
    case 0x1B:
    case 0x1D:
      v66 = 2;
      break;
    case 0x1F:
    case 0x23:
      v66 = 10;
      break;
    case 0x24:
      v66 = 16;
      break;
    default:
      v66 = 0;
      break;
  }
  v23 = v69;
  v24 = 0;
  if ( v69 )
  {
    switch ( v69[14] )
    {
      case 'F':
      case 'P':
        v24 = 16;
        break;
      case 'G':
      case 'R':
        v24 = 32;
        break;
      case 'I':
        v24 = 15;
        break;
      case 'K':
      case 'M':
      case 'O':
      case 'S':
        v24 = 24;
        break;
      default:
        v24 = 0;
        break;
    }
  }
  v25 = 0;
  if ( (int)a2[6] > 0 )
  {
    do
    {
      switch ( *(_DWORD *)(a2[5] + 4 * v25) )
      {
        case 'F':
        case 'P':
          v26 = 16;
          break;
        case 'G':
        case 'R':
          v26 = 32;
          break;
        case 'I':
          v26 = 15;
          break;
        case 'K':
        case 'M':
        case 'O':
        case 'S':
          v26 = 24;
          break;
        default:
          v26 = 0;
          break;
      }
      v27 = a3[12];
      if ( v27 == 1 )
      {
        v28 = v24 != v26 ? 0x2710 : 0;
      }
      else
      {
        if ( v27 )
          v29 = v26 - v24;
        else
          v29 = v26 - 4 * v66;
        v28 = abs32(v29);
      }
      if ( sub_42DBC0(v77 + 1, (int)&Block) >= 0 )
      {
        v30 = v77;
        *((_DWORD *)Block + v77) = v28;
        v77 = v30 + 1;
      }
      ++v25;
    }
    while ( v25 < a2[6] );
    v23 = v69;
    v22 = a2;
  }
  v31 = Block;
  v32 = 0;
  if ( v23 )
  {
    switch ( v23[14] )
    {
      case 'I':
        v32 = 1;
        break;
      case 'K':
      case 'S':
        v32 = 8;
        break;
      case 'O':
        v32 = 4;
        break;
      default:
        v32 = 0;
        break;
    }
  }
  for ( j = 0; j < v22[6]; ++j )
  {
    v34 = v31[j];
    switch ( *(_DWORD *)(v22[5] + 4 * j) )
    {
      case 'I':
        v35 = 1;
        break;
      case 'K':
      case 'S':
        v35 = 8;
        break;
      case 'O':
        v35 = 4;
        break;
      default:
        v35 = 0;
        break;
    }
    v36 = a3[13];
    if ( v36 == 1 )
    {
      if ( v35 != v32 )
        v34 += 10000;
    }
    else
    {
      if ( v36 )
        v35 = abs32(v35 - v32);
      v34 += v35;
    }
    if ( j >= 0 && j < v77 )
      v31[j] = v34;
  }
  v37 = a2[6];
  v38 = -1;
  v39 = 0;
  v40 = 100000;
  if ( v37 <= 0 )
    goto LABEL_113;
  do
  {
    if ( *((_DWORD *)Block + v39) < v40 )
    {
      v40 = *((_DWORD *)Block + v39);
      v38 = v39;
    }
    ++v39;
  }
  while ( v39 < v37 );
  if ( v38 < 0 )
  {
LABEL_113:
    v68 = 0;
    v41 = 0;
    i = 0;
  }
  else
  {
    v41 = 1;
    i = *(_DWORD *)(a2[5] + 4 * v38);
    v68 = 1;
  }
  v42 = a3[14];
  if ( v42 == 1 )
  {
    v67 = v69[15];
  }
  else if ( v42 )
  {
    v67 = v69[15];
    if ( v41 )
      v67 |= 2u;
  }
  else
  {
    v67 = 0;
    if ( v41 )
      v67 = 2;
  }
  if ( a2[4] )
  {
    v83 = 0;
  }
  else
  {
    v43 = a3[15];
    if ( v43 == 1 )
    {
      v83 = v69[16];
    }
    else
    {
      if ( v43 == 2 )
        v44 = v69[16];
      else
        v44 = v88;
      v79 = v44;
      v83 = 0;
      if ( v44 )
      {
        v45 = a2[20];
        v46 = 0;
        v47 = 100000;
        v86 = *(_DWORD *)(v45 + 1620);
        if ( v86 > 0 )
        {
          v84 = a2[2];
          v48 = *(_DWORD **)(v45 + 1616);
          do
          {
            if ( v48[3] == v84 && v48[1] == v82 && *v48 == v81 )
            {
              v49 = abs32(v48[2] - v79);
              if ( v49 < v47 )
              {
                v83 = v48[2];
                v47 = v49;
                if ( !v49 )
                  break;
              }
            }
            ++v46;
            v48 += 4;
          }
          while ( v46 < v86 );
        }
      }
    }
  }
  v50 = a3[16];
  if ( v50 == 1 )
  {
    v51 = v69[17];
  }
  else
  {
    if ( !v50 || (int)a2[15] <= 0 )
      goto LABEL_144;
    v52 = (_DWORD *)a2[14];
    v53 = 0;
    while ( v69[17] != *v52 )
    {
      ++v53;
      ++v52;
      if ( v53 >= a2[15] )
        goto LABEL_144;
    }
    if ( v53 == -1 )
LABEL_144:
      v51 = 0;
    else
      v51 = v69[17];
  }
  v54 = v85;
  memset(v85, 0, 0x48u);
  *v54 = *a2;
  v54[1] = a2[1];
  v55 = v81;
  v54[2] = a2[2];
  v56 = v82;
  v54[4] = v55;
  v54[3] = v70;
  v54[5] = v56;
  v54[6] = a2[3];
  v54[7] = v75;
  v54[8] = v74;
  v54[9] = v73;
  v54[10] = v72;
  if ( a2[4] )
  {
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      LOBYTE(v90) = 1;
      if ( !dword_4D7F04 )
      {
        v57 = operator new(0x1E80u);
        if ( v57 )
          sub_419430((int)v57);
        else
          v57 = 0;
        dword_4D7F04 = v57;
      }
      atexit(sub_4724C0);
    }
    v58 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v59 = v58[142];
  }
  else
  {
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      LOBYTE(v90) = 2;
      if ( !dword_4D7F04 )
      {
        v60 = operator new(0x1E80u);
        if ( v60 )
          sub_419430((int)v60);
        else
          v60 = 0;
        dword_4D7F04 = v60;
      }
      atexit(sub_4724C0);
    }
    v61 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v59 = v61[141];
  }
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v62 = v77 <= 0;
  v54[11] = v59;
  v63 = i;
  v54[12] = a2[4];
  v54[13] = v68;
  v64 = v83;
  v54[14] = v63;
  v65 = Block;
  v54[15] = v67;
  v54[16] = v64;
  v54[17] = v51;
  if ( v62 || v65 )
  {
    if ( v65 )
      free(v65);
  }
}
