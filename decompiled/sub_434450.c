int __thiscall sub_434450(_DWORD *this, const unsigned __int16 *a2)
{
  int result; // eax
  int v3; // ebx
  const unsigned __int16 **i; // edi

  if ( !a2 )
    return -1;
  v3 = *(this + 219);
  result = 0;
  if ( v3 <= 0 )
    return -1;
  for ( i = (const unsigned __int16 **)*(this + 218); wcscmp(*i, a2); ++i )
  {
    if ( ++result >= v3 )
      return -1;
  }
  return result;
}
