int __userpurge sub_4192D0@<eax>(int a1@<esi>, _WORD *a2, int a3)
{
  _WORD *v3; // ebx
  int result; // eax

  v3 = a2;
  result = sub_419370(a1, a2, &a2);
  if ( result >= 0 )
    return sub_4193D0(a1 - (_DWORD)a2, &v3[(_DWORD)a2], a3, 0x7FFFFFFF);
  return result;
}
