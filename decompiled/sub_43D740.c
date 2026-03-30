int __usercall sub_43D740@<eax>(int a1@<eax>)
{
  int v1; // esi
  int v2; // ecx
  int *v3; // edx
  int v4; // eax

  v1 = *(_DWORD *)(a1 + 628);
  v2 = 0;
  if ( v1 <= 0 )
  {
LABEL_6:
    v4 = 0;
  }
  else
  {
    v3 = *(int **)(a1 + 624);
    while ( 1 )
    {
      v4 = *v3;
      if ( *(_DWORD *)(*v3 + 44) == 42 && *(_DWORD *)(v4 + 48) == 2 )
        break;
      ++v2;
      ++v3;
      if ( v2 >= v1 )
        goto LABEL_6;
    }
  }
  if ( *(_BYTE *)(v4 + 604) )
    dword_4D7E3C |= 2u;
  else
    dword_4D7E3C &= ~2u;
  return 0;
}
