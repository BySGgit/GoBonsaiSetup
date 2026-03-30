_DWORD *__usercall sub_4032A0@<eax>(_DWORD *result@<eax>, _DWORD *a2@<edx>, _DWORD *a3)
{
  _DWORD *i; // ecx

  for ( i = a3; i != a2; ++result )
  {
    if ( result )
      *result = *i;
    ++i;
  }
  return result;
}
