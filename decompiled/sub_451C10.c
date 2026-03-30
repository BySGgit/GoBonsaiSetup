int __usercall sub_451C10@<eax>(
        int a1@<eax>,
        int a2,
        int a3,
        _DWORD *a4,
        unsigned __int8 (__cdecl *a5)(_DWORD *, _DWORD *))
{
  int v5; // edi
  int i; // esi
  _DWORD *v7; // ebx
  _DWORD *v8; // eax
  _DWORD *v9; // ebp
  int result; // eax

  v5 = a1;
  for ( i = (a1 - 1) / 2; a3 < v5; i = (i - 1) / 2 )
  {
    v7 = (_DWORD *)(a2 + 12 * i);
    if ( !a5(v7, a4) )
      break;
    v8 = (_DWORD *)(a2 + 12 * v5);
    *v8 = *v7;
    v8[1] = v7[1];
    v8[2] = v7[2];
    v5 = i;
  }
  v9 = (_DWORD *)(a2 + 12 * v5);
  *v9 = *a4;
  v9[1] = a4[1];
  result = a4[2];
  v9[2] = result;
  return result;
}
