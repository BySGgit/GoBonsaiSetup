int __userpurge sub_436ED0@<eax>(int a1@<eax>, int *a2@<edi>, int a3, _DWORD *a4)
{
  int v5; // ebp

  *a2 = 0;
  *a4 = 0;
  if ( !*(_BYTE *)(a1 + 12) || (v5 = sub_436B30(a1), v5 >= 0) )
    v5 = off_4D5250(*(_DWORD *)(a1 + 16), a3, (int)a2, (int)a4);
  if ( *a2 == -1 && *a4 == 1 )
  {
    *a2 = 0;
    *a4 = 0;
    return v5;
  }
  else
  {
    if ( *a2 > lstrlenW(*(LPCWSTR *)a1) && !*a4 )
    {
      *a2 = lstrlenW(*(LPCWSTR *)a1);
      *a4 = 1;
    }
    return v5;
  }
}
