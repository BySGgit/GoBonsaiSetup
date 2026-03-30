char *__userpurge sub_44A460@<eax>(char *a1@<esi>, _DWORD *a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // eax
  char *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  _DWORD *v10; // ecx
  char *v11; // eax
  bool v13; // cf

  v4 = a2[4];
  v5 = a4;
  if ( v4 < a3 )
    std::_Xout_of_range("invalid string position");
  v6 = v4 - a3;
  if ( v6 < a4 )
    v5 = v6;
  v7 = (char *)*((_DWORD *)a1 + 4);
  if ( -1 - (int)v7 <= v5 )
    std::_Xlength_error("string too long");
  if ( !v5 )
    return a1;
  v8 = (unsigned int)&v7[v5];
  if ( (unsigned int)&v7[v5] > 0x7FFFFFFE )
    std::_Xlength_error("string too long");
  v9 = *((_DWORD *)a1 + 5);
  if ( v9 < v8 )
  {
    sub_403580((const void **)a1, (unsigned int)&v7[v5], v7);
    if ( v8 )
    {
LABEL_12:
      v10 = a2;
      if ( a2[5] >= 8u )
        v10 = (_DWORD *)*a2;
      if ( *((_DWORD *)a1 + 5) < 8u )
        v11 = a1;
      else
        v11 = *(char **)a1;
      memcpy_0(&v11[2 * *((_DWORD *)a1 + 4)], (char *)v10 + 2 * a3, 2 * v5);
      v13 = *((_DWORD *)a1 + 5) < 8u;
      *((_DWORD *)a1 + 4) = v8;
      if ( !v13 )
      {
        *(_WORD *)(*(_DWORD *)a1 + 2 * v8) = 0;
        return a1;
      }
      *(_WORD *)&a1[2 * v8] = 0;
    }
    return a1;
  }
  if ( v8 )
    goto LABEL_12;
  *((_DWORD *)a1 + 4) = 0;
  if ( v9 < 8 )
    *(_WORD *)a1 = 0;
  else
    **(_WORD **)a1 = 0;
  return a1;
}
