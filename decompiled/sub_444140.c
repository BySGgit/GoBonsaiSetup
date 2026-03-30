void __stdcall sub_444140(int a1)
{
  void **v1; // esi
  void **v2; // edi

  v1 = **(void ****)a1;
  **(_DWORD **)a1 = *(_DWORD *)a1;
  *(_DWORD *)(*(_DWORD *)a1 + 4) = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 4) = 0;
  if ( v1 != *(void ***)a1 )
  {
    do
    {
      v2 = (void **)*v1;
      if ( (unsigned int)v1[7] >= 8 )
        operator delete(v1[2]);
      v1[7] = (void *)7;
      v1[6] = 0;
      *((_WORD *)v1 + 4) = 0;
      operator delete(v1);
      v1 = v2;
    }
    while ( v2 != *(void ***)a1 );
  }
}
