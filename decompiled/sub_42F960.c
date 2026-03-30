int __stdcall sub_42F960(int a1, int a2, int a3)
{
  int v3; // edi
  int v4; // esi

  v3 = 0;
  if ( *(int *)(a1 + 612) <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)(a1 + 608) + 4 * v3);
    if ( v4 )
    {
      if ( (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v4 + 52))(v4, a2, a3)
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 60))(v4)
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 68))(v4) )
      {
        break;
      }
    }
    if ( ++v3 >= *(_DWORD *)(a1 + 612) )
      return 0;
  }
  return v4;
}
