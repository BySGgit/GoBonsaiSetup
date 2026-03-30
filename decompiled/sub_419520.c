void __stdcall sub_419520(int a1)
{
  int v1; // esi

  v1 = *(_DWORD *)(a1 + 1528);
  if ( v1 )
  {
    if ( *(int *)(v1 + 4) <= 0 || *(_DWORD *)v1 )
    {
      if ( *(_DWORD *)v1 )
      {
        free(*(void **)v1);
        *(_DWORD *)v1 = 0;
      }
    }
    *(_DWORD *)(v1 + 8) = 0;
    *(_DWORD *)(v1 + 4) = 0;
    operator delete((void *)v1);
    *(_DWORD *)(a1 + 1528) = 0;
  }
  sub_428190(0);
  DeleteCriticalSection(&CriticalSection);
}
