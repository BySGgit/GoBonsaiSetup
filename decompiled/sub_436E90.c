int __userpurge sub_436E90@<eax>(int a1@<eax>, _DWORD *a2@<edi>, int a3, int a4)
{
  int result; // eax

  *a2 = 0;
  if ( !*(_BYTE *)(a1 + 12) )
    return off_4D524C[0](*(_DWORD *)(a1 + 16), a3, a4, (int)a2);
  result = sub_436B30(a1);
  if ( result >= 0 )
    return off_4D524C[0](*(_DWORD *)(a1 + 16), a3, a4, (int)a2);
  return result;
}
