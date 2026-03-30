__int16 __thiscall sub_444460(int this, __int16 a2)
{
  unsigned int *v3; // edx
  unsigned int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  __int16 result; // ax
  unsigned int v8; // edi
  _DWORD *v9; // ecx
  _WORD **v10; // esi
  _WORD *v11; // ecx
  unsigned int v12; // ebp
  unsigned int v13; // eax
  int v14; // edi
  void *v15; // ebx
  int *v16; // edx
  bool v17; // zf
  int *v18; // edx
  _DWORD *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  _DWORD *v23; // eax
  _WORD **v24; // esi
  _WORD *v25; // ecx
  unsigned int v26; // [esp+8h] [ebp-4h]

  if ( (*(_BYTE *)(this + 64) & 8) != 0 )
  {
    v3 = *(unsigned int **)(this + 36);
    v4 = *v3;
    if ( *v3 )
    {
      v5 = *(_DWORD *)(this + 60);
      if ( v4 < v5 )
      {
        v6 = v4 + 2 * **(_DWORD **)(this + 52) - v5;
        *v3 = v5;
        **(_DWORD **)(this + 52) = v6 >> 1;
      }
    }
  }
  result = a2;
  if ( a2 == -1 )
    return 0;
  v8 = **(_DWORD **)(this + 36);
  if ( v8 )
  {
    v9 = *(_DWORD **)(this + 52);
    if ( v8 < v8 + 2 * *v9 )
    {
      --*v9;
      v10 = *(_WORD ***)(this + 36);
      v11 = (*v10)++;
      *v11 = a2;
      return result;
    }
  }
  if ( (*(_BYTE *)(this + 64) & 2) != 0 )
    return -1;
  if ( v8 )
    v12 = (int)(v8 + 2 * **(_DWORD **)(this + 52) - **(_DWORD **)(this + 16)) >> 1;
  else
    v12 = 0;
  v13 = v12 >> 1;
  if ( v12 >> 1 >= 0x20 )
  {
    if ( !v13 )
      return -1;
  }
  else
  {
    v13 = 32;
  }
  do
  {
    if ( 0x7FFFFFFF - v13 >= v12 )
      break;
    v13 >>= 1;
  }
  while ( v13 );
  if ( !v13 )
    return -1;
  v26 = v13 + v12;
  v14 = (int)sub_403520(v13 + v12);
  v15 = **(void ***)(this + 16);
  if ( v12 )
  {
    memcpy_0((void *)v14, v15, 2 * v12);
    v19 = *(_DWORD **)(this + 36);
    *(_DWORD *)(this + 60) = v14 + 2 * ((*(_DWORD *)(this + 60) - (int)v15) >> 1);
    v20 = v14 + 2 * ((*v19 - (int)v15) >> 1);
    **(_DWORD **)(this + 20) = v14 + 2 * ((**(_DWORD **)(this + 20) - (int)v15) >> 1);
    **(_DWORD **)(this + 36) = v20;
    **(_DWORD **)(this + 52) = (int)(v14 + 2 * v26 - v20) >> 1;
    if ( (*(_BYTE *)(this + 64) & 4) != 0 )
    {
      **(_DWORD **)(this + 16) = v14;
      **(_DWORD **)(this + 32) = 0;
      **(_DWORD **)(this + 48) = v14 >> 1;
    }
    else
    {
      v21 = **(_DWORD **)(this + 36);
      v22 = v14 + 2 * ((**(_DWORD **)(this + 32) - (int)v15) >> 1);
      **(_DWORD **)(this + 16) = v14;
      **(_DWORD **)(this + 32) = v22;
      **(_DWORD **)(this + 48) = (v21 - v22 + 2) >> 1;
    }
  }
  else
  {
    v16 = *(int **)(this + 20);
    *(_DWORD *)(this + 60) = v14;
    *v16 = v14;
    **(_DWORD **)(this + 36) = v14;
    **(_DWORD **)(this + 52) = (int)(2 * v26) >> 1;
    v17 = (*(_BYTE *)(this + 64) & 4) == 0;
    **(_DWORD **)(this + 16) = v14;
    v18 = *(int **)(this + 32);
    if ( v17 )
    {
      *v18 = v14;
      **(_DWORD **)(this + 48) = 1;
    }
    else
    {
      *v18 = 0;
      **(_DWORD **)(this + 48) = v14 >> 1;
    }
  }
  if ( (*(_BYTE *)(this + 64) & 1) != 0 )
    operator delete(v15);
  v23 = *(_DWORD **)(this + 52);
  *(_DWORD *)(this + 64) |= 1u;
  --*v23;
  v24 = *(_WORD ***)(this + 36);
  v25 = (*v24)++;
  *v25 = a2;
  return a2;
}
