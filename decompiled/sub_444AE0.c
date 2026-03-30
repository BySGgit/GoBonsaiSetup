int __usercall sub_444AE0@<eax>(_DWORD *a1@<edi>, int a2@<esi>)
{
  if ( (_DWORD *)a2 != a1 )
  {
    if ( *(_DWORD *)(a2 + 20) >= 8u )
      operator delete(*(void **)a2);
    *(_DWORD *)(a2 + 20) = 7;
    *(_DWORD *)(a2 + 16) = 0;
    *(_WORD *)a2 = 0;
    if ( a1[5] >= 8u )
    {
      *(_DWORD *)a2 = *a1;
      *a1 = 0;
    }
    else
    {
      memcpy((void *)a2, a1, 2 * a1[4] + 2);
    }
    *(_DWORD *)(a2 + 16) = a1[4];
    *(_DWORD *)(a2 + 20) = a1[5];
    a1[5] = 7;
    a1[4] = 0;
    *(_WORD *)a1 = 0;
  }
  return a2;
}
