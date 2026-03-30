_DWORD *__usercall sub_4476A0@<eax>(unsigned __int16 *a1@<eax>, _DWORD *a2, int a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // ecx
  int i; // ebp
  __int16 v8; // dx
  int *v9; // eax
  _WORD **v10; // eax
  _WORD *v11; // ecx
  __int16 v12; // ax

  v5 = a4;
  for ( i = a5; i; --i )
  {
    if ( !v5 )
      goto LABEL_8;
    v8 = *a1;
    if ( *(_DWORD *)v5[9] && (v9 = (int *)v5[13], *v9 > 0) )
    {
      --*v9;
      v10 = (_WORD **)v5[9];
      v11 = (*v10)++;
      *v11 = v8;
      v12 = v8;
    }
    else
    {
      v12 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*v5 + 12))(v5, *a1);
    }
    v5 = a4;
    if ( v12 == -1 )
LABEL_8:
      LOBYTE(a3) = 1;
    ++a1;
  }
  *a2 = a3;
  a2[1] = v5;
  return a2;
}
