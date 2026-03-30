int __cdecl sub_42C6B0(int *a1, unsigned int *a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // ebp
  int *v5; // ebx
  int *v6; // edi
  int v7; // eax
  int **v8; // edi
  int v9; // ebp
  int *v10; // esi
  int *v12; // [esp+8h] [ebp-8Ch]
  int v13; // [esp+Ch] [ebp-88h]
  float v14; // [esp+10h] [ebp-84h]
  float v15; // [esp+14h] [ebp-80h]
  int v16[7]; // [esp+18h] [ebp-7Ch] BYREF
  int v17[24]; // [esp+34h] [ebp-60h] BYREF

  v14 = -1.0;
  v4 = 0;
  v12 = 0;
  v5 = (int *)sub_42B3D0();
  v13 = 0;
  if ( v5[15] <= 0 )
    return -2147219198;
  do
  {
    v6 = *(int **)(v5[14] + 4 * v4);
    sub_42D830(v16, *v6, 0);
    v7 = v6[146];
    if ( v7 > 0 )
    {
      v8 = (int **)v6[145];
      v9 = v7;
      do
      {
        v10 = *v8;
        if ( sub_42C970(*v8, a2, a3) )
        {
          v15 = sub_42CB30(v10, a4);
          if ( v14 < (double)v15 )
          {
            v14 = v15;
            v12 = v10;
          }
        }
        ++v8;
        --v9;
      }
      while ( v9 );
      v4 = v13;
    }
    v13 = ++v4;
  }
  while ( v4 < v5[15] );
  if ( !v12 )
    return -2147219198;
  sub_42D070(v17, v12, a2, a3);
  qmemcpy(a1, v17, 0x5Cu);
  return 0;
}
