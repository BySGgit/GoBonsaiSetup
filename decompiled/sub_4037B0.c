int __userpurge sub_4037B0@<eax>(unsigned int a1@<eax>, int a2@<ecx>, _DWORD *a3, unsigned int a4)
{
  unsigned int v4; // edi
  unsigned int v6; // edi
  unsigned int v8; // eax
  _DWORD *v9; // ecx
  void *v10; // eax
  int v11; // ebx
  bool v12; // cf

  v4 = a3[4];
  if ( v4 < a4 )
    std::_Xout_of_range("invalid string position");
  v6 = v4 - a4;
  if ( a1 < v6 )
    v6 = a1;
  if ( (_DWORD *)a2 == a3 )
  {
    sub_403440(0xFFFFFFFF, v6 + a4, (_DWORD *)a2);
    sub_403440(a4, 0, (_DWORD *)a2);
    return a2;
  }
  if ( v6 > 0x7FFFFFFE )
    std::_Xlength_error("string too long");
  v8 = *(_DWORD *)(a2 + 20);
  if ( v8 < v6 )
  {
    sub_403580((const void **)a2, v6, *(const void **)(a2 + 16));
    if ( !v6 )
      return a2;
LABEL_11:
    if ( a3[5] < 8u )
      v9 = a3;
    else
      v9 = (_DWORD *)*a3;
    if ( *(_DWORD *)(a2 + 20) < 8u )
      v10 = (void *)a2;
    else
      v10 = *(void **)a2;
    v11 = 2 * v6;
    memcpy_0(v10, (char *)v9 + 2 * a4, 2 * v6);
    v12 = *(_DWORD *)(a2 + 20) < 8u;
    *(_DWORD *)(a2 + 16) = v6;
    if ( !v12 )
    {
      *(_WORD *)(v11 + *(_DWORD *)a2) = 0;
      return a2;
    }
    *(_WORD *)(v11 + a2) = 0;
    return a2;
  }
  if ( v6 )
    goto LABEL_11;
  *(_DWORD *)(a2 + 16) = 0;
  if ( v8 < 8 )
    *(_WORD *)a2 = 0;
  else
    **(_WORD **)a2 = 0;
  return a2;
}
