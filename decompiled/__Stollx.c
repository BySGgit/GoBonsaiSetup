int __cdecl _Stollx(unsigned __int8 *a1, unsigned __int8 **a2, size_t MaxCount, _DWORD *a4)
{
  unsigned __int8 **v4; // edi
  unsigned __int8 *v5; // ebx
  int v6; // eax
  unsigned __int8 *v7; // esi
  unsigned __int64 v8; // rax

  v4 = a2;
  if ( !a2 )
    v4 = &a1;
  v5 = a1;
  v6 = *a1;
  v7 = a1;
  while ( isspace(v6) )
    v6 = *++v7;
  if ( *v7 == 45 || *v7 == 43 )
    HIBYTE(a2) = *v7++;
  else
    HIBYTE(a2) = 43;
  LODWORD(v8) = _Stoullx((int)v7, (int)v4, MaxCount, (int)a4);
  if ( v7 == *v4 )
    *v4 = v5;
  if ( (v5 != *v4 || !v8) && (HIBYTE(a2) != 43 || HIDWORD(v8) <= 0x7FFFFFFF) )
  {
    if ( HIBYTE(a2) != 45 )
      return v8;
    if ( v8 <= 0x8000000000000000uLL )
      return -(__int64)v8;
  }
  *_errno() = 34;
  if ( a4 )
    *a4 = 1;
  if ( HIBYTE(a2) == 45 )
    LODWORD(v8) = 0;
  else
    LODWORD(v8) = -1;
  return v8;
}
