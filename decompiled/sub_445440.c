_DWORD *__thiscall sub_445440(void *this, _DWORD *a2, int a3, _DWORD *a4, __int64 *a5, __int16 a6, double a7)
{
  int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // esi
  double v10; // st7
  int v11; // ecx
  unsigned int v12; // esi
  int v13; // edx
  double v14; // st7
  double v15; // st6
  double v16; // st5
  double v17; // st4
  double v18; // st5
  double v19; // rt2
  double v20; // rtt
  double v21; // st4
  double v22; // rt0
  double v23; // st5
  double v24; // st7
  double v25; // st5
  double v26; // rt1
  bool v27; // cf
  double v28; // rt2
  double v29; // st5
  double v30; // st6
  double v31; // st5
  char *v32; // eax
  int v33; // edx
  char v34; // cl
  size_t v35; // eax
  char v37; // [esp+3Fh] [ebp-91h]
  size_t v38; // [esp+40h] [ebp-90h]
  int v39; // [esp+44h] [ebp-8Ch]
  char Format; // [esp+50h] [ebp-80h] BYREF
  char v42; // [esp+51h] [ebp-7Fh] BYREF
  char v43; // [esp+52h] [ebp-7Eh] BYREF
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
    v39 = v9;
  else
    v39 = 36;
  v10 = a7;
  v11 = (__PAIR64__(v7, v9) - v39) >> 32;
  v12 = v9 - v39;
  v13 = *((_DWORD *)a5 + 5);
  v38 = 0;
  if ( (v13 & 0x3000) == 0x2000 && a7 != 0.5 * a7 )
  {
    if ( a7 >= 0.0 )
    {
      v37 = 0;
      v15 = a7;
      v14 = 0.0;
    }
    else
    {
      v14 = 0.0;
      v37 = 1;
      v15 = -a7;
    }
    v16 = 1.0e35;
    v17 = 1.0e10;
    if ( v15 >= 1.0e35 )
    {
      while ( v38 < 0x1388 )
      {
        v15 = v15 / v17;
        v38 += 10;
        v20 = v17;
        v21 = v16;
        v18 = v20;
        if ( v21 > v15 )
          goto LABEL_20;
        v19 = v21;
        v17 = v18;
        v16 = v19;
      }
    }
    v18 = v17;
LABEL_20:
    v22 = v18;
    v23 = v14;
    v24 = v22;
    if ( v23 < v15 && v11 >= 0 && (v11 > 0 || v12 >= 0xA) )
    {
      v25 = 1.0e-35;
      while ( v25 >= v15 && v8 < 0x1388 )
      {
        v27 = __CFADD__(v12, -10);
        v12 -= 10;
        v28 = v25;
        v29 = v15;
        v30 = v28;
        v11 = v27 + v11 - 1;
        v31 = v29 * v24;
        v8 += 10;
        if ( v11 <= 0 && (v11 < 0 || v12 < 0xA) )
        {
          v15 = v31;
          break;
        }
        v26 = v31;
        v25 = v30;
        v15 = v26;
      }
    }
    v10 = v15;
    if ( v37 )
      v10 = -v15;
  }
  Format = 37;
  v32 = &v42;
  if ( (v13 & 0x20) != 0 )
  {
    v42 = 43;
    v32 = &v43;
  }
  if ( (v13 & 0x10) != 0 )
    *v32++ = 35;
  v33 = v13 & 0x3000;
  *(_WORD *)v32 = 10798;
  if ( v33 == 0x2000 )
  {
    v34 = 102;
  }
  else if ( v33 == 12288 )
  {
    v34 = 97;
  }
  else
  {
    v34 = 2 * (v33 != 4096) + 101;
  }
  v32[2] = v34;
  v32[3] = 0;
  v35 = sprintf_s(Buffer, 0x6Cu, &Format, v39, v10);
  sub_446C70(v38, v8, (int)this, a2, (int)a5, a6, Buffer, v12, v35, a3, a4);
  return a2;
}
