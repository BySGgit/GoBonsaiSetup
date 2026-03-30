int __thiscall sub_402CD0(_DWORD *this, int a2, unsigned int *a3, _DWORD **a4)
{
  div_t v5; // rax
  unsigned int v6; // esi
  int v7; // eax
  _DWORD *v8; // edx
  _DWORD *v9; // ebx
  _DWORD *v10; // ecx
  int v11; // eax
  unsigned int v12; // eax
  _DWORD **v13; // eax
  int v14; // eax
  _DWORD *v15; // edx
  _DWORD *v16; // eax
  _DWORD *v18; // edx
  _DWORD *v19; // ecx
  _DWORD *v20; // [esp+Ch] [ebp-4h] BYREF

  v5 = div((*a3 ^ 0xDEADBEEF) & 0x7FFFFFFF, 127773);
  v6 = (16807 * v5.rem - 2836 * v5.quot + (16807 * v5.rem - 2836 * v5.quot < 0 ? 0x7FFFFFFF : 0)) & *(this + 8);
  if ( *(this + 9) <= v6 )
    v6 += -1 - (*(this + 8) >> 1);
  v7 = *(this + 4);
  v8 = *(_DWORD **)(v7 + 8 * v6);
  v9 = (_DWORD *)*(this + 1);
  v10 = this + 1;
  v11 = v7 + 8 * v6;
  v20 = this + 1;
  if ( v9 != v8 )
  {
    v9 = **(_DWORD ***)(v11 + 4);
    if ( v9 != v8 )
    {
      v12 = *a3;
      while ( 1 )
      {
        v9 = (_DWORD *)v9[1];
        if ( v9[2] <= v12 )
          break;
        if ( v9 == v8 )
          goto LABEL_8;
      }
      if ( v9[2] >= v12 )
      {
        sub_44EDE0(&v20, (int)v10, a4);
        *(_DWORD *)a2 = v9;
        *(_BYTE *)(a2 + 4) = 0;
        return a2;
      }
      v9 = (_DWORD *)*v9;
    }
  }
LABEL_8:
  v13 = a4;
  if ( v9 != *a4 )
  {
    sub_402EE0((int)v10, (int)(this + 1), (int)v9, (int)a4, (int)*a4);
    v13 = a4;
    v10 = v20;
  }
  v20 = v13;
  v14 = *(this + 4);
  v15 = *(_DWORD **)(v14 + 8 * v6);
  v16 = (_DWORD *)(v14 + 8 * v6);
  if ( v15 == (_DWORD *)*v10 )
  {
    *v16 = a4;
    *(_DWORD *)(*(this + 4) + 8 * v6 + 4) = v20;
  }
  else if ( v15 == v9 )
  {
    *v16 = a4;
  }
  else
  {
    v18 = (_DWORD *)v16[1];
    v19 = (_DWORD *)*v18;
    v16[1] = *v18;
    if ( v19 != v20 )
      *(_DWORD *)(*(this + 4) + 8 * v6 + 4) = *(_DWORD *)(*(_DWORD *)(*(this + 4) + 8 * v6 + 4) + 4);
  }
  sub_402E10((int)this);
  *(_DWORD *)a2 = a4;
  *(_BYTE *)(a2 + 4) = 1;
  return a2;
}
