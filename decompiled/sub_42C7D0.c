int __usercall sub_42C7D0@<eax>(int *a1@<edi>, int a2, _DWORD *a3)
{
  int result; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // [esp-8h] [ebp-30h]
  int v10; // [esp+Ch] [ebp-1Ch] BYREF
  int v11; // [esp+10h] [ebp-18h]
  int v12; // [esp+14h] [ebp-14h]
  int v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-Ch]
  int v15; // [esp+20h] [ebp-8h]
  int v16; // [esp+24h] [ebp-4h]

  memset(a1, 0, 0x5Cu);
  v15 = 0;
  v16 = 0;
  v9 = *a1;
  v10 = 640;
  v11 = 480;
  v12 = 60;
  v13 = 1;
  v14 = 29;
  sub_42D830(&v10, v9, 0);
  result = 0;
  if ( a3[1] )
    *a1 = *(_DWORD *)a2;
  else
    *a1 = 0;
  if ( a3[3] )
    a1[1] = *(_DWORD *)(a2 + 4);
  else
    a1[1] = 0;
  if ( a3[4] )
    a1[15] = *(_DWORD *)(a2 + 60);
  else
    a1[15] = 1;
  if ( a3[2] )
    a1[2] = *(_DWORD *)(a2 + 8);
  else
    a1[2] = 0;
  a1[18] = *(_DWORD *)(a2 + 72);
  if ( a3[7] )
  {
    v4 = *(_DWORD *)(a2 + 12);
    v5 = *(_DWORD *)(a2 + 16);
  }
  else
  {
    if ( a1[15] )
    {
      a1[3] = 640;
      a1[4] = 480;
      goto LABEL_19;
    }
    v4 = v10;
    v5 = v11;
  }
  a1[4] = v5;
  a1[3] = v4;
LABEL_19:
  if ( a3[8] )
    a1[7] = *(_DWORD *)(a2 + 28);
  else
    a1[7] = v14;
  a1[12] = 32;
  if ( a3[9] )
    a1[13] = *(_DWORD *)(a2 + 52);
  else
    a1[13] = 2;
  if ( a3[10] )
  {
    v6 = *(_DWORD *)(a2 + 44);
    a1[10] = *(_DWORD *)(a2 + 40);
    a1[11] = v6;
  }
  else
  {
    a1[10] = 0;
    a1[11] = 0;
  }
  if ( a3[11] )
    a1[16] = *(_DWORD *)(a2 + 64);
  else
    a1[16] = 0;
  if ( a3[12] || a3[13] )
  {
    v7 = *(_DWORD *)(a2 + 88);
    *((_BYTE *)a1 + 84) = *(_BYTE *)(a2 + 84);
    a1[22] = v7;
  }
  else
  {
    *((_BYTE *)a1 + 84) = 1;
    a1[22] = 40;
  }
  if ( a3[14] )
    a1[20] = *(_DWORD *)(a2 + 80);
  else
    a1[20] = 0;
  if ( a3[15] )
  {
    v8 = *(_DWORD *)(a2 + 24);
    a1[5] = *(_DWORD *)(a2 + 20);
    a1[6] = v8;
  }
  else
  {
    a1[5] = 60;
    a1[6] = 1;
  }
  if ( a3[16] )
  {
    result = *(_DWORD *)(a2 + 76);
    a1[19] = result;
  }
  else
  {
    a1[19] = 1;
  }
  return result;
}
