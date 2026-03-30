void __stdcall sub_44C260(int ***a1, int ***a2)
{
  int v2; // edx
  int v3; // esi
  int **v4; // ecx
  int **v5; // eax
  int *v6; // ebx
  int *v7; // ebp
  _DWORD *v8; // eax
  _DWORD *v9; // ecx
  unsigned int v10; // esi
  unsigned int v11; // edi
  unsigned int v12; // edx
  int v13; // eax
  int v14; // edi
  int *v15; // [esp+4h] [ebp-Ch]
  int **v16; // [esp+8h] [ebp-8h]
  int **v17; // [esp+Ch] [ebp-4h]

  v2 = (int)a1;
  v3 = (int)a2;
  if ( a2 != a1 )
  {
    v4 = *a1;
    v5 = *a2;
    v6 = **a2;
    v7 = **a1;
    v17 = *a1;
    v15 = v7;
    v16 = *a2;
    if ( v7 != (int *)*a1 )
    {
      while ( 1 )
      {
        if ( v6 == (int *)v5 )
          return;
        v8 = (_DWORD *)v7[2];
        v9 = (_DWORD *)v6[2];
        v10 = v8[4];
        if ( v8[5] >= 8u )
          v8 = (_DWORD *)*v8;
        v11 = v9[4];
        v12 = v11;
        if ( v11 >= v10 )
          v12 = v10;
        if ( v9[5] >= 8u )
          v9 = (_DWORD *)*v9;
        if ( v12 )
        {
          while ( *(_WORD *)v9 == *(_WORD *)v8 )
          {
            v9 = (_DWORD *)((char *)v9 + 2);
            v8 = (_DWORD *)((char *)v8 + 2);
            if ( !--v12 )
            {
              v7 = v15;
              goto LABEL_14;
            }
          }
          v13 = *(_WORD *)v9 < *(_WORD *)v8 ? -1 : 1;
          v7 = v15;
        }
        else
        {
LABEL_14:
          if ( v11 < v10 )
            goto LABEL_17;
          v13 = v11 != v10;
        }
        if ( v13 >= 0 )
        {
          v7 = (int *)*v7;
          v15 = v7;
          goto LABEL_21;
        }
LABEL_17:
        v14 = *v6;
        sub_44B900(1u, (int)a1, (int)a2, (int)v7, (int)v6, *v6);
        v6 = (int *)v14;
LABEL_21:
        v5 = v16;
        if ( v7 == (int *)v17 )
        {
          v4 = v17;
          v3 = (int)a2;
          v2 = (int)a1;
          break;
        }
      }
    }
    if ( v6 != (int *)v5 )
      sub_44B900(*(_DWORD *)(v3 + 4), v2, v3, (int)v4, (int)v6, (int)v5);
  }
}
