int __usercall sub_416300@<eax>(int a1@<esi>)
{
  if ( !a1 )
    return 0;
  if ( (dword_4D8CE0 & 1) == 0 )
  {
    dword_4D8CE0 |= 1u;
    sub_40FBA0();
  }
  if ( byte_4D822A[11 * *(_DWORD *)(a1 + 4)] )
    return a1;
  else
    return 0;
}
