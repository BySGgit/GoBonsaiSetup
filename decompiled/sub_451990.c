void __cdecl sub_451990(_DWORD *a1, _DWORD *a2, unsigned __int8 (__cdecl *a3)(int *, _DWORD *))
{
  _DWORD *v3; // ebp
  _DWORD *v4; // ebx
  _DWORD *v5; // esi
  int v6; // ecx
  int v7; // edx
  _DWORD *v8; // edi
  _DWORD *i; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // [esp+8h] [ebp-Ch] BYREF
  int v16; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]

  v3 = a1;
  v4 = a1 + 3;
  if ( a1 + 3 != a2 )
  {
    v5 = a1;
    do
    {
      v6 = v4[1];
      v7 = v4[2];
      v15 = *v4;
      v8 = v4;
      v16 = v6;
      v17 = v7;
      if ( a3(&v15, v3) )
      {
        for ( i = v4; i != v3; i[5] = i[2] )
        {
          v10 = *(i - 3);
          i -= 3;
          i[3] = v10;
          i[4] = i[1];
        }
        v11 = v16;
        v12 = v17;
        *v3 = v15;
        v3[1] = v11;
        v3[2] = v12;
      }
      else
      {
        if ( a3(&v15, a1) )
        {
          do
          {
            *v8 = *v5;
            v8[1] = v5[1];
            v8[2] = v5[2];
            v8 = v5;
            v5 -= 3;
          }
          while ( a3(&v15, v5) );
        }
        v13 = v16;
        v14 = v17;
        *v8 = v15;
        v8[1] = v13;
        v8[2] = v14;
      }
      v4 += 3;
      v5 = a1 + 3;
      a1 += 3;
    }
    while ( v4 != a2 );
  }
}
