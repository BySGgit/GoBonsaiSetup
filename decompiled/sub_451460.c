int **__cdecl sub_451460(int **a1, int *a2, int *a3, unsigned __int8 (*a4)(void))
{
  int *v4; // esi
  int *v5; // ebp
  int *v6; // ebx
  int *v7; // edi
  int v8; // ecx
  bool v9; // zf
  int *v10; // ebx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int *v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int *v24; // [esp+10h] [ebp-58h]
  int *v25; // [esp+10h] [ebp-58h]
  int v26; // [esp+14h] [ebp-54h]
  int v27; // [esp+18h] [ebp-50h]
  int v28; // [esp+1Ch] [ebp-4Ch]
  int v29; // [esp+24h] [ebp-44h]
  int v30; // [esp+28h] [ebp-40h]
  int v31; // [esp+40h] [ebp-28h]
  int v32; // [esp+4Ch] [ebp-1Ch]
  int v33; // [esp+58h] [ebp-10h]
  int v34; // [esp+64h] [ebp-4h]

  v4 = &a2[3 * (((char *)a3 - (char *)a2) / 12 / 2)];
  sub_451720(a2, v4, a3 - 3, a4);
  v5 = v4 + 3;
  if ( a2 < v4 )
  {
    do
    {
      v24 = v4 - 3;
      if ( ((unsigned __int8 (__cdecl *)(int *, int *))a4)(v4 - 3, v4) )
        break;
      if ( ((unsigned __int8 (__cdecl *)(int *, int *))a4)(v4, v24) )
        break;
      v4 -= 3;
    }
    while ( a2 < v24 );
  }
  for ( ; v5 < a3; v5 += 3 )
  {
    if ( ((unsigned __int8 (__cdecl *)(int *, int *))a4)(v5, v4) )
      break;
    if ( ((unsigned __int8 (__cdecl *)(int *, int *))a4)(v4, v5) )
      break;
  }
  v6 = v4;
  v7 = v5;
  v25 = v4;
  while ( 1 )
  {
    while ( 1 )
    {
      for ( ; v7 < a3; v7 += 3 )
      {
        if ( !((unsigned __int8 (__cdecl *)(int *, int *))a4)(v4, v7) )
        {
          if ( ((unsigned __int8 (__cdecl *)(int *, int *))a4)(v7, v4) )
            break;
          v8 = *v5;
          v29 = v5[1];
          v30 = v5[2];
          *v5 = *v7;
          v5[1] = v7[1];
          v5[2] = v7[2];
          *v7 = v8;
          v7[1] = v29;
          v5 += 3;
          v7[2] = v30;
        }
      }
      v9 = v6 == a2;
      if ( v6 > a2 )
      {
        v10 = v6 - 3;
        do
        {
          if ( !((unsigned __int8 (__cdecl *)(int *, int *))a4)(v10, v4) )
          {
            if ( ((unsigned __int8 (__cdecl *)(int *, int *))a4)(v4, v10) )
              break;
            v11 = *(v4 - 1);
            v12 = *(v4 - 3);
            v13 = *(v4 - 2);
            v4 -= 3;
            *v4 = *v10;
            v4[1] = v10[1];
            v4[2] = v10[2];
            *v10 = v12;
            v10[1] = v13;
            v10[2] = v11;
          }
          v10 -= 3;
          v25 -= 3;
        }
        while ( a2 < v25 );
        v6 = v25;
        v9 = v25 == a2;
      }
      if ( v9 )
        break;
      v6 -= 3;
      v25 = v6;
      if ( v7 == a3 )
      {
        v4 -= 3;
        if ( v6 != v4 )
        {
          v17 = *v6;
          v18 = v6[1];
          v32 = v6[2];
          *v6 = *v4;
          v6[1] = v4[1];
          v6[2] = v4[2];
          *v4 = v17;
          v4[1] = v18;
          v4[2] = v32;
        }
        v19 = *v4;
        v20 = v4[1];
        v5 -= 3;
        v33 = v4[2];
        *v4 = *v5;
        v4[1] = v5[1];
        v4[2] = v5[2];
        *v5 = v19;
        v5[1] = v20;
        v5[2] = v33;
      }
      else
      {
        v21 = *v7;
        v22 = v7[1];
        v34 = v7[2];
        *v7 = *v6;
        v7[1] = v6[1];
        v7[2] = v6[2];
        *v6 = v21;
        v6[1] = v22;
        v6[2] = v34;
        v7 += 3;
      }
    }
    if ( v7 == a3 )
      break;
    if ( v5 != v7 )
    {
      v14 = *v4;
      v15 = v4[1];
      v31 = v4[2];
      *v4 = *v5;
      v4[1] = v5[1];
      v4[2] = v5[2];
      *v5 = v14;
      v5[1] = v15;
      v5[2] = v31;
    }
    v26 = *v4;
    v16 = v7;
    v27 = v4[1];
    v28 = v4[2];
    *v4 = *v7;
    v4[1] = v7[1];
    v4[2] = v7[2];
    *v7 = v26;
    v5 += 3;
    v4 += 3;
    v7[1] = v27;
    v7 += 3;
    v16[2] = v28;
  }
  *a1 = v4;
  a1[1] = v5;
  return a1;
}
