int __userpurge sub_44B900@<eax>(unsigned int a1@<eax>, int a2@<edx>, int a3@<esi>, int a4, int a5, int a6)
{
  int v6; // ecx
  int v7; // ecx

  if ( a2 != a3 )
  {
    v6 = *(_DWORD *)(a2 + 4);
    if ( 1073741822 - v6 < a1 )
      std::_Xlength_error("list<T> too long");
    *(_DWORD *)(a2 + 4) = a1 + v6;
    *(_DWORD *)(a3 + 4) -= a1;
  }
  **(_DWORD **)(a5 + 4) = a6;
  **(_DWORD **)(a6 + 4) = a4;
  **(_DWORD **)(a4 + 4) = a5;
  v7 = *(_DWORD *)(a4 + 4);
  *(_DWORD *)(a4 + 4) = *(_DWORD *)(a6 + 4);
  *(_DWORD *)(a6 + 4) = *(_DWORD *)(a5 + 4);
  *(_DWORD *)(a5 + 4) = v7;
  return a6;
}
