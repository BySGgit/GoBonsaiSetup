int __cdecl sub_426E40(HMONITOR a1)
{
  _DWORD *v1; // ecx
  int *v2; // ebp
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // ebx
  int v8; // [esp+14h] [ebp-DCh]
  _DWORD *v9; // [esp+18h] [ebp-D8h]
  char v10[88]; // [esp+20h] [ebp-D0h] BYREF
  HMONITOR v11; // [esp+78h] [ebp-78h]
  struct tagMONITORINFO v12[2]; // [esp+80h] [ebp-70h] BYREF

  v9 = v1;
  v12[0].cbSize = 104;
  sub_438210(v12, a1);
  v2 = (int *)sub_42B3D0();
  v3 = 0;
  v8 = 0;
  if ( v2[15] <= 0 )
    return -2147467259;
  while ( 1 )
  {
    v4 = *(_DWORD *)(v2[14] + 4 * v3);
    v5 = 0;
    if ( *(int *)(v4 + 560) > 0 )
      break;
LABEL_6:
    v8 = ++v3;
    if ( v3 >= v2[15] )
      return -2147467259;
  }
  while ( 1 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(v4 + 556) + 4 * v5);
    (*(void (__stdcall **)(_DWORD, char *))(**(_DWORD **)(v6 + 8) + 28))(*(_DWORD *)(v6 + 8), v10);
    if ( a1 == v11 )
      break;
    if ( ++v5 >= *(_DWORD *)(v4 + 560) )
    {
      v3 = v8;
      goto LABEL_6;
    }
  }
  *v9 = *(_DWORD *)(v6 + 4);
  return 0;
}
