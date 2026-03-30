int *__userpurge sub_44CB50@<eax>(size_t Size@<ecx>, char a2@<dl>, int a3@<esi>, int *a4)
{
  int *result; // eax

  result = a4;
  if ( Size == 1 )
  {
    if ( (unsigned int)a4[5] >= 0x10 )
      result = (int *)*a4;
    *((_BYTE *)result + a3) = a2;
  }
  else
  {
    if ( (unsigned int)a4[5] >= 0x10 )
      result = (int *)*a4;
    return (int *)memset((char *)result + a3, a2, Size);
  }
  return result;
}
