_DWORD *__usercall sub_448FF0@<eax>(char *a1@<eax>, int a2, _DWORD *a3, int a4, _DWORD *a5, int a6)
{
  _DWORD *result; // eax
  _DWORD *v8; // ecx
  wchar_t v9; // dx
  int *v10; // ebx
  _WORD **v11; // eax
  wchar_t *v12; // ecx
  wchar_t v13; // ax
  char v14[4]; // [esp+8h] [ebp-10h] BYREF
  wchar_t v15[2]; // [esp+Ch] [ebp-Ch] BYREF
  _Cvtvec *v16; // [esp+10h] [ebp-8h]
  int v17; // [esp+14h] [ebp-4h] BYREF

  result = a3;
  if ( a6 )
  {
    v16 = (_Cvtvec *)(a2 + 8);
    do
    {
      v14[0] = *a1;
      *(_DWORD *)v15 = 0;
      v17 = 0;
      _Mbrtowc(v15, v14, 1u, (mbstate_t *)&v17, v16);
      v8 = a5;
      if ( !a5 )
        goto LABEL_9;
      v9 = v15[0];
      if ( *(_DWORD *)a5[9] && (v10 = (int *)a5[13], *v10 > 0) )
      {
        --*v10;
        v11 = (_WORD **)a5[9];
        v12 = (*v11)++;
        *v12 = v9;
        v13 = v9;
      }
      else
      {
        v13 = (*(int (__stdcall **)(_DWORD))(*a5 + 12))(*(_DWORD *)v15);
      }
      v8 = a5;
      if ( v13 == 0xFFFF )
LABEL_9:
        LOBYTE(a4) = 1;
      ++a1;
      --a6;
    }
    while ( a6 );
    *a3 = a4;
    a3[1] = v8;
    return a3;
  }
  else
  {
    *a3 = a4;
    a3[1] = a5;
  }
  return result;
}
