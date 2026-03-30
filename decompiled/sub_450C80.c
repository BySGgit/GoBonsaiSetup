void __usercall sub_450C80(_DWORD *a1@<edx>, int a2@<esi>)
{
  void **v2; // ecx
  void **v3; // eax

  v2 = *(void ***)(a2 + 168);
  v3 = (void **)*v2;
  if ( *v2 != v2 )
  {
    while ( v3[2] != a1 )
    {
      v3 = (void **)*v3;
      if ( v3 == v2 )
        return;
    }
    a1[45] = 0;
    if ( v3 != *(void ***)(a2 + 168) )
    {
      *(_DWORD *)v3[1] = *v3;
      *((_DWORD *)*v3 + 1) = v3[1];
      operator delete(v3);
      --*(_DWORD *)(a2 + 172);
    }
  }
}
