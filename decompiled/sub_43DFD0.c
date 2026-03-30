int __usercall sub_43DFD0@<eax>(int a1@<eax>)
{
  int v1; // esi
  int v2; // ecx
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // ecx

  v1 = *(_DWORD *)(a1 + 628);
  v2 = 0;
  if ( v1 <= 0 )
  {
LABEL_6:
    v4 = 0;
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 624);
    while ( 1 )
    {
      v4 = *(_DWORD **)v3;
      if ( *(_DWORD *)(*(_DWORD *)v3 + 44) == 11 && v4[12] == 4 )
        break;
      ++v2;
      v3 += 4;
      if ( v2 >= v1 )
        goto LABEL_6;
    }
  }
  v5 = v4[151];
  if ( v5 >= 0 )
    return *(_DWORD *)(*(_DWORD *)(v4[218] + 4 * v5) + 512);
  else
    return 0;
}
