void __usercall sub_403410(int a1@<esi>)
{
  if ( *(_DWORD *)(a1 + 20) >= 8u )
    operator delete(*(void **)a1);
  *(_DWORD *)(a1 + 20) = 7;
  *(_DWORD *)(a1 + 16) = 0;
  *(_WORD *)a1 = 0;
}
