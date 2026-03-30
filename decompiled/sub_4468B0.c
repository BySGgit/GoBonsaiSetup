int __usercall sub_4468B0@<eax>(int a1@<esi>)
{
  _WORD *v1; // eax

  *(_DWORD *)(a1 + 20) = 7;
  *(_DWORD *)(a1 + 16) = 0;
  *(_WORD *)a1 = 0;
  if ( !*(_DWORD *)(a1 + 20) )
    sub_403580((const void **)a1, 1u, *(const void **)(a1 + 16));
  if ( *(_DWORD *)(a1 + 20) < 8u )
    v1 = (_WORD *)a1;
  else
    v1 = *(_WORD **)a1;
  *v1 = 0;
  *(_DWORD *)(a1 + 16) = 1;
  if ( *(_DWORD *)(a1 + 20) < 8u )
  {
    *(_WORD *)(a1 + 2) = 0;
    return a1;
  }
  else
  {
    *(_WORD *)(*(_DWORD *)a1 + 2) = 0;
    return a1;
  }
}
