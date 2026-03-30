void __stdcall sub_440D50(_DWORD **a1)
{
  int **v1; // eax
  int v2; // edx
  unsigned int v3; // ecx
  unsigned int v4; // esi
  unsigned int v5; // eax
  int v6; // ecx
  unsigned int *v7; // eax
  _DWORD *v8; // ecx
  unsigned int v9; // eax
  _DWORD *v10; // esi
  _DWORD *v11; // ecx
  _DWORD *v12; // ecx
  int v13; // eax
  int v14; // eax
  _DWORD *v15; // esi
  int i; // edi
  _WORD *v17; // eax
  _DWORD *v18; // ecx
  int v19; // eax
  int v20; // esi
  _DWORD *v21; // esi
  bool v22; // cf
  void **v23; // esi
  void **v24; // ecx
  unsigned __int16 *v25; // ecx
  unsigned __int16 *v26; // eax
  _DWORD *v27; // esi
  unsigned int v28; // edi
  void **v29; // edx
  void **v30; // eax
  unsigned __int16 *v31; // ecx
  unsigned __int16 *v32; // eax
  void **v33; // eax
  void **v34; // eax
  char *v35; // edx
  char *v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // edx
  _DWORD *v39; // edx
  void **v40; // eax
  char *v41; // ecx
  char *v42; // eax
  unsigned int v43; // edi
  int v44; // kr00_4
  int v45; // ecx
  int v46; // eax
  char *v47; // ecx
  char *v48; // eax
  _DWORD *v49; // edx
  _DWORD *v50; // eax
  _DWORD *v51; // edx
  int v52; // eax
  void **v53; // eax
  char *v54; // ecx
  char *v55; // eax
  _DWORD *v56; // edx
  int v57; // edi
  unsigned int v58; // ecx
  _DWORD **v59; // eax
  int v60; // eax
  _DWORD **v61; // ecx
  _DWORD *v62; // [esp-8h] [ebp-ACh]
  _DWORD *v63; // [esp-4h] [ebp-A8h]
  _DWORD *v64; // [esp+10h] [ebp-94h]
  _DWORD *j; // [esp+10h] [ebp-94h]
  void **v66; // [esp+14h] [ebp-90h]
  void **v67; // [esp+18h] [ebp-8Ch] BYREF
  void **v68; // [esp+1Ch] [ebp-88h] BYREF
  int v69[4]; // [esp+20h] [ebp-84h] BYREF
  int v70[3]; // [esp+30h] [ebp-74h] BYREF
  void *v71[4]; // [esp+3Ch] [ebp-68h] BYREF
  int v72; // [esp+4Ch] [ebp-58h]
  unsigned int v73; // [esp+50h] [ebp-54h]
  void *v74[4]; // [esp+58h] [ebp-4Ch] BYREF
  unsigned int v75; // [esp+68h] [ebp-3Ch]
  unsigned int v76; // [esp+6Ch] [ebp-38h]
  void *v77[7]; // [esp+74h] [ebp-30h] BYREF
  int v78; // [esp+A0h] [ebp-4h]

  while ( a1[7] )
  {
    v1 = (int **)sub_446A10(v70, (int *)a1 + 3);
    if ( *v1 )
      v2 = **v1;
    else
      v2 = 0;
    v3 = (unsigned int)v1[2];
    v4 = *(_DWORD *)(v2 + 8);
    v5 = v3 >> 2;
    v6 = v3 & 3;
    if ( v4 <= v5 )
      v5 -= v4;
    v7 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)(v2 + 4) + 4 * v5) + 4 * v6);
    v8 = a1[7];
    v9 = *v7;
    if ( v8 )
    {
      v10 = a1[5];
      a1[6] = (_DWORD *)((char *)a1[6] + 1);
      if ( 4 * (int)v10 <= (unsigned int)a1[6] )
        a1[6] = 0;
      v11 = (_DWORD *)((char *)v8 - 1);
      a1[7] = v11;
      if ( !v11 )
        a1[6] = 0;
    }
    if ( v9 == 192 )
    {
      *((_BYTE *)a1 + 112) = *((_BYTE *)a1 + 112) == 0;
      v12 = a1[20];
      v13 = (int)a1[19];
      if ( (_DWORD *)v13 != v12 )
      {
        v14 = sub_44C450(v12, v13, v12);
        v15 = a1[20];
        v64 = (_DWORD *)v14;
        for ( i = v14; (_DWORD *)i != v15; i += 28 )
        {
          if ( *(_DWORD *)(i + 20) >= 8u )
            operator delete(*(void **)i);
          *(_DWORD *)(i + 20) = 7;
          *(_DWORD *)(i + 16) = 0;
          *(_WORD *)i = 0;
        }
        a1[20] = v64;
      }
      a1[27] = 0;
    }
    else if ( *((_BYTE *)a1 + 112) )
    {
      switch ( v9 )
      {
        case 0xDu:
          if ( a1[16] )
          {
            if ( a1[23] == a1[24] )
              goto LABEL_27;
            v17 = a1 + 12;
            if ( (unsigned int)a1[17] >= 8 )
              v17 = *(_WORD **)v17;
            if ( sub_44BDA0(a1[23][4], (int)a1[23], (unsigned int)a1[16], v17) )
LABEL_27:
              sub_4441D0(a1 + 12, (int *)a1 + 23);
          }
          a1[27] = (_DWORD *)(((char *)a1[24] - (char *)a1[23]) / 28);
          v18 = a1[20];
          v19 = (int)a1[19];
          if ( (_DWORD *)v19 != v18 )
          {
            v20 = sub_44C450(v18, v19, v18);
            sub_446B40(v20, (int)a1[20]);
            a1[20] = (_DWORD *)v20;
          }
          v21 = a1 + 12;
          *(float *)v69 = 1.0;
          *(float *)&v69[1] = 1.0;
          *(float *)&v69[2] = 1.0;
          *(float *)&v69[3] = 1.0;
          sub_441E00(v69, (int)a1, a1 + 12);
          sub_4401A0(a1, (void **)a1 + 12);
          v22 = (unsigned int)a1[17] < 8;
          a1[16] = 0;
          if ( !v22 )
            v21 = (_DWORD *)*v21;
          *(_WORD *)v21 = 0;
          break;
        case 0x2Eu:
        case 8u:
          if ( a1[16] )
          {
            v58 = (unsigned int)a1[17];
            if ( v58 < 8 )
              v59 = a1 + 12;
            else
              v59 = (_DWORD **)a1[12];
            v60 = (int)v59 + 2 * (_DWORD)a1[16] - 2;
            if ( v58 < 8 )
              v61 = a1 + 12;
            else
              v61 = (_DWORD **)a1[12];
            if ( v60 )
              sub_403440(1u, (v60 - (int)v61) >> 1, a1 + 12);
            else
              sub_403440(1u, 0, a1 + 12);
          }
          break;
        case 9u:
          sub_4442B0((int *)a1 + 19);
          LOWORD(v74[0]) = 0;
          v76 = 7;
          v75 = 0;
          sub_4037B0(0xFFFFFFFF, (int)v74, a1 + 12, 0);
          v78 = 0;
          v23 = (void **)v74[0];
          if ( v76 >= 8 )
          {
            v24 = (void **)v74[0];
          }
          else
          {
            v23 = v74;
            v24 = v74;
          }
          v25 = (unsigned __int16 *)v24 + v75;
          v26 = (unsigned __int16 *)v74[0];
          if ( v76 < 8 )
            v26 = (unsigned __int16 *)v74;
          if ( v26 == v25 )
            v68 = v23;
          else
            sub_44C210(v26, &v68, v25, v23);
          for ( j = (_DWORD *)**a1; j != *a1; j = (_DWORD *)*j )
          {
            v27 = (_DWORD *)j[2];
            LOWORD(v71[0]) = 0;
            v73 = 7;
            v72 = 0;
            sub_4037B0(0xFFFFFFFF, (int)v71, v27, 0);
            LOBYTE(v78) = 1;
            v28 = v73;
            if ( v73 < 8 )
            {
              v66 = v71;
              v29 = (void **)v71[0];
            }
            else
            {
              v29 = (void **)v71[0];
              v66 = (void **)v71[0];
            }
            v30 = v29;
            if ( v73 < 8 )
              v30 = v71;
            v31 = (unsigned __int16 *)v30 + v72;
            v32 = (unsigned __int16 *)v29;
            if ( v73 < 8 )
              v32 = (unsigned __int16 *)v71;
            if ( v32 == v31 )
            {
              v67 = v66;
            }
            else
            {
              sub_44C210(v32, &v67, v31, v66);
              v28 = v73;
            }
            v33 = (void **)v74[0];
            if ( v76 < 8 )
              v33 = v74;
            if ( sub_444C00((char *)v71, v33, v75) != -1 )
            {
              sub_4441D0(v27, (int *)a1 + 19);
              v28 = v73;
            }
            LOBYTE(v78) = 0;
            if ( v28 >= 8 )
              operator delete(v71[0]);
          }
          a1[27] = 0;
          if ( a1[19] != a1[20] )
          {
            v34 = sub_44B1C0(v71, a1[19]);
            LOBYTE(v78) = 2;
            sub_444AE0(v34, (int)(a1 + 12));
            if ( v73 >= 8 )
              operator delete(v71[0]);
          }
          v78 = -1;
          if ( v76 >= 8 )
            operator delete(v74[0]);
          break;
        case 0x28u:
          v35 = (char *)a1[19];
          v36 = (char *)a1[20];
          if ( v35 == v36 )
          {
            v41 = (char *)a1[23];
            v42 = (char *)a1[24];
            if ( v41 != v42 )
            {
              v43 = (unsigned int)a1[27];
              v44 = v42 - v41;
              v45 = (int)(a1 + 12);
              if ( v43 < v44 / 28 - 1 )
              {
                v46 = v43 + 1;
                goto LABEL_87;
              }
              v62 = a1[23];
              a1[27] = 0;
              sub_4037B0(0xFFFFFFFF, v45, v62, 0);
            }
          }
          else
          {
            v37 = (unsigned int)a1[27];
            v38 = (int)((unsigned __int64)(2454267027LL * (v36 - v35)) >> 32) >> 4;
            if ( v37 >= v38 + (v38 >> 31) - 1 )
            {
              v63 = a1[19];
              a1[27] = 0;
              v40 = sub_44B1C0(v71, v63);
              v78 = 4;
            }
            else
            {
              v39 = a1[19];
              a1[27] = (_DWORD *)(v37 + 1);
              v40 = sub_44B1C0(v71, &v39[7 * v37 + 7]);
              v78 = 3;
            }
LABEL_72:
            sub_444AE0(v40, (int)(a1 + 12));
            v78 = -1;
            sub_403410((int)v71);
          }
          break;
        case 0x26u:
          v47 = (char *)a1[19];
          v48 = (char *)a1[20];
          if ( v47 == v48 )
          {
            v54 = (char *)a1[23];
            v55 = (char *)a1[24];
            if ( v54 != v55 )
            {
              v56 = a1[27];
              if ( v56 )
                v46 = (int)v56 - 1;
              else
                v46 = (v55 - v54) / 28 - 1;
              v45 = (int)(a1 + 12);
LABEL_87:
              a1[27] = (_DWORD *)v46;
              sub_4037B0(0xFFFFFFFF, v45, &a1[23][7 * v46], 0);
            }
          }
          else
          {
            v49 = a1[27];
            if ( v49 )
            {
              v50 = (_DWORD *)((char *)v49 - 1);
              v51 = a1[19];
              a1[27] = v50;
              v40 = sub_44B1C0(v71, &v51[7 * (_DWORD)v50]);
              v78 = 5;
              goto LABEL_72;
            }
            v52 = (v48 - v47) / 28 - 1;
            a1[27] = (_DWORD *)v52;
            v53 = sub_44B1C0(v77, &a1[19][7 * v52]);
            v78 = 6;
            sub_444AE0(v53, (int)(a1 + 12));
            v78 = -1;
            sub_403410((int)v77);
          }
          break;
        default:
          v57 = 0;
          if ( v9 >= 0x41 && v9 <= 0x5A || v9 >= 0x61 && v9 <= 0x7A || v9 >= 0x30 && v9 <= 0x39 || v9 == 32 )
            v57 = v9;
          switch ( v9 )
          {
            case 0x20u:
              v57 = 32;
              break;
            case 0xBAu:
              v57 = 59;
              break;
            case 0xBBu:
              v57 = 61;
              break;
            case 0xBCu:
              v57 = 44;
              break;
            case 0xBDu:
              v57 = 45;
              break;
            case 0xBEu:
              v57 = 46;
              break;
            case 0xBFu:
              v57 = 47;
              break;
            case 0xDBu:
              v57 = 91;
              break;
            case 0xDCu:
              v57 = 92;
              break;
            case 0xDDu:
              v57 = 93;
              break;
            case 0xDEu:
              v57 = 39;
              break;
            default:
              break;
          }
          if ( (GetKeyState(20) & 1) == 0 && (unsigned int)(v57 - 65) <= 0x19 )
            v57 += 32;
          if ( (GetKeyState(16) & 0xFFFE) != 0 )
          {
            if ( (unsigned int)(v57 - 65) <= 0x19 )
            {
              v57 += 32;
              goto LABEL_114;
            }
            if ( (unsigned int)(v57 - 97) <= 0x19 )
            {
              v57 -= 32;
              goto LABEL_114;
            }
            switch ( v57 )
            {
              case '\'':
                sub_444B50((int)(a1 + 12), 34);
                break;
              case ',':
                sub_444B50((int)(a1 + 12), 60);
                break;
              case '-':
                sub_444B50((int)(a1 + 12), 95);
                break;
              case '.':
                sub_444B50((int)(a1 + 12), 62);
                break;
              case '/':
                sub_444B50((int)(a1 + 12), 63);
                break;
              case '0':
                sub_444B50((int)(a1 + 12), 41);
                break;
              case '1':
                sub_444B50((int)(a1 + 12), 33);
                break;
              case '2':
                sub_444B50((int)(a1 + 12), 64);
                break;
              case '3':
                sub_444B50((int)(a1 + 12), 35);
                break;
              case '4':
                sub_444B50((int)(a1 + 12), 36);
                break;
              case '5':
                sub_444B50((int)(a1 + 12), 37);
                break;
              case '6':
                sub_444B50((int)(a1 + 12), 94);
                break;
              case '7':
                sub_444B50((int)(a1 + 12), 38);
                break;
              case '8':
                sub_444B50((int)(a1 + 12), 42);
                break;
              case '9':
                sub_444B50((int)(a1 + 12), 40);
                break;
              case ';':
                sub_444B50((int)(a1 + 12), 58);
                break;
              case '=':
                sub_444B50((int)(a1 + 12), 43);
                break;
              case '[':
                sub_444B50((int)(a1 + 12), 123);
                break;
              case '\\':
                sub_444B50((int)(a1 + 12), 124);
                break;
              case ']':
                sub_444B50((int)(a1 + 12), 125);
                break;
              default:
                goto LABEL_114;
            }
          }
          else
          {
LABEL_114:
            if ( v57 )
              sub_444B50((int)(a1 + 12), v57);
          }
          break;
      }
    }
  }
}
