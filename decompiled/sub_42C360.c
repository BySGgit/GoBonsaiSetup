void __stdcall sub_42C360(int a1)
{
  int v1; // eax

  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v1 + 8))(*(_DWORD *)(a1 + 8));
    *(_DWORD *)(a1 + 8) = 0;
  }
  if ( (*(int *)(a1 + 108) <= 0 || *(_DWORD *)(a1 + 104)) && *(_DWORD *)(a1 + 104) )
  {
    free(*(void **)(a1 + 104));
    *(_DWORD *)(a1 + 104) = 0;
  }
  *(_DWORD *)(a1 + 112) = 0;
  *(_DWORD *)(a1 + 108) = 0;
  if ( *(_DWORD *)(a1 + 104) )
  {
    free(*(void **)(a1 + 104));
    *(_DWORD *)(a1 + 104) = 0;
  }
  *(_DWORD *)(a1 + 112) = 0;
  *(_DWORD *)(a1 + 108) = 0;
}
