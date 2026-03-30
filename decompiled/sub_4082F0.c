void __stdcall sub_4082F0(int a1)
{
  unsigned int v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // ecx
  unsigned int v5; // ebp
  int v6; // esi
  char *v7; // eax
  const void *v8; // ecx
  char *v9; // edx
  char *v10; // edi
  unsigned int v11; // ecx
  size_t v12; // esi
  char *v13; // eax
  char *v14; // [esp+8h] [ebp-Ch]
  size_t v15; // [esp+10h] [ebp-4h]
  int v16; // [esp+18h] [ebp+4h]

  v2 = *(_DWORD *)(a1 + 8);
  v3 = 1;
  v16 = 1;
  if ( v2 == 0xFFFFFFF )
    std::_Xlength_error("deque<T> too long");
  v4 = v2 >> 1;
  if ( v2 >> 1 >= 8 )
  {
    if ( v4 <= 1 )
      goto LABEL_8;
  }
  else
  {
    v4 = 8;
  }
  if ( v2 <= 0xFFFFFFF - v4 )
  {
    v16 = v4;
    v3 = v4;
  }
LABEL_8:
  v5 = *(_DWORD *)(a1 + 12) >> 2;
  v6 = 4 * v5;
  v14 = (char *)sub_4031B0(v2 + v3);
  v15 = 4 * ((int)(4 * *(_DWORD *)(a1 + 8) - 4 * v5) >> 2);
  v7 = (char *)memcpy(&v14[4 * v5], (const void *)(4 * v5 + *(_DWORD *)(a1 + 4)), v15) + v15;
  v8 = *(const void **)(a1 + 4);
  if ( v5 > v3 )
  {
    memcpy(v7, v8, 4 * ((int)(4 * v3) >> 2));
    v12 = 4 * ((int)(v6 - 4 * v3) >> 2);
    v13 = (char *)memcpy(v14, (const void *)(*(_DWORD *)(a1 + 4) + 4 * v3), v12);
    v11 = v3;
    v10 = &v13[v12];
    goto LABEL_15;
  }
  v9 = (char *)memcpy(v7, v8, 4 * (v6 >> 2)) + 4 * (v6 >> 2);
  if ( v3 != v5 )
  {
    memset(v9, 0, 4 * (v3 - v5));
    v3 = v16;
  }
  if ( v5 )
  {
    v10 = v14;
    v11 = v5;
LABEL_15:
    memset(v10, 0, 4 * v11);
    v3 = v16;
  }
  if ( *(_DWORD *)(a1 + 4) )
    operator delete(*(void **)(a1 + 4));
  *(_DWORD *)(a1 + 8) += v3;
  *(_DWORD *)(a1 + 4) = v14;
}
