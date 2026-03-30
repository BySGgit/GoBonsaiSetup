bool __usercall sub_41B4E0@<al>(_DWORD *a1@<eax>)
{
  int v2; // eax

  if ( !a1 )
    return 1;
  if ( *a1 )
    v2 = a1[16];
  else
    v2 = a1[13];
  return v2 == 1;
}
