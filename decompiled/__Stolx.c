size_t __cdecl _Stolx(char *a1, char **a2, size_t MaxCount, _DWORD *a4)
{
  char **v4; // edi
  char *v5; // ebx
  int v6; // eax
  char *v7; // esi
  size_t result; // eax

  v4 = a2;
  if ( !a2 )
    v4 = &a1;
  v5 = a1;
  v6 = (unsigned __int8)*a1;
  v7 = a1;
  while ( isspace(v6) )
    v6 = (unsigned __int8)*++v7;
  if ( *v7 == 45 || *v7 == 43 )
    HIBYTE(a2) = *v7++;
  else
    HIBYTE(a2) = 43;
  result = _Stoulx(v7, v4, MaxCount, a4);
  if ( v7 == *v4 )
    *v4 = v5;
  if ( v5 == *v4 && result || HIBYTE(a2) == 43 && result > 0x7FFFFFFF )
    goto LABEL_18;
  if ( HIBYTE(a2) != 45 )
    return result;
  if ( result <= 0x80000000 )
    return -result;
LABEL_18:
  *_errno() = 34;
  if ( a4 )
    *a4 = 1;
  return (HIBYTE(a2) == 45) + 0x7FFFFFFF;
}
