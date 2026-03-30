int __userpurge sub_44A3B0@<eax>(unsigned int a1@<edi>, int a2@<esi>, char a3)
{
  unsigned int v3; // eax
  void *v5; // eax
  bool v6; // cf

  if ( a1 == -1 )
    std::_Xlength_error("string too long");
  v3 = *(_DWORD *)(a2 + 20);
  if ( v3 < a1 )
  {
    sub_44C9E0(a2, a1, *(_DWORD *)(a2 + 16));
    if ( !a1 )
      return a2;
LABEL_5:
    if ( a1 == 1 )
    {
      if ( *(_DWORD *)(a2 + 20) < 0x10u )
        *(_BYTE *)a2 = a3;
      else
        **(_BYTE **)a2 = a3;
    }
    else
    {
      if ( *(_DWORD *)(a2 + 20) < 0x10u )
        v5 = (void *)a2;
      else
        v5 = *(void **)a2;
      memset(v5, a3, a1);
    }
    v6 = *(_DWORD *)(a2 + 20) < 0x10u;
    *(_DWORD *)(a2 + 16) = a1;
    if ( !v6 )
    {
      *(_BYTE *)(*(_DWORD *)a2 + a1) = 0;
      return a2;
    }
    *(_BYTE *)(a2 + a1) = 0;
    return a2;
  }
  if ( a1 )
    goto LABEL_5;
  *(_DWORD *)(a2 + 16) = 0;
  if ( v3 < 0x10 )
    *(_BYTE *)a2 = 0;
  else
    **(_BYTE **)a2 = 0;
  return a2;
}
