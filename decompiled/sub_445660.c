_DWORD *__thiscall sub_445660(void *this, _DWORD *a2, int a3, _DWORD *a4, __int64 *a5, __int16 a6, double a7)
{
  int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // esi
  int v10; // ecx
  unsigned int v11; // esi
  int v12; // edx
  double v13; // st6
  double v14; // st5
  double v15; // st4
  double v16; // st5
  double v17; // rt0
  double v18; // rt1
  double v19; // st4
  double v20; // st7
  double v21; // st5
  double v22; // rtt
  bool v23; // cf
  double v24; // rt0
  double v25; // st5
  double v26; // st6
  double v27; // st5
  double v28; // st7
  char *v29; // eax
  int v30; // edx
  char v31; // cl
  size_t v32; // eax
  char v34; // [esp+3Fh] [ebp-91h]
  size_t v35; // [esp+40h] [ebp-90h]
  int v36; // [esp+44h] [ebp-8Ch]
  char Format; // [esp+50h] [ebp-80h] BYREF
  char v39; // [esp+51h] [ebp-7Fh] BYREF
  char v40; // [esp+52h] [ebp-7Eh] BYREF
  char Buffer[116]; // [esp+58h] [ebp-78h] BYREF

  v7 = *((_DWORD *)a5 + 7);
  v8 = 0;
  if ( a5[3] > 0 || (*((_DWORD *)a5 + 5) & 0x2000) != 0 )
  {
    v9 = *((_DWORD *)a5 + 6);
  }
  else
  {
    v9 = 6;
    v7 = 0;
  }
  if ( v7 < 0 || v7 <= 0 && v9 <= 0x24 )
    v36 = v9;
  else
    v36 = 36;
  v10 = (__PAIR64__(v7, v9) - v36) >> 32;
  v11 = v9 - v36;
  v12 = *((_DWORD *)a5 + 5);
  v35 = 0;
  if ( (v12 & 0x3000) == 0x2000 )
  {
    v13 = a7;
    if ( a7 >= 0.0 )
    {
      v34 = 0;
    }
    else
    {
      v34 = 1;
      v13 = -a7;
    }
    v14 = 1.0e35;
    v15 = 1.0e10;
    if ( v13 >= 1.0e35 )
    {
      while ( v35 < 0x1388 )
      {
        v13 = v13 / v15;
        v35 += 10;
        v18 = v15;
        v19 = v14;
        v16 = v18;
        if ( v19 > v13 )
          goto LABEL_19;
        v17 = v19;
        v15 = v16;
        v14 = v17;
      }
    }
    v16 = v15;
LABEL_19:
    v20 = v16;
    if ( v13 > 0.0 && v10 >= 0 && (v10 > 0 || v11 >= 0xA) )
    {
      v21 = 1.0e-35;
      while ( v21 >= v13 && v8 < 0x1388 )
      {
        v23 = __CFADD__(v11, -10);
        v11 -= 10;
        v24 = v21;
        v25 = v13;
        v26 = v24;
        v10 = v23 + v10 - 1;
        v27 = v25 * v20;
        v8 += 10;
        if ( v10 <= 0 && (v10 < 0 || v11 < 0xA) )
        {
          v13 = v27;
          break;
        }
        v22 = v27;
        v21 = v26;
        v13 = v22;
      }
    }
    v28 = v13;
    if ( v34 )
      v28 = -v13;
  }
  else
  {
    v28 = a7;
  }
  Format = 37;
  v29 = &v39;
  if ( (v12 & 0x20) != 0 )
  {
    v39 = 43;
    v29 = &v40;
  }
  if ( (v12 & 0x10) != 0 )
    *v29++ = 35;
  v30 = v12 & 0x3000;
  *(_WORD *)v29 = 10798;
  v29[2] = 76;
  if ( v30 == 0x2000 )
  {
    v31 = 102;
  }
  else if ( v30 == 12288 )
  {
    v31 = 97;
  }
  else
  {
    v31 = 2 * (v30 != 4096) + 101;
  }
  v29[3] = v31;
  v29[4] = 0;
  v32 = sprintf_s(Buffer, 0x6Cu, &Format, v36, v28);
  sub_446C70(v35, v8, (int)this, a2, (int)a5, a6, Buffer, v11, v32, a3, a4);
  return a2;
}
