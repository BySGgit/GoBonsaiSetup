void __cdecl qsort(
        void *Base,
        size_t NumOfElements,
        size_t SizeOfElements,
        _CoreCrtNonSecureSearchSortCompareFunction CompareFunction)
{
  _BYTE *v4; // edi
  size_t v5; // ebx
  _BYTE *v6; // esi
  unsigned int v7; // eax
  _BYTE *v8; // ebx
  size_t v9; // edx
  _BYTE *v10; // eax
  int v11; // ecx
  size_t v12; // ecx
  _BYTE *v13; // eax
  int v14; // edi
  size_t v15; // ecx
  _BYTE *v16; // eax
  int v17; // edi
  size_t v18; // edx
  _BYTE *v19; // eax
  int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // edx
  int v23; // ecx
  int v24; // ecx
  int v25; // eax
  _BYTE *v26; // edx
  _BYTE *v27; // eax
  _DWORD v28[60]; // [esp+8h] [ebp-100h]
  size_t v29; // [esp+F8h] [ebp-10h]
  int v30; // [esp+FCh] [ebp-Ch]
  _BYTE *v31; // [esp+100h] [ebp-8h]
  _BYTE *v32; // [esp+104h] [ebp-4h]
  char Base_3; // [esp+113h] [ebp+Bh]
  char Base_3a; // [esp+113h] [ebp+Bh]
  char Base_3b; // [esp+113h] [ebp+Bh]
  char Base_3c; // [esp+113h] [ebp+Bh]

  v4 = Base;
  if ( !Base && NumOfElements )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  v5 = SizeOfElements;
  if ( !SizeOfElements || !CompareFunction )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  if ( NumOfElements >= 2 )
  {
    v6 = (char *)Base + SizeOfElements * (NumOfElements - 1);
    v30 = 0;
    v32 = Base;
    v31 = v6;
    while ( 1 )
    {
      v7 = (v6 - v4) / v5 + 1;
      if ( v7 <= 8 )
      {
        shortsort(v6, (unsigned int)v4, v5, (int (__cdecl *)(unsigned int, unsigned int))CompareFunction);
        goto LABEL_57;
      }
      v8 = &v4[(v7 >> 1) * v5];
      if ( CompareFunction(v4, v8) > 0 )
      {
        v9 = SizeOfElements;
        v10 = v8;
        if ( v4 != v8 )
        {
          v11 = v4 - v8;
          do
          {
            v29 = v9 - 1;
            Base_3 = v10[v11];
            v10[v11] = *v10;
            *v10 = Base_3;
            v9 = v29;
            ++v10;
          }
          while ( v29 );
        }
      }
      if ( CompareFunction(v4, v6) > 0 )
      {
        v12 = SizeOfElements;
        v13 = v6;
        if ( v4 != v6 )
        {
          v14 = v4 - v6;
          do
          {
            Base_3a = v13[v14];
            v13[v14] = *v13;
            *v13++ = Base_3a;
            --v12;
          }
          while ( v12 );
          v4 = v32;
        }
      }
      if ( CompareFunction(v8, v6) > 0 )
      {
        v15 = SizeOfElements;
        v16 = v6;
        if ( v8 != v6 )
        {
          v17 = v8 - v6;
          do
          {
            Base_3b = v16[v17];
            v16[v17] = *v16;
            *v16++ = Base_3b;
            --v15;
          }
          while ( v15 );
          v4 = v32;
        }
      }
      while ( 1 )
      {
        if ( v8 > v4 )
        {
          while ( 1 )
          {
            v4 += SizeOfElements;
            if ( v4 >= v8 )
              break;
            if ( CompareFunction(v4, v8) > 0 )
            {
              if ( v8 > v4 )
                goto LABEL_32;
              goto LABEL_30;
            }
          }
        }
        do
LABEL_30:
          v4 += SizeOfElements;
        while ( v4 <= v31 && CompareFunction(v4, v8) <= 0 );
        do
LABEL_32:
          v6 -= SizeOfElements;
        while ( v6 > v8 && CompareFunction(v6, v8) > 0 );
        if ( v4 > v6 )
          break;
        v18 = SizeOfElements;
        v19 = v6;
        if ( v4 != v6 )
        {
          v20 = v4 - v6;
          do
          {
            v29 = v18 - 1;
            Base_3c = v19[v20];
            v19[v20] = *v19;
            *v19 = Base_3c;
            v18 = v29;
            ++v19;
          }
          while ( v29 );
        }
        if ( v8 == v6 )
          v8 = v4;
      }
      v6 += SizeOfElements;
      if ( v8 >= v6 )
        goto LABEL_44;
      do
      {
        v6 -= SizeOfElements;
        if ( v6 <= v8 )
          goto LABEL_44;
      }
      while ( !CompareFunction(v6, v8) );
      if ( v8 < v6 )
      {
LABEL_46:
        v21 = (unsigned int)v32;
      }
      else
      {
LABEL_44:
        while ( 1 )
        {
          v6 -= SizeOfElements;
          v21 = (unsigned int)v32;
          if ( v6 <= v32 )
            break;
          if ( CompareFunction(v6, v8) )
            goto LABEL_46;
        }
      }
      v22 = (unsigned int)v31;
      if ( (int)&v6[-v21] < v31 - v4 )
      {
        if ( v4 < v31 )
        {
          v24 = v30;
          v28[v30 + 30] = v4;
          v28[v24] = v22;
          v30 = v24 + 1;
        }
        if ( v21 >= (unsigned int)v6 )
          goto LABEL_56;
        v4 = v32;
        v5 = SizeOfElements;
        v31 = v6;
      }
      else
      {
        if ( v21 < (unsigned int)v6 )
        {
          v23 = v30;
          v28[v30 + 30] = v21;
          v28[v23] = v6;
          v30 = v23 + 1;
        }
        if ( (unsigned int)v4 >= v22 )
        {
LABEL_56:
          v5 = SizeOfElements;
LABEL_57:
          v25 = --v30;
          if ( v30 < 0 )
            return;
          v26 = (_BYTE *)v28[v25 + 30];
          v27 = (_BYTE *)v28[v25];
          v32 = v26;
          v31 = v27;
          v6 = v27;
          v4 = v26;
        }
        else
        {
          v6 = v31;
          v5 = SizeOfElements;
          v32 = v4;
        }
      }
    }
  }
}
