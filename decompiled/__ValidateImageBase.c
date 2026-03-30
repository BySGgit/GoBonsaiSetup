BOOL __cdecl _ValidateImageBase(int a1)
{
  int v2; // eax

  if ( *(_WORD *)a1 == 23117 && (v2 = a1 + *(_DWORD *)(a1 + 60), *(_DWORD *)v2 == 17744) )
    return *(_WORD *)(v2 + 24) == 267;
  else
    return 0;
}
