void __stdcall sub_440650(int a1, int a2)
{
  _WORD **v2; // edx
  _DWORD *v3; // edi
  unsigned int v4; // ebx
  _DWORD *v5; // ecx
  _WORD *v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // edx
  int v9; // eax

  v2 = (_WORD **)a2;
  v3 = **(_DWORD ***)a1;
  if ( v3 != *(_DWORD **)a1 )
  {
    v4 = *(_DWORD *)(a2 + 16);
    while ( 1 )
    {
      v5 = (_DWORD *)v3[2];
      if ( *(_DWORD *)(a2 + 20) < 8u )
        v6 = v2;
      else
        v6 = *v2;
      v7 = v5[4];
      v8 = v7;
      if ( v7 >= v4 )
        v8 = *(_DWORD *)(a2 + 16);
      if ( v5[5] >= 8u )
        v5 = (_DWORD *)*v5;
      if ( v8 )
      {
        while ( *(_WORD *)v5 == *v6 )
        {
          v5 = (_DWORD *)((char *)v5 + 2);
          ++v6;
          if ( !--v8 )
            goto LABEL_16;
        }
        v9 = *(_WORD *)v5 < *v6 ? -1 : 1;
      }
      else
      {
LABEL_16:
        if ( v7 < v4 )
          goto LABEL_19;
        v9 = v7 != v4;
      }
      if ( !v9 )
      {
        if ( v3 != *(_DWORD **)a1 )
        {
          *(_DWORD *)v3[1] = *v3;
          *(_DWORD *)(*v3 + 4) = v3[1];
          operator delete(v3);
          --*(_DWORD *)(a1 + 4);
        }
        return;
      }
LABEL_19:
      v3 = (_DWORD *)*v3;
      if ( v3 == *(_DWORD **)a1 )
        return;
      v2 = (_WORD **)a2;
    }
  }
}
