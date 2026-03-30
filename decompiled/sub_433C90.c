int __thiscall sub_433C90(int this, float a2)
{
  int v3; // edi
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  LONG *v7; // ecx
  _DWORD *v8; // esi
  unsigned int v9; // eax
  LONG top; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // edi
  int v14; // edx
  int v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // eax
  LONG *v19; // edi
  int v20; // eax
  int v21; // eax
  LONG *v22; // ecx
  int v23; // edi
  double v24; // st7
  int v25; // edi
  LONG v26; // ecx
  LONG v27; // edx
  LONG v28; // eax
  int v29; // eax
  int v30; // edi
  int v31; // eax
  LONG *v32; // esi
  int result; // eax
  int v34; // ebx
  int v35; // [esp+0h] [ebp-5Ch]
  int v36; // [esp+1Ch] [ebp-40h]
  int v37; // [esp+1Ch] [ebp-40h]
  int v38; // [esp+1Ch] [ebp-40h]
  int v39; // [esp+20h] [ebp-3Ch]
  int v40; // [esp+24h] [ebp-38h]
  int v41; // [esp+24h] [ebp-38h]
  int v42; // [esp+24h] [ebp-38h]
  int v43; // [esp+28h] [ebp-34h]
  float v44; // [esp+28h] [ebp-34h]
  int dy; // [esp+2Ch] [ebp-30h]
  int dya; // [esp+2Ch] [ebp-30h]
  int v47; // [esp+30h] [ebp-2Ch]
  struct tagRECT rc; // [esp+38h] [ebp-24h] BYREF
  struct tagRECT v49; // [esp+48h] [ebp-14h] BYREF

  v36 = 0;
  if ( !*(_BYTE *)(this + 804) )
    v36 = 2;
  v3 = *(_DWORD *)(*(_DWORD *)(this + 32) + 8);
  v40 = v3;
  if ( !byte_4D8E18 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 24) + 572) + 80) + 4 * *(_DWORD *)(v3 + 4))
                   + 520);
    if ( v4 )
      v5 = (*(_DWORD *)(this + 868) - *(_DWORD *)(this + 860)) / v4;
    else
      v5 = *(_DWORD *)(this + 868) - *(_DWORD *)(this + 860);
    sub_437460(this + 616, v5);
    byte_4D8E18 = 1;
  }
  if ( *(_BYTE *)(this + 804) )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)(this + 616) + 12))(LODWORD(a2));
  sub_437110(v36, (float *)(v3 + 28), a2, 0.69999999);
  sub_437110(v36, (float *)(v3 + 68), a2, 0.69999999);
  v6 = *(_DWORD *)(this + 24);
  v7 = (LONG *)(this + 840);
  if ( *(_DWORD *)(*(_DWORD *)(v6 + 572) + 60) )
    sub_430950(v3, v7, *(_DWORD *)(this + 24));
  else
    sub_430C90(v7, v6, v3, 0.60000002);
  v8 = *(_DWORD **)(*(_DWORD *)(this + 32) + 12);
  v8[13] = *(_DWORD *)(v3 + 52);
  v8[14] = *(_DWORD *)(v3 + 56);
  v8[15] = *(_DWORD *)(v3 + 60);
  v9 = v8[17];
  v8[16] = *(_DWORD *)(v3 + 64);
  *(float *)&rc.left = (double)BYTE2(v9) * 0.003921568859368563;
  v37 = (int)v8;
  *(float *)&rc.top = (double)BYTE1(v9) * 0.003921568859368563;
  top = rc.top;
  v8[23] = rc.left;
  v8[24] = top;
  *(float *)&rc.right = (double)(unsigned __int8)v9 * 0.003921568859368563;
  v8[25] = rc.right;
  *(float *)&rc.bottom = 0.003921568859368563 * (double)HIBYTE(v9);
  v8[26] = rc.bottom;
  v11 = *(_DWORD *)(this + 24);
  v12 = *(_DWORD *)(v11 + 572);
  if ( v12 )
  {
    v13 = *(_DWORD *)(*(_DWORD *)(v12 + 80) + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 596) + 4 * *(_DWORD *)(v3 + 4)));
    v39 = v13;
    if ( v13 )
    {
      v14 = *(_DWORD *)(this + 860);
      v15 = *(_DWORD *)(this + 764);
      v16 = *(_DWORD *)(this + 868) - v14;
      v43 = v14;
      dy = v15;
      if ( v15 < *(_DWORD *)(this + 876) )
      {
        while ( 1 )
        {
          v17 = *(_DWORD *)(*(_DWORD *)(this + 872) + 4 * v15);
          v18 = *(_DWORD *)(v13 + 520);
          v47 = v16 - v18;
          if ( v16 - v18 < 0 )
          {
            *(_BYTE *)(v17 + 532) = 0;
            goto LABEL_32;
          }
          v19 = (LONG *)(v17 + 516);
          SetRect((LPRECT)(v17 + 516), *(_DWORD *)(this + 856), v14, *(_DWORD *)(this + 864), v14 + v18);
          v43 += *(_DWORD *)(v39 + 520);
          *(_BYTE *)(v17 + 532) = 1;
          if ( *(_BYTE *)(this + 804) )
          {
            if ( dy == *(_DWORD *)(this + 608) )
            {
              SetRect(
                &rc,
                *(_DWORD *)(this + 840),
                *(_DWORD *)(v17 + 520) - 2,
                *(_DWORD *)(this + 848),
                *(_DWORD *)(v17 + 528) + 2);
              v20 = *(_DWORD *)(this + 24);
              if ( *(_DWORD *)(*(_DWORD *)(v20 + 572) + 60) )
              {
                sub_430950(v37, &rc.left, *(_DWORD *)(this + 24));
                v19 = (LONG *)(v17 + 516);
              }
              else
              {
                sub_430C90(&rc.left, v20, v37, 0.60000002);
              }
              v21 = *(_DWORD *)(this + 24);
              v22 = v19;
              v35 = v17;
              if ( *(_DWORD *)(*(_DWORD *)(v21 + 572) + 60) )
              {
                sub_431020(v19, v21, v37, v17, 0, -1);
                goto LABEL_32;
              }
              v23 = v37;
            }
            else
            {
              v21 = *(_DWORD *)(this + 24);
              v35 = v17;
              v22 = (LONG *)(v17 + 516);
              if ( *(_DWORD *)(*(_DWORD *)(v21 + 572) + 60) )
              {
                sub_431020(v22, v21, v40, v17, 0, -1);
                goto LABEL_32;
              }
              v23 = v40;
            }
            sub_431380(v22, v23, v21, v35, 0, -1);
          }
LABEL_32:
          v15 = dy + 1;
          dy = v15;
          if ( v15 >= *(_DWORD *)(this + 876) )
            break;
          v16 = v47;
          v14 = v43;
          v13 = v39;
        }
      }
    }
  }
  v41 = 0;
  dya = 0;
  v38 = 0;
  if ( !*(_BYTE *)(this + 4) )
  {
    v38 = 2;
LABEL_35:
    v24 = 0.80000001;
    goto LABEL_36;
  }
  if ( !*(_BYTE *)(this + 60) )
  {
    v38 = 1;
    goto LABEL_35;
  }
  if ( !*(_BYTE *)(this + 600) )
  {
    if ( *(_BYTE *)(this + 5) )
    {
      v38 = 4;
      v41 = -1;
      dya = -2;
    }
    else if ( *(_BYTE *)(this + 6) )
    {
      v38 = 3;
    }
    goto LABEL_35;
  }
  v24 = 0.0;
  v38 = 5;
  v41 = 1;
  dya = 2;
