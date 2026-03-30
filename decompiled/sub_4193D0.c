int __userpurge sub_4193D0@<eax>(int a1@<eax>, _WORD *a2@<ecx>, int a3, int a4)
{
  int result; // eax
  int v7; // ebx
  __int16 v8; // dx

  result = 0;
  if ( a1 )
  {
    v7 = a3 - (_DWORD)a2;
    while ( a4 )
    {
      v8 = *(_WORD *)((char *)a2 + v7);
      if ( !v8 )
        break;
      *a2++ = v8;
      --a4;
      if ( !--a1 )
      {
        *(a2 - 1) = 0;
        return -2147024774;
      }
    }
  }
  else
  {
    --a2;
    result = -2147024774;
  }
  *a2 = 0;
  return result;
}
