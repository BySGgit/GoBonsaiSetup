_DWORD *__userpurge sub_451040@<eax>(_DWORD *a1@<edi>, int *a2)
{
  div_t v2; // rax
  unsigned int v3; // eax
  int *v4; // ecx
  int v5; // esi

  v2 = div((a2[2] ^ 0xDEADBEEF) & 0x7FFFFFFF, 127773);
  v3 = (16807 * v2.rem - 2836 * v2.quot + (16807 * v2.rem - 2836 * v2.quot < 0 ? 0x7FFFFFFF : 0)) & dword_4D8C2C;
  if ( dword_4D8C30 <= v3 )
    v3 += -1 - ((unsigned int)dword_4D8C2C >> 1);
  v4 = a2;
  if ( *(int **)(dword_4D8C1C + 8 * v3 + 4) == a2 )
  {
    if ( *(int **)(dword_4D8C1C + 8 * v3) == a2 )
    {
      *(_DWORD *)(dword_4D8C1C + 8 * v3) = dword_4D8C10;
      *(_DWORD *)(dword_4D8C1C + 8 * v3 + 4) = dword_4D8C10;
    }
    else
    {
      *(_DWORD *)(dword_4D8C1C + 8 * v3 + 4) = a2[1];
    }
  }
  else
  {
    if ( *(int **)(dword_4D8C1C + 8 * v3) != a2 )
      goto LABEL_10;
    *(_DWORD *)(dword_4D8C1C + 8 * v3) = *a2;
  }
  v4 = a2;
LABEL_10:
  v5 = *v4;
  if ( v4 != (int *)dword_4D8C10 )
  {
    *(_DWORD *)v4[1] = v5;
    *(_DWORD *)(*v4 + 4) = v4[1];
    operator delete(v4);
    --dword_4D8C14;
  }
  *a1 = v5;
  return a1;
}
