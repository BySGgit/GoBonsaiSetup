int __userpurge sub_44BDA0@<eax>(unsigned int a1@<eax>, int a2@<ecx>, unsigned int a3@<edi>, _WORD *a4)
{
  unsigned int v4; // esi
  unsigned int v5; // edx
  _WORD *v6; // eax

  v4 = a1;
  if ( *(_DWORD *)(a2 + 16) < a1 )
    v4 = *(_DWORD *)(a2 + 16);
  v5 = v4;
  if ( v4 >= a3 )
    v5 = a3;
  if ( *(_DWORD *)(a2 + 20) < 8u )
    v6 = (_WORD *)a2;
  else
    v6 = *(_WORD **)a2;
  if ( v5 )
  {
    while ( *v6 == *a4 )
    {
      ++v6;
      ++a4;
      if ( !--v5 )
        goto LABEL_13;
    }
    return *v6 < *a4 ? -1 : 1;
  }
  else
  {
LABEL_13:
    if ( v4 >= a3 )
      return v4 != a3;
    else
      return -1;
  }
}
