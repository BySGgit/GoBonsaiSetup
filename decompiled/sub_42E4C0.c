char __usercall sub_42E4C0@<al>(int a1@<esi>)
{
  int v1; // eax
  int v2; // ecx
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // ecx

  v1 = 0;
  if ( dword_4D8C6C > 0 )
  {
    while ( *(_DWORD *)(dword_4D8C68 + 4 * v1) != a1 )
    {
      if ( ++v1 >= dword_4D8C6C )
        goto LABEL_4;
    }
    return 1;
  }
LABEL_4:
  if ( sub_42DBC0(dword_4D8C6C + 1, (int)&dword_4D8C68) >= 0 )
  {
    *(_DWORD *)(dword_4D8C68 + 4 * dword_4D8C6C) = a1;
    v2 = dword_4D8C6C + 1;
    dword_4D8C6C = v2;
    if ( v2 > 1 )
    {
      v3 = *(_DWORD *)(dword_4D8C68 + 4 * v2 - 8);
      v4 = a1;
      if ( !a1 )
        v4 = v3;
      *(_DWORD *)(v3 + 740) = v4;
      if ( v4 )
        *(_DWORD *)(v4 + 744) = v3;
    }
    v5 = *(_DWORD *)dword_4D8C68;
    v6 = *(_DWORD *)(dword_4D8C68 + 4 * dword_4D8C6C - 4);
    if ( !*(_DWORD *)dword_4D8C68 )
      v5 = *(_DWORD *)(dword_4D8C68 + 4 * dword_4D8C6C - 4);
    *(_DWORD *)(v6 + 740) = v5;
    if ( v5 )
      *(_DWORD *)(v5 + 744) = v6;
    return 1;
  }
  return 0;
}
