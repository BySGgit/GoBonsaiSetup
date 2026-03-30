_BYTE *__userpurge sub_44D260@<eax>(int a1@<ecx>, _BYTE *a2, _BYTE *a3, mbstate_t a4)
{
  _BYTE *v4; // ebx
  _BYTE *v5; // esi
  _WORD *Wchar; // edi
  const _Cvtvec *v7; // ebp
  bool v8; // sf
  __int16 v9; // ax

  v4 = a3;
  v5 = a2;
  if ( a2 != a3 )
  {
    Wchar = (_WORD *)a4._Wchar;
    v7 = (const _Cvtvec *)(a1 + 24);
    do
    {
      LOBYTE(a2) = *v5;
      a4._Wchar = 0;
      v8 = _Mbrtowc((wchar_t *)&a3, (const char *)&a2, 1u, &a4, v7) < 0;
      v9 = -1;
      if ( !v8 )
        v9 = (__int16)a3;
      *Wchar = v9;
      ++v5;
      ++Wchar;
    }
    while ( v5 != v4 );
  }
  return v5;
}
