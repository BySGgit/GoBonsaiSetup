int __usercall sub_403210@<eax>(int result@<eax>, _DWORD *a2@<edx>, _DWORD *a3)
{
  for ( ; result; --result )
  {
    if ( a3 )
      *a3 = *a2;
    ++a3;
  }
  return result;
}
