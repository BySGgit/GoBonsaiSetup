int __userpurge sub_43DAA0@<eax>(int a1@<eax>, int a2)
{
  int v3; // ecx
  int v4; // eax
  int *v5; // esi
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // esi
  _DWORD *v10; // ecx

  v3 = *(_DWORD *)(a1 + 628);
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_6:
    v6 = 0;
  }
  else
  {
    v5 = *(int **)(a1 + 624);
    while ( *(_DWORD *)(*v5 + 44) != 5 || *(_DWORD *)(*v5 + 48) != 3 )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        goto LABEL_6;
    }
    v6 = *v5;
  }
  (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v6 + 84))(v6, a2, 1, 0);
  v7 = *(_DWORD *)(a1 + 628);
  v8 = 0;
  if ( v7 <= 0 )
  {
LABEL_12:
    v10 = 0;
  }
  else
  {
    v9 = *(_DWORD *)(a1 + 624);
    while ( 1 )
    {
      v10 = *(_DWORD **)v9;
      if ( *(_DWORD *)(*(_DWORD *)v9 + 44) == 6 && v10[12] == 3 )
        break;
      ++v8;
      v9 += 4;
      if ( v8 >= v7 )
        goto LABEL_12;
    }
  }
  return (*(int (__thiscall **)(_DWORD *, bool, int, _DWORD))(*v10 + 84))(v10, (_BYTE)a2 == 0, 1, 0);
}
