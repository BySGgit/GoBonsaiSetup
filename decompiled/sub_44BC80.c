char *__userpurge sub_44BC80@<eax>(char *a1@<eax>, char *Src, unsigned int a3)
{
  char *v3; // esi
  unsigned int v4; // ecx
  char *v5; // eax
  char *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  char *v10; // eax
  bool v11; // cf

  v3 = a1;
  if ( Src )
  {
    v4 = *((_DWORD *)a1 + 5);
    if ( v4 >= 8 )
      a1 = *(char **)a1;
    if ( Src >= a1 )
    {
      v5 = v4 < 8 ? v3 : *(char **)v3;
      if ( &v5[2 * *((_DWORD *)v3 + 4)] > Src )
      {
        if ( v4 < 8 )
          return sub_44A460(v3, v3, (Src - v3) >> 1, a3);
        else
          return sub_44A460(v3, v3, (int)&Src[-*(_DWORD *)v3] >> 1, a3);
      }
    }
  }
  v7 = (char *)*((_DWORD *)v3 + 4);
  if ( -1 - (int)v7 <= a3 )
    std::_Xlength_error("string too long");
  if ( !a3 )
    return v3;
  v8 = (unsigned int)&v7[a3];
  if ( (unsigned int)&v7[a3] > 0x7FFFFFFE )
    std::_Xlength_error("string too long");
  v9 = *((_DWORD *)v3 + 5);
  if ( v9 < v8 )
  {
    sub_403580((const void **)v3, (unsigned int)&v7[a3], v7);
    if ( v8 )
    {
LABEL_19:
      if ( *((_DWORD *)v3 + 5) < 8u )
        v10 = v3;
      else
        v10 = *(char **)v3;
      memcpy_0(&v10[2 * *((_DWORD *)v3 + 4)], Src, 2 * a3);
      v11 = *((_DWORD *)v3 + 5) < 8u;
      *((_DWORD *)v3 + 4) = v8;
      if ( !v11 )
      {
        *(_WORD *)(*(_DWORD *)v3 + 2 * v8) = 0;
        return v3;
      }
      *(_WORD *)&v3[2 * v8] = 0;
    }
    return v3;
  }
  if ( v8 )
    goto LABEL_19;
  *((_DWORD *)v3 + 4) = 0;
  if ( v9 < 8 )
    *(_WORD *)v3 = 0;
  else
    **(_WORD **)v3 = 0;
  return v3;
}
