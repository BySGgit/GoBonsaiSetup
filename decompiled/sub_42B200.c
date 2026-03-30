int __cdecl sub_42B200(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ecx
  int v6; // edi
  int v8; // eax
  int v9; // edx
  int v10; // ebx
  int *v11; // ecx
  signed int v12; // esi
  int v13; // [esp+10h] [ebp-2Ch]
  int v14; // [esp+14h] [ebp-28h]
  int v15; // [esp+18h] [ebp-24h]
  int v16; // [esp+20h] [ebp-1Ch]
  int v17; // [esp+24h] [ebp-18h]
  int v18; // [esp+28h] [ebp-14h]

  v6 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  if ( v5[4] )
  {
    *a1 = a2;
    a1[1] = a3;
    a1[2] = a4;
    a1[3] = a5;
    return 0;
  }
  else
  {
    v8 = v5[20];
    v9 = *(_DWORD *)(v8 + 1620);
    v10 = 100000;
    v13 = 0;
    v15 = v9;
    if ( v9 > 0 )
    {
      v14 = v5[2];
      v11 = *(int **)(v8 + 1616);
      do
      {
        if ( v11[3] == v14 )
        {
          v12 = abs32(*v11 - a2) + abs32(v11[1] - a3);
          if ( v12 < v10 )
          {
            v16 = v11[1];
            v6 = *v11;
            v17 = v11[2];
            v18 = v11[3];
            v10 = v12;
            if ( !v12 )
              break;
          }
          v9 = v15;
        }
        v11 += 4;
        ++v13;
      }
      while ( v13 < v9 );
    }
    if ( v6 )
    {
      *a1 = v6;
      a1[1] = v16;
      a1[2] = v17;
      a1[3] = v18;
      return 0;
    }
    else
    {
      *a1 = a2;
      a1[1] = a3;
      a1[2] = a4;
      a1[3] = a5;
      return -2147467259;
    }
  }
}
