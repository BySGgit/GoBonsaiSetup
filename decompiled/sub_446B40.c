void __usercall sub_446B40(int a1@<eax>, int a2@<edi>)
{
  int i; // esi

  for ( i = a1; i != a2; i += 28 )
  {
    if ( *(_DWORD *)(i + 20) >= 8u )
      operator delete(*(void **)i);
    *(_DWORD *)(i + 20) = 7;
    *(_DWORD *)(i + 16) = 0;
    *(_WORD *)i = 0;
  }
}
