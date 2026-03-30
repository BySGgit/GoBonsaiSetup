_DWORD *__usercall sub_447710@<eax>(int a1@<eax>, __int16 a2@<si>, _DWORD *a3, int a4, _DWORD *a5)
{
  _DWORD *v5; // ecx
  int i; // edi
  int *v7; // eax
  _WORD **v8; // eax
  _WORD *v9; // ecx
  __int16 v10; // ax

  v5 = a5;
  for ( i = a1; i; --i )
  {
    if ( v5 )
    {
      if ( *(_DWORD *)v5[9] && (v7 = (int *)v5[13], *v7 > 0) )
      {
        --*v7;
        v8 = (_WORD **)v5[9];
        v9 = (*v8)++;
        *v9 = a2;
        v10 = a2;
      }
      else
      {
        v10 = (*(int (__thiscall **)(_DWORD *, __int16))(*v5 + 12))(v5, a2);
      }
      v5 = a5;
      if ( v10 != -1 )
        continue;
    }
    LOBYTE(a4) = 1;
  }
  *a3 = a4;
  a3[1] = v5;
  return a3;
}
