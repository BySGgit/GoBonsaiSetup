_DWORD *__usercall sub_44C210@<eax>(unsigned __int16 *a1@<eax>, _DWORD *a2, unsigned __int16 *a3, _WORD *a4)
{
  unsigned __int16 *v4; // esi

  v4 = a1;
  if ( a1 == a3 )
  {
    *a2 = a4;
    return a2;
  }
  else
  {
    do
      *a4++ = tolower(*v4++);
    while ( v4 != a3 );
    *a2 = a4;
    return a2;
  }
}
