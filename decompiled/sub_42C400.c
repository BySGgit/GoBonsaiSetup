void __stdcall sub_42C400(int a1)
{
  int v1; // ebx
  int v2; // edi
  int v3; // eax
  int v4; // edi
  int v5; // ebx
  int v6; // edi
  int v7; // eax

  v1 = 0;
  if ( *(int *)(a1 + 560) <= 0 )
    goto LABEL_52;
  do
  {
    v2 = *(_DWORD *)(*(_DWORD *)(a1 + 556) + 4 * v1);
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 8);
      if ( v3 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*(_DWORD *)(v2 + 8));
        *(_DWORD *)(v2 + 8) = 0;
      }
      if ( *(_DWORD *)(v2 + 104) )
      {
        free(*(void **)(v2 + 104));
        *(_DWORD *)(v2 + 104) = 0;
      }
      *(_DWORD *)(v2 + 112) = 0;
      *(_DWORD *)(v2 + 108) = 0;
      if ( *(_DWORD *)(v2 + 104) )
      {
        free(*(void **)(v2 + 104));
        *(_DWORD *)(v2 + 104) = 0;
      }
      *(_DWORD *)(v2 + 112) = 0;
      *(_DWORD *)(v2 + 108) = 0;
      operator delete((void *)v2);
    }
    ++v1;
  }
  while ( v1 < *(_DWORD *)(a1 + 560) );
  if ( *(int *)(a1 + 560) <= 0 || *(_DWORD *)(a1 + 556) )
  {
LABEL_52:
    if ( *(_DWORD *)(a1 + 556) )
    {
      free(*(void **)(a1 + 556));
      *(_DWORD *)(a1 + 556) = 0;
    }
  }
  *(_DWORD *)(a1 + 564) = 0;
  *(_DWORD *)(a1 + 560) = 0;
  v4 = 0;
  if ( *(int *)(a1 + 572) <= 0 )
    goto LABEL_53;
  do
  {
    if ( *(_DWORD *)(*(_DWORD *)(a1 + 568) + 4 * v4) )
      operator delete(*(void **)(*(_DWORD *)(a1 + 568) + 4 * v4));
    ++v4;
  }
  while ( v4 < *(_DWORD *)(a1 + 572) );
  if ( *(int *)(a1 + 572) <= 0 || *(_DWORD *)(a1 + 568) )
  {
LABEL_53:
    if ( *(_DWORD *)(a1 + 568) )
    {
      free(*(void **)(a1 + 568));
      *(_DWORD *)(a1 + 568) = 0;
    }
  }
  *(_DWORD *)(a1 + 576) = 0;
  *(_DWORD *)(a1 + 572) = 0;
  v5 = 0;
  if ( *(int *)(a1 + 584) <= 0 )
    goto LABEL_54;
  do
  {
    v6 = *(_DWORD *)(*(_DWORD *)(a1 + 580) + 4 * v5);
    if ( v6 )
    {
      if ( *(_DWORD *)(v6 + 32) )
      {
        free(*(void **)(v6 + 32));
        *(_DWORD *)(v6 + 32) = 0;
      }
      *(_DWORD *)(v6 + 40) = 0;
      *(_DWORD *)(v6 + 36) = 0;
      if ( *(_DWORD *)(v6 + 20) )
      {
        free(*(void **)(v6 + 20));
        *(_DWORD *)(v6 + 20) = 0;
      }
      *(_DWORD *)(v6 + 28) = 0;
      *(_DWORD *)(v6 + 24) = 0;
      operator delete((void *)v6);
    }
    ++v5;
  }
  while ( v5 < *(_DWORD *)(a1 + 584) );
  if ( *(int *)(a1 + 584) <= 0 || *(_DWORD *)(a1 + 580) )
  {
LABEL_54:
    if ( *(_DWORD *)(a1 + 580) )
    {
      free(*(void **)(a1 + 580));
      *(_DWORD *)(a1 + 580) = 0;
    }
  }
  *(_DWORD *)(a1 + 588) = 0;
  *(_DWORD *)(a1 + 584) = 0;
  v7 = *(_DWORD *)(a1 + 552);
  if ( v7 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 8))(*(_DWORD *)(a1 + 552));
    *(_DWORD *)(a1 + 552) = 0;
  }
  if ( (*(int *)(a1 + 584) <= 0 || *(_DWORD *)(a1 + 580)) && *(_DWORD *)(a1 + 580) )
  {
    free(*(void **)(a1 + 580));
    *(_DWORD *)(a1 + 580) = 0;
  }
  *(_DWORD *)(a1 + 588) = 0;
  *(_DWORD *)(a1 + 584) = 0;
  if ( (*(int *)(a1 + 572) <= 0 || *(_DWORD *)(a1 + 568)) && *(_DWORD *)(a1 + 568) )
  {
    free(*(void **)(a1 + 568));
    *(_DWORD *)(a1 + 568) = 0;
  }
  *(_DWORD *)(a1 + 576) = 0;
  *(_DWORD *)(a1 + 572) = 0;
  if ( *(int *)(a1 + 560) <= 0 || *(_DWORD *)(a1 + 556) )
  {
    if ( *(_DWORD *)(a1 + 556) )
    {
      free(*(void **)(a1 + 556));
      *(_DWORD *)(a1 + 556) = 0;
    }
  }
  *(_DWORD *)(a1 + 564) = 0;
  *(_DWORD *)(a1 + 560) = 0;
}
