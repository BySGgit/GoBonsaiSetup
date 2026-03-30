int __stdcall sub_43EB70(int *a1)
{
  int *v1; // ebx
  int v2; // ecx
  int v3; // eax
  int *v4; // esi
  int v5; // edi
  int result; // eax
  int v7; // esi
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // ebp
  int v12; // ebx
  int v13; // esi
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  char v17; // [esp+13h] [ebp-35h]
  _DWORD *v18; // [esp+14h] [ebp-34h]
  int v19; // [esp+18h] [ebp-30h]
  float v20; // [esp+1Ch] [ebp-2Ch]
  float v21; // [esp+20h] [ebp-28h]
  float v22; // [esp+20h] [ebp-28h]
  float v23; // [esp+20h] [ebp-28h]
  int v24; // [esp+24h] [ebp-24h]
  int v25; // [esp+28h] [ebp-20h]
  char Args[28]; // [esp+2Ch] [ebp-1Ch] BYREF

  v1 = a1;
  v24 = *(_DWORD *)::Args;
  v2 = a1[157];
  v25 = *(_DWORD *)dword_4D7E00;
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_6:
    v18 = 0;
    sub_434340(0);
  }
  else
  {
    v4 = (int *)a1[156];
    while ( *(_DWORD *)(*v4 + 44) != 30 || *(_DWORD *)(*v4 + 48) != 4 )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
    v18 = (_DWORD *)*v4;
    sub_434340(*v4);
  }
  v5 = sub_43B220();
  v19 = v5;
  if ( !v5 )
    return -2147467259;
  v7 = a1[157];
  v8 = 0;
  if ( v7 <= 0 )
  {
LABEL_15:
    v10 = 0;
  }
  else
  {
    v9 = a1[156];
    while ( 1 )
    {
      v10 = *(_DWORD *)v9;
      if ( *(_DWORD *)(*(_DWORD *)v9 + 44) == 26 && *(_DWORD *)(v10 + 48) == 2 )
        break;
      ++v8;
      v9 += 4;
      if ( v8 >= v7 )
        goto LABEL_15;
    }
  }
  v17 = *(_BYTE *)(v10 + 604);
  sub_4383E0(dword_4D7DF4, (DWORD *)Args, (DWORD *)&Args[4]);
  v11 = 0;
  v20 = (double)*(unsigned int *)Args / (double)*(unsigned int *)&Args[4];
  if ( *(int *)(v5 + 108) > 0 )
  {
    v12 = 0;
    while ( 1 )
    {
      qmemcpy(Args, (const void *)(v12 + *(_DWORD *)(v5 + 104)), sizeof(Args));
      if ( *(_DWORD *)&Args[16] == dword_4D7E10 )
      {
        if ( v17
          || (v21 = (double)*(unsigned int *)Args / (double)*(unsigned int *)&Args[4],
              v22 = v20 - v21,
              v23 = fabs(v22),
              v23 < 0.05000000074505806) )
        {
          sub_43DDC0(a1, *(int *)Args, *(int *)&Args[4]);
        }
      }
      ++v11;
      v12 += 28;
      if ( v11 >= *(_DWORD *)(v19 + 108) )
        break;
      v5 = v19;
    }
    v1 = a1;
  }
  sub_4344D0(v18, *(unsigned __int16 *)dword_4D7E00 | (*(unsigned __int16 *)::Args << 16));
  result = sub_43C7D0(v1);
  if ( result >= 0 )
  {
    v13 = v1[157];
    v14 = 0;
    if ( v13 <= 0 )
    {
LABEL_31:
      v16 = 0;
    }
    else
    {
      v15 = v1[156];
      while ( 1 )
      {
        v16 = *(_DWORD *)v15;
        if ( *(_DWORD *)(*(_DWORD *)v15 + 44) == 5 && *(_DWORD *)(v16 + 48) == 3 )
          break;
        ++v14;
        v15 += 4;
        if ( v14 >= v13 )
          goto LABEL_31;
      }
    }
    if ( !*(_BYTE *)(v16 + 604) )
      return 0;
    sub_434340((int)v18);
    sub_43DDC0(v1, v25, v24);
    sub_4344D0(v18, (unsigned __int16)v25 | ((unsigned __int16)v24 << 16));
    result = sub_43C7D0(v1);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
