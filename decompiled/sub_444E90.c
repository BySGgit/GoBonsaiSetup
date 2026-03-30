int __stdcall sub_444E90(int a1, int a2)
{
  int v2; // ecx
  unsigned int *v3; // edx
  unsigned int v4; // edx
  unsigned int v5; // ecx
  const void *v6; // eax
  void *v7; // ecx
  _DWORD *v8; // ecx
  const void *v9; // eax
  unsigned int v11; // [esp-4h] [ebp-64h]
  void *v12[4]; // [esp+18h] [ebp-48h] BYREF
  int v13; // [esp+28h] [ebp-38h]
  unsigned int v14; // [esp+2Ch] [ebp-34h]
  _DWORD v15[5]; // [esp+34h] [ebp-2Ch] BYREF
  unsigned int v16; // [esp+48h] [ebp-18h]
  int v17; // [esp+5Ch] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 64);
  if ( (v2 & 2) == 0 )
  {
    v3 = *(unsigned int **)(a1 + 36);
    if ( *v3 )
    {
      v4 = *v3;
      v5 = *(_DWORD *)(a1 + 60);
      if ( v5 < v4 )
        v5 = v4;
      v6 = **(const void ***)(a1 + 20);
      v14 = 7;
      v13 = 0;
      LOWORD(v12[0]) = 0;
      sub_4032D0(v6, (int)v12, (int)(v5 - (_DWORD)v6) >> 1);
      v17 = 0;
LABEL_6:
      *(_DWORD *)(a2 + 16) = 0;
      *(_DWORD *)(a2 + 20) = 7;
      *(_WORD *)a2 = 0;
      sub_444AE0(v12, a2);
      if ( v14 >= 8 )
      {
        v7 = v12[0];
LABEL_13:
        operator delete(v7);
        return a2;
      }
      return a2;
    }
  }
  if ( (v2 & 4) == 0 )
  {
    v8 = *(_DWORD **)(a1 + 32);
    if ( *v8 )
    {
      v9 = **(const void ***)(a1 + 16);
      v11 = (*v8 + 2 * **(_DWORD **)(a1 + 48) - (int)v9) >> 1;
      v14 = 7;
      v13 = 0;
      LOWORD(v12[0]) = 0;
      sub_4032D0(v9, (int)v12, v11);
      v17 = 1;
      goto LABEL_6;
    }
  }
  v16 = 7;
  v15[4] = 0;
  LOWORD(v15[0]) = 0;
  v17 = 2;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 7;
  *(_WORD *)a2 = 0;
  sub_444AE0(v15, a2);
  if ( v16 >= 8 )
  {
    v7 = (void *)v15[0];
    goto LABEL_13;
  }
  return a2;
}
