int __fastcall sub_402EE0(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // ecx

  if ( a2 != a1 )
  {
    v5 = *(_DWORD *)(a2 + 4);
    if ( v5 == 536870910 )
      std::_Xlength_error("list<T> too long");
    *(_DWORD *)(a2 + 4) = v5 + 1;
    --*(_DWORD *)(a1 + 4);
  }
  **(_DWORD **)(a4 + 4) = a5;
  **(_DWORD **)(a5 + 4) = a3;
  **(_DWORD **)(a3 + 4) = a4;
  v6 = *(_DWORD *)(a3 + 4);
  *(_DWORD *)(a3 + 4) = *(_DWORD *)(a5 + 4);
  *(_DWORD *)(a5 + 4) = *(_DWORD *)(a4 + 4);
  *(_DWORD *)(a4 + 4) = v6;
  return a5;
}
