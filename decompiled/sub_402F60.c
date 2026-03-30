void __fastcall sub_402F60(unsigned int a1, int *a2, char *a3, void **a4)
{
  char *v6; // ebx
  _DWORD *v7; // ecx
  int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // eax
  void *v12; // eax
  int v13; // ebx
  unsigned int v14; // ecx
  char *v15; // ebx
  unsigned int v16; // edi
  int v17; // esi
  void **v18; // eax
  int v19; // eax
  char *v20; // edi
  _DWORD *v21; // eax
  char *v22; // ecx
  char *v23; // eax
  int v24; // ebx
  int v25; // edx
  void **v26; // eax
  int v27; // [esp+0h] [ebp-28h] BYREF
  void *v28; // [esp+10h] [ebp-18h] BYREF
  unsigned int v29; // [esp+14h] [ebp-14h]
  int *v30; // [esp+18h] [ebp-10h]
  int v31; // [esp+24h] [ebp-4h]
  int v32; // [esp+34h] [ebp+Ch]

  v30 = &v27;
  if ( a1 )
  {
    v6 = (char *)a2[1];
    v7 = (_DWORD *)*a2;
    v8 = (int)&v6[-*a2] >> 2;
    if ( 0x3FFFFFFF - v8 < a1 )
      std::_Xlength_error("vector<T> too long");
    v9 = v8 + a1;
    v10 = (a2[2] - (int)v7) >> 2;
    if ( v10 >= v9 )
    {
      if ( (v6 - a3) >> 2 >= a1 )
      {
        v28 = *a4;
        v19 = 4 * a1;
        v20 = &v6[-4 * a1];
        v32 = v19;
        v21 = sub_4032A0(v6, v6, v20);
        v22 = a3;
        a2[1] = (int)v21;
        v23 = v20;
        if ( a3 != v20 )
        {
          v24 = v6 - v20;
          do
          {
            v25 = *((_DWORD *)v23 - 1);
            v23 -= 4;
            *(_DWORD *)&v23[v24] = v25;
            v22 = a3;
          }
          while ( a3 != v23 );
        }
        v26 = (void **)v22;
        if ( v22 != &v22[v32] )
        {
          do
            *v26++ = v28;
          while ( v26 != (void **)&a3[v32] );
        }
      }
      else
      {
        v28 = *a4;
        sub_4032A0(&a3[4 * a1], v6, a3);
        v31 = 2;
        sub_403210(a1 - ((a2[1] - (int)a3) >> 2), &v28, (_DWORD *)a2[1]);
        a2[1] += 4 * a1;
        v17 = a2[1] - 4 * a1;
        v18 = (void **)a3;
        if ( a3 != (char *)v17 )
        {
          do
            *v18++ = v28;
          while ( v18 != (void **)v17 );
        }
      }
    }
    else
    {
      if ( 0x3FFFFFFF - (v10 >> 1) >= v10 )
      {
        v11 = (v10 >> 1) + v10;
        v29 = v11;
      }
      else
      {
        v29 = 0;
        v11 = 0;
      }
      if ( v11 < v9 )
      {
        v29 = v9;
        v11 = v9;
      }
      v12 = sub_4031B0(v11);
      v13 = (int)&a3[-*a2];
      v31 = 0;
      v28 = v12;
      v13 >>= 2;
      sub_403210(a1, a4, (_DWORD *)v12 + v13);
      sub_4032A0(v28, a3, (_DWORD *)*a2);
      v14 = v13 + a1;
      v15 = (char *)v28;
      sub_4032A0((_DWORD *)v28 + v14, (_DWORD *)a2[1], a3);
      v16 = ((a2[1] - *a2) >> 2) + a1;
      if ( *a2 )
        operator delete((void *)*a2);
      a2[2] = (int)&v15[4 * v29];
      a2[1] = (int)&v15[4 * v16];
      *a2 = (int)v15;
    }
  }
}
