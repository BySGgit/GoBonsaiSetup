void __usercall sub_402E10(int a1@<edi>)
{
  double v1; // st7
  unsigned int v2; // esi
  int i; // eax
  int v4; // ebx
  int v5; // ecx
  _DWORD *v6; // eax
  void *v7; // ebx
  void *v8; // esi
  int v9[3]; // [esp+10h] [ebp-Ch] BYREF

  v1 = *(float *)(a1 + 40);
  v2 = *(_DWORD *)(a1 + 36);
  *(float *)v9 = (double)*(unsigned int *)(a1 + 8) / (double)v2;
  if ( *(float *)v9 > v1 )
  {
    for ( i = 0; i < 3; ++i )
    {
      if ( v2 >= 0x1FFFFFFF )
        break;
      v2 *= 2;
    }
    v4 = *(_DWORD *)(a1 + 16);
    v5 = *(_DWORD *)(a1 + 20);
    v9[0] = *(_DWORD *)(a1 + 4);
    if ( v4 != v5 )
      *(_DWORD *)(a1 + 20) = v4;
    sub_402F60(2 * v2, (int *)(a1 + 16), *(char **)(a1 + 16), (void **)v9);
    v6 = *(_DWORD **)(a1 + 4);
    *(_DWORD *)(a1 + 32) = v2 - 1;
    *(_DWORD *)(a1 + 36) = v2;
    if ( (_DWORD *)*v6 != v6 )
    {
      v7 = (void *)v6[1];
      do
      {
        v8 = **(void ***)(a1 + 4);
        sub_402CD0((int)v9, (int)v8 + 8, v8);
      }
      while ( v8 != v7 );
    }
  }
}
