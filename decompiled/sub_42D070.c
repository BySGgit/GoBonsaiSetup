int __cdecl sub_42D070(int *a1, int *a2, _DWORD *a3, _DWORD *a4)
{
  int *v5; // ebx
  _DWORD *v6; // edx
  int v7; // eax
  _DWORD *v8; // edi
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  int v13; // eax
  int *v14; // esi
  int v15; // ebx
  int v16; // eax
  int v17; // ecx
  int v18; // edi
  unsigned int v19; // ecx
  int v20; // eax
  int v21; // eax
  unsigned int v22; // edx
  unsigned int v23; // eax
  int v24; // eax
  int v25; // ecx
  int v26; // ebx
  char *v27; // esi
  int v28; // eax
  int v29; // edx
  int v30; // eax
  unsigned int v31; // ecx
  unsigned int v32; // edx
  int v33; // ecx
  int v34; // eax
  int v35; // edx
  int v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // edx
  void *v39; // esi
  _DWORD *v40; // esi
  int v41; // esi
  void *v42; // esi
  _DWORD *v43; // esi
  unsigned int v44; // ecx
  unsigned int v45; // edx
  int v46; // edx
  int result; // eax
  int v48[7]; // [esp-20h] [ebp-A4h] BYREF
  int v49; // [esp+14h] [ebp-70h]
  unsigned int v50; // [esp+18h] [ebp-6Ch]
  int v51; // [esp+1Ch] [ebp-68h]
  unsigned int v52; // [esp+20h] [ebp-64h]
  float v53; // [esp+24h] [ebp-60h]
  char *i; // [esp+28h] [ebp-5Ch]
  int v55; // [esp+2Ch] [ebp-58h]
  float v56; // [esp+30h] [ebp-54h]
  int v57; // [esp+34h] [ebp-50h]
  unsigned int v58; // [esp+38h] [ebp-4Ch]
  unsigned int v59; // [esp+3Ch] [ebp-48h]
  unsigned int v60[7]; // [esp+40h] [ebp-44h] BYREF
  _DWORD v61[7]; // [esp+5Ch] [ebp-28h] BYREF
  int v62; // [esp+80h] [ebp-4h]
  char *v63; // [esp+88h] [ebp+4h]
  char v64; // [esp+88h] [ebp+4h]
  int v65; // [esp+90h] [ebp+Ch]

  v5 = a2;
  sub_42D830(v61, *a2, a2[4]);
  v6 = a4;
  v7 = a4[7];
  if ( v7 == 1 )
  {
    v8 = a3;
    v60[0] = a3[3];
    v60[1] = a3[4];
  }
  else
  {
    if ( v7 == 2 && a3 )
    {
      v9 = a3[4];
      v60[0] = a3[3];
      v60[1] = v9;
    }
    else if ( a2[3] )
    {
      v60[0] = 640;
      v60[1] = 480;
    }
    else
    {
      v60[0] = v61[0];
      v60[1] = v61[1];
    }
    qmemcpy(v48, v60, sizeof(v48));
    sub_42D640((int)a2, v48[0], v48[1], v48[2], v48[3], v48[4], v48[5], v48[6], v60);
    v8 = a3;
    v6 = a4;
  }
  v10 = v6[9];
  if ( v10 == 1 )
  {
    v51 = v8[13];
  }
  else if ( v10 )
  {
    v11 = v8[13];
    v51 = v11;
    if ( v11 <= 3 )
    {
      if ( !v11 )
        v51 = 1;
    }
    else
    {
      v51 = 3;
    }
  }
  else
  {
    v51 = 2;
  }
  if ( v8 && v8[16] )
    goto LABEL_31;
  v12 = v6[10];
  if ( v12 == 1 )
  {
    v49 = v8[10];
    v50 = v8[11];
    goto LABEL_32;
  }
  if ( v12 != 2 )
  {
LABEL_31:
    v49 = 1;
    v50 = 0;
  }
  else
  {
    v13 = a2[6];
    v49 = 1;
    v50 = 0;
    v63 = 0;
    v52 = v13;
    if ( v13 > 0 )
    {
      v14 = (int *)a2[8];
      v15 = v8[10];
      v16 = a2[5] - (_DWORD)v14;
      v55 = v15;
      for ( i = (char *)v16; ; v16 = (int)i )
      {
        v17 = *(int *)((char *)v14 + v16);
        v18 = *v14;
        v53 = COERCE_FLOAT(abs32(v17 - v15));
        if ( SLODWORD(v53) < (int)abs32(v49 - v15) )
        {
          v49 = v17;
          v19 = a3[11];
          v50 = v18 - 1;
          if ( v18 - 1 >= v19 )
            v50 = v19;
        }
        ++v14;
        if ( (int)++v63 >= (int)v52 )
          break;
        v15 = v55;
      }
      v5 = a2;
      v8 = a3;
      v6 = a4;
    }
  }
LABEL_32:
  v20 = v6[11];
  if ( v20 == 1 )
  {
    v52 = v8[16];
  }
  else if ( !v20 || (v52 = v8[16], v52 >= 2) )
  {
    v52 = 0;
  }
  if ( v6[12] || v6[13] )
  {
    v64 = *((_BYTE *)v8 + 84);
    v55 = v8[22];
  }
  else
  {
    v64 = 1;
    v55 = 40;
  }
  if ( v5[3] )
  {
    v60[2] = 60;
    v60[3] = 1;
  }
  else
  {
    v21 = v6[15];
    if ( v21 == 1 )
    {
      v60[2] = v8[5];
      v60[3] = v8[6];
    }
    else
    {
      if ( v21 == 2 )
      {
        v22 = v8[5];
        v23 = v8[6];
      }
      else
      {
        v22 = v61[2];
        v23 = v61[3];
      }
      v59 = v23;
      v24 = v5[13];
      v53 = 100000.0;
      v60[3] = 1;
      v25 = *(_DWORD *)(v24 + 108);
      v26 = 0;
      v58 = v22;
      v60[2] = 60;
      v57 = v25;
      if ( v25 > 0 )
      {
        v27 = *(char **)(v24 + 104);
        i = v27;
        do
        {
          qmemcpy(v61, v27, sizeof(v61));
          if ( v61[1] == v60[1] && v61[0] == v60[0] )
          {
            v56 = (double)v61[2] / (double)v61[3] - (double)v58 / (double)v59;
            v56 = fabs(v56);
            if ( v53 > (double)v56 )
            {
              v53 = v56;
              v60[2] = v61[2];
              v60[3] = v61[3];
              if ( v56 < 0.1000000014901161 )
                break;
            }
          }
          ++v26;
          v27 = i + 28;
          i += 28;
        }
        while ( v26 < v57 );
        v8 = a3;
      }
      v5 = a2;
      v6 = a4;
    }
  }
  v28 = v6[16];
  if ( v28 == 1 )
  {
    v65 = v8[19];
  }
  else if ( v28 )
  {
    v65 = v8[19];
  }
  else
  {
    v65 = v5[1] != 1;
  }
  memset(a1, 0, 0x5Cu);
  v29 = v5[4];
  v30 = v5[1];
  *a1 = *v5;
  v31 = v60[0];
  a1[2] = v29;
  v32 = v60[1];
  a1[3] = v31;
  v33 = v8[12];
  a1[1] = v30;
  v34 = v5[2];
  a1[4] = v32;
  v35 = v51;
  a1[7] = v34;
  v36 = v49;
  a1[12] = v33 | 0x20;
  v37 = v50;
  a1[13] = v35;
  v38 = v52;
  a1[10] = v36;
  a1[11] = v37;
  a1[16] = v38;
  if ( v5[3] )
  {
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      v62 = 0;
      if ( !dword_4D7F04 )
      {
        v39 = operator new(0x1E80u);
        if ( v39 )
          sub_419430((int)v39);
        else
          v39 = 0;
        dword_4D7F04 = v39;
      }
      atexit(sub_4724C0);
    }
    v40 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v41 = v40[142];
  }
  else
  {
    if ( (dword_4D8E98 & 1) == 0 )
    {
      dword_4D8E98 |= 1u;
      v62 = 1;
      if ( !dword_4D7F04 )
      {
        v42 = operator new(0x1E80u);
        if ( v42 )
          sub_419430((int)v42);
        else
          v42 = 0;
        dword_4D7F04 = v42;
      }
      atexit(sub_4724C0);
    }
    v43 = dword_4D7F04;
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v41 = v43[141];
  }
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v44 = v60[2];
  v45 = v60[3];
  a1[14] = v41;
  a1[15] = v5[3];
  a1[5] = v44;
  a1[6] = v45;
  v46 = v55;
  a1[19] = v65;
  result = v8[18];
  a1[17] = 0;
  *((_BYTE *)a1 + 84) = v64;
  a1[22] = v46;
  a1[18] = result;
  return result;
}
