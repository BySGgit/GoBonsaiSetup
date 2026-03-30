int __thiscall sub_4448F0(int this, int a2, __int64 a3, int a4, int a5, int a6, int a7, char a8)
{
  unsigned int *v8; // esi
  __int64 v9; // kr00_8
  unsigned int v10; // eax
  int v11; // esi
  int v12; // esi
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // esi
  int v17; // esi
  int v19; // [esp+Ch] [ebp-4h]
  unsigned int v20; // [esp+Ch] [ebp-4h]

  v8 = *(unsigned int **)(this + 36);
  v10 = *v8;
  v9 = a3 + a4;
  if ( *v8 && *(_DWORD *)(this + 60) < v10 )
    *(_DWORD *)(this + 60) = v10;
  if ( v9 != -1 )
  {
    if ( (a8 & 1) != 0 && (v19 = **(_DWORD **)(this + 32)) != 0 )
    {
      if ( v9 >= 0 )
      {
        v11 = **(_DWORD **)(this + 16);
        if ( v9 <= (*(_DWORD *)(this + 60) - v11) >> 1 )
        {
          v12 = v9 + ((v11 - v19) >> 1);
          **(_DWORD **)(this + 48) -= v12;
          **(_DWORD **)(this + 32) += 2 * v12;
          if ( (a8 & 2) != 0 )
          {
            v13 = **(_DWORD **)(this + 36);
            if ( v13 )
            {
              v14 = **(_DWORD **)(this + 32);
              v15 = v13 + 2 * **(_DWORD **)(this + 52);
              **(_DWORD **)(this + 36) = v14;
              **(_DWORD **)(this + 52) = (v15 - v14) >> 1;
            }
          }
          goto LABEL_18;
        }
      }
    }
    else if ( (a8 & 2) != 0 )
    {
      v20 = *v8;
      if ( *v8 )
      {
        if ( v9 >= 0 )
        {
          v16 = **(_DWORD **)(this + 16);
          if ( v9 <= (*(_DWORD *)(this + 60) - v16) >> 1 )
          {
            v17 = v9 + ((int)(v16 - v20) >> 1);
            **(_DWORD **)(this + 52) -= v17;
            **(_DWORD **)(this + 36) += 2 * v17;
            goto LABEL_18;
          }
        }
      }
    }
    v9 = -1;
  }
LABEL_18:
  *(_QWORD *)a2 = v9;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  return a2;
}
