_DWORD *__stdcall sub_451210(_DWORD *a1, unsigned int *a2)
{
  div_t v2; // rax
  unsigned int v3; // eax
  _DWORD *i; // edx
  int v5; // ecx
  unsigned int v6; // ecx
  _DWORD *result; // eax

  v2 = div((*a2 ^ 0xDEADBEEF) & 0x7FFFFFFF, 127773);
  v3 = (16807 * v2.rem - 2836 * v2.quot + (16807 * v2.rem - 2836 * v2.quot < 0 ? 0x7FFFFFFF : 0)) & dword_4D8C2C;
  if ( dword_4D8C30 <= v3 )
    v3 += -1 - ((unsigned int)dword_4D8C2C >> 1);
  for ( i = *(_DWORD **)(dword_4D8C1C + 8 * v3); ; i = (_DWORD *)*i )
  {
    if ( *(_DWORD *)(dword_4D8C1C + 8 * v3) == dword_4D8C10 )
      v5 = dword_4D8C10;
    else
      v5 = **(_DWORD **)(dword_4D8C1C + 8 * v3 + 4);
    if ( i == (_DWORD *)v5 )
    {
      *a1 = dword_4D8C10;
      return a1;
    }
    v6 = i[2];
    if ( v6 >= *a2 )
      break;
  }
  result = a1;
  if ( *a2 >= v6 )
    *a1 = i;
  else
    *a1 = dword_4D8C10;
  return result;
}