LABEL_36:
  v44 = v24;
  v25 = *(_DWORD *)(*(_DWORD *)(this + 32) + 4);
  sub_437110(v38, (float *)(v25 + 28), a2, v44);
  v26 = *(_DWORD *)(this + 828);
  v27 = *(_DWORD *)(this + 832);
  v49.left = *(_DWORD *)(this + 824);
  v28 = *(_DWORD *)(this + 836);
  v49.top = v26;
  v49.right = v27;
  v49.bottom = v28;
  OffsetRect(&v49, v41, dya);
  v29 = *(_DWORD *)(this + 24);
  if ( *(_DWORD *)(*(_DWORD *)(v29 + 572) + 60) )
    sub_430950(v25, &v49.left, *(_DWORD *)(this + 24));
  else
    sub_430C90(&v49.left, v29, v25, 0.80000001);
  if ( *(_BYTE *)(this + 804) )
    v38 = 5;
  v42 = **(_DWORD **)(this + 32);
  v30 = v42;
  sub_437110(v38, (float *)(v42 + 28), a2, v44);
  sub_437110(v38, (float *)(v42 + 68), a2, v44);
  v31 = *(_DWORD *)(this + 24);
  v32 = (LONG *)(this + 808);
  if ( *(_DWORD *)(*(_DWORD *)(v31 + 572) + 60) )
  {
    sub_430950(v42, (LONG *)(this + 808), *(_DWORD *)(this + 24));
    v30 = v42;
  }
  else
  {
    sub_430C90((LONG *)(this + 808), v31, v42, 0.60000002);
  }
  result = *(_DWORD *)(this + 604);
  if ( result >= 0 && result < *(_DWORD *)(this + 876) )
  {
    result = *(_DWORD *)(*(_DWORD *)(this + 872) + 4 * result);
    if ( result )
    {
      v34 = *(_DWORD *)(this + 24);
      if ( *(_DWORD *)(*(_DWORD *)(v34 + 572) + 60) )
        return sub_431020(v32, v34, v30, result, 0, -1);
      else
        return sub_431380(v32, v30, v34, result, 0, -1);
    }
  }
  return result;
}
