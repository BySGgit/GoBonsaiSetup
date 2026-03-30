int __userpurge sub_444B50@<eax>(int a1@<esi>, __int16 a2)
{
  int v2; // ecx
  unsigned int v3; // edi
  unsigned int v4; // eax
  _WORD *v5; // eax

  v2 = *(_DWORD *)(a1 + 16);
  if ( v2 == -1 || v2 == -2 )
    std::_Xlength_error("string too long");
  v3 = v2 + 1;
  if ( (unsigned int)(v2 + 1) > 0x7FFFFFFE )
    std::_Xlength_error("string too long");
  v4 = *(_DWORD *)(a1 + 20);
  if ( v4 < v3 )
  {
    sub_403580((const void **)a1, v2 + 1, (const void *)v2);
    if ( !v3 )
      return a1;
LABEL_7:
    if ( *(_DWORD *)(a1 + 20) < 8u )
      v5 = (_WORD *)a1;
    else
      v5 = *(_WORD **)a1;
    v5[*(_DWORD *)(a1 + 16)] = a2;
    *(_DWORD *)(a1 + 16) = v3;
    if ( *(_DWORD *)(a1 + 20) >= 8u )
    {
      *(_WORD *)(*(_DWORD *)a1 + 2 * v3) = 0;
      return a1;
    }
    *(_WORD *)(a1 + 2 * v3) = 0;
    return a1;
  }
  if ( v2 != -1 )
    goto LABEL_7;
  *(_DWORD *)(a1 + 16) = 0;
  if ( v4 < 8 )
  {
    *(_WORD *)a1 = 0;
    return a1;
  }
  else
  {
    **(_WORD **)a1 = 0;
    return a1;
  }
}
