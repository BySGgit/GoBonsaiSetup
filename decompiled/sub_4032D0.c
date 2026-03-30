int __userpurge sub_4032D0@<eax>(const void *a1@<eax>, int a2@<esi>, unsigned int a3)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // eax
  unsigned int v8; // eax
  void *v9; // eax
  int v10; // ebx
  bool v11; // cf

  if ( a1 )
  {
    v4 = *(_DWORD *)(a2 + 20);
    v5 = v4 < 8 ? a2 : *(_DWORD *)a2;
    if ( (unsigned int)a1 >= v5 )
    {
      v6 = v4 < 8 ? a2 : *(_DWORD *)a2;
      if ( v6 + 2 * *(_DWORD *)(a2 + 16) > (unsigned int)a1 )
      {
        if ( v4 < 8 )
          return sub_4037B0(a3, a2, (_DWORD *)a2, ((int)a1 - a2) >> 1);
        else
          return sub_4037B0(a3, a2, (_DWORD *)a2, ((int)a1 - *(_DWORD *)a2) >> 1);
      }
    }
  }
  if ( a3 > 0x7FFFFFFE )
    std::_Xlength_error("string too long");
  v8 = *(_DWORD *)(a2 + 20);
  if ( v8 < a3 )
  {
    sub_403580((const void **)a2, a3, *(const void **)(a2 + 16));
    if ( !a3 )
      return a2;
LABEL_17:
    if ( *(_DWORD *)(a2 + 20) < 8u )
      v9 = (void *)a2;
    else
      v9 = *(void **)a2;
    v10 = 2 * a3;
    memcpy_0(v9, a1, 2 * a3);
    v11 = *(_DWORD *)(a2 + 20) < 8u;
    *(_DWORD *)(a2 + 16) = a3;
    if ( !v11 )
    {
      *(_WORD *)(v10 + *(_DWORD *)a2) = 0;
      return a2;
    }
    *(_WORD *)(v10 + a2) = 0;
    return a2;
  }
  if ( a3 )
    goto LABEL_17;
  *(_DWORD *)(a2 + 16) = 0;
  if ( v8 < 8 )
    *(_WORD *)a2 = 0;
  else
    **(_WORD **)a2 = 0;
  return a2;
}
