_DWORD *__usercall sub_403440@<eax>(unsigned int a1@<eax>, unsigned int a2@<ecx>, _DWORD *a3@<esi>)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ebx
  _DWORD *v8; // edx
  unsigned int v9; // eax
  bool v10; // cf

  v4 = a3[4];
  if ( v4 < a2 )
    std::_Xout_of_range("invalid string position");
  v5 = v4 - a2;
  if ( v5 < a1 )
    a1 = v5;
  if ( a1 )
  {
    v6 = a3[5];
    if ( v6 < 8 )
      v7 = a3;
    else
      v7 = (_DWORD *)*a3;
    if ( v6 < 8 )
      v8 = a3;
    else
      v8 = (_DWORD *)*a3;
    memcpy((char *)v8 + 2 * a2, (char *)v7 + 2 * a2 + 2 * a1, 2 * (v5 - a1));
    v9 = a3[4] - a1;
    v10 = a3[5] < 8u;
    a3[4] = v9;
    if ( !v10 )
    {
      *(_WORD *)(*a3 + 2 * v9) = 0;
      return a3;
    }
    *((_WORD *)a3 + v9) = 0;
  }
  return a3;
}
