void __thiscall sub_44A640(int **this)
{
  int **v1; // edi
  unsigned int v2; // ebx
  int **v3; // eax
  int **v4; // ebp
  int v5; // eax
  int v6; // ecx
  int *v7; // edx
  int v8; // esi
  unsigned int v9; // edi
  int ***v10; // esi
  int **v11; // ecx
  int **v12; // eax
  int ***v13; // eax
  int **v14; // ecx
  int **v15; // edx
  int **v16; // ecx
  int ***v17; // esi
  int **v18; // esi
  unsigned int v19; // ebx
  int *v20; // eax
  int *v21; // esi
  unsigned int v23; // [esp+14h] [ebp-168h]
  int **v24; // [esp+18h] [ebp-164h] BYREF
  int **v25; // [esp+1Ch] [ebp-160h]
  char *v26; // [esp+24h] [ebp-158h] BYREF
  _DWORD pExceptionObject[3]; // [esp+28h] [ebp-154h] BYREF
  _DWORD v28[3]; // [esp+34h] [ebp-148h] BYREF
  char v29; // [esp+40h] [ebp-13Ch] BYREF
  int **v30; // [esp+154h] [ebp-28h] BYREF
  int v31; // [esp+178h] [ebp-4h]

  v1 = this;
  if ( (unsigned int)*(this + 1) >= 2 )
  {
    v2 = 0;
    v25 = 0;
    v3 = (int **)operator new(0xCu);
    if ( !v3 )
    {
      v26 = 0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v26);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
    v4 = v3;
    *v3 = (int *)v3;
    v24 = v3;
    v3[1] = (int *)v3;
    v31 = 0;
    `eh vector constructor iterator'(
      v28,
      0xCu,
      26,
      (void (__thiscall *)(void *))sub_444090,
      (void (__thiscall *)(void *))sub_4440F0);
    LOBYTE(v31) = 1;
    if ( v1[1] )
    {
      do
      {
        v5 = *(_DWORD *)**v1;
        v6 = **v1;
        v7 = *v4;
        if ( &v24 != (int ***)v1 )
        {
          if ( v25 == (int **)1073741822 )
            std::_Xlength_error("list<T> too long");
          v25 = (int **)((char *)v25 + 1);
          v1[1] = (int *)((char *)v1[1] - 1);
        }
        **(_DWORD **)(v6 + 4) = v5;
        **(_DWORD **)(v5 + 4) = v7;
        *(_DWORD *)v7[1] = v6;
        v8 = v7[1];
        v7[1] = *(_DWORD *)(v5 + 4);
        v9 = 0;
        *(_DWORD *)(v5 + 4) = *(_DWORD *)(v6 + 4);
        *(_DWORD *)(v6 + 4) = v8;
        if ( !v2 )
          goto LABEL_16;
        v10 = (int ***)v28;
        do
        {
          if ( !v10[1] )
            break;
          sub_44C260(v10, &v24);
          if ( v10 == &v24 )
          {
            v4 = v24;
          }
          else
          {
            v4 = *v10;
            v11 = v25;
            *v10 = v24;
            v12 = v10[1];
            v24 = v4;
            v10[1] = v11;
            v25 = v12;
          }
          ++v9;
          v10 += 3;
        }
        while ( v9 < v2 );
        if ( v9 == 25 )
        {
          sub_44C260(&v30, &v24);
          v4 = v24;
        }
        else
        {
LABEL_16:
          v13 = (int ***)&v28[3 * v9];
          if ( v13 != &v24 )
          {
            v14 = *v13;
            v15 = v25;
            *v13 = v4;
            v4 = v14;
            v16 = v13[1];
            v24 = v4;
            v13[1] = v15;
            v25 = v16;
          }
          if ( v9 == v2 )
            ++v2;
        }
        v1 = this;
      }
      while ( *(this + 1) );
    }
    if ( v2 > 1 )
    {
      v17 = (int ***)&v29;
      v23 = v2 - 1;
      do
      {
        sub_44C260(v17, v17 - 3);
        v17 += 3;
        --v23;
      }
      while ( v23 );
    }
    v18 = (int **)&pExceptionObject[3 * v2];
    if ( v1 != v18 )
    {
      v19 = (unsigned int)v18[1];
      if ( v19 )
        sub_44B900(v19, (int)v1, (int)v18, **v1, **v18, (int)*v18);
    }
    LOBYTE(v31) = 0;
    `eh vector destructor iterator'(v28, 0xCu, 26, (void (__thiscall *)(void *))sub_4440F0);
    v20 = *v4;
    *v4 = (int *)v4;
    v4[1] = (int *)v4;
    if ( v20 != (int *)v4 )
    {
      do
      {
        v21 = (int *)*v20;
        operator delete(v20);
        v20 = v21;
      }
      while ( v21 != (int *)v4 );
    }
    operator delete(v4);
  }
}
