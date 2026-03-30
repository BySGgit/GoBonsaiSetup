int *__thiscall sub_444730(int this, int *a2, __int64 a3, int a4, char a5)
{
  unsigned int *v5; // edx
  unsigned int v6; // eax
  int *v7; // esi
  int v8; // ebx
  int v9; // eax
  int v10; // ebp
  int v11; // edi
  int v12; // esi
  int v13; // esi
  int *v14; // esi
  int v15; // eax
  int v16; // ebx
  int v17; // edx
  unsigned int v18; // eax
  int v19; // esi
  int v20; // esi

  v5 = *(unsigned int **)(this + 36);
  v6 = *v5;
  if ( *v5 && *(_DWORD *)(this + 60) < v6 )
    *(_DWORD *)(this + 60) = v6;
  if ( (a5 & 1) == 0 || (v7 = *(int **)(this + 32), (v8 = *v7) == 0) )
  {
    if ( (a5 & 2) == 0 || !*v5 )
    {
      v10 = HIDWORD(a3);
      v11 = a3;
      if ( !a3 )
        goto LABEL_35;
      goto LABEL_34;
    }
    if ( a4 == 2 )
    {
      v18 = *(_DWORD *)(this + 60);
    }
    else
    {
      if ( a4 != 1 )
      {
        if ( a4 )
        {
          v11 = -1;
          v10 = -1;
        }
        else
        {
          v10 = HIDWORD(a3);
          v11 = a3;
        }
LABEL_30:
        if ( v10 >= 0 )
        {
          v19 = **(_DWORD **)(this + 16);
          if ( __SPAIR64__(v10, v11) <= (*(_DWORD *)(this + 60) - v19) >> 1 )
          {
            v20 = v11 + ((int)(v19 - *v5) >> 1);
            **(_DWORD **)(this + 52) -= v20;
            **(_DWORD **)(this + 36) += 2 * v20;
            goto LABEL_35;
          }
        }
LABEL_34:
        v11 = -1;
        v10 = -1;
        goto LABEL_35;
      }
      v18 = *v5;
    }
    v10 = (unsigned __int64)(((int)(v18 - **(_DWORD **)(this + 16)) >> 1) + a3) >> 32;
    v11 = ((int)(v18 - **(_DWORD **)(this + 16)) >> 1) + a3;
    goto LABEL_30;
  }
  if ( a4 != 2 )
  {
    if ( a4 == 1 )
    {
      if ( (a5 & 2) == 0 )
      {
        v9 = *v7;
        goto LABEL_11;
      }
    }
    else if ( !a4 )
    {
      v10 = HIDWORD(a3);
      v11 = a3;
      goto LABEL_15;
    }
    v11 = -1;
    v10 = -1;
    goto LABEL_15;
  }
  v9 = *(_DWORD *)(this + 60);
LABEL_11:
  v10 = (unsigned __int64)(((v9 - **(_DWORD **)(this + 16)) >> 1) + a3) >> 32;
  v11 = ((v9 - **(_DWORD **)(this + 16)) >> 1) + a3;
LABEL_15:
  if ( v10 < 0 )
    goto LABEL_34;
  v12 = **(_DWORD **)(this + 16);
  if ( __SPAIR64__(v10, v11) > (*(_DWORD *)(this + 60) - v12) >> 1 )
    goto LABEL_34;
  v13 = v11 + ((v12 - v8) >> 1);
  **(_DWORD **)(this + 48) -= v13;
  **(_DWORD **)(this + 32) += 2 * v13;
  if ( (a5 & 2) != 0 )
  {
    v14 = *(int **)(this + 36);
    v15 = *v14;
    if ( *v14 )
    {
      v16 = **(_DWORD **)(this + 52);
      v17 = **(_DWORD **)(this + 32);
      *v14 = v17;
      **(_DWORD **)(this + 52) = (v15 + 2 * v16 - v17) >> 1;
    }
  }
LABEL_35:
  *a2 = v11;
  a2[1] = v10;
  a2[2] = 0;
  a2[3] = 0;
  a2[4] = 0;
  return a2;
}
