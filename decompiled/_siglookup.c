unsigned int __usercall siglookup@<eax>(int a1@<edx>, unsigned int a2)
{
  unsigned int result; // eax

  result = a2;
  do
  {
    if ( *(_DWORD *)(result + 4) == a1 )
      break;
    result += 12;
  }
  while ( result < a2 + 144 );
  if ( result >= a2 + 144 || *(_DWORD *)(result + 4) != a1 )
    return 0;
  return result;
}
