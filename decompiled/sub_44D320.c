wchar_t *__thiscall sub_44D320(char *this, wchar_t *a2, wchar_t *a3, char a4, char *a5)
{
  wchar_t *v5; // esi
  const _Cvtvec *v7; // ebx
  bool v8; // zf
  char Byte; // al
  wchar_t v11; // [esp-10h] [ebp-2Ch]
  mbstate_t v12; // [esp+Ch] [ebp-10h] BYREF

  v5 = a2;
  if ( a2 != a3 )
  {
    v7 = (const _Cvtvec *)(this + 24);
    do
    {
      v11 = *v5;
      v12._Wchar = 0;
      v8 = _Wcrtomb((char *)&v12._Byte, v11, &v12, v7) == 1;
      Byte = a4;
      if ( v8 )
        Byte = v12._Byte;
      *a5 = Byte;
      ++v5;
      ++a5;
    }
    while ( v5 != a3 );
  }
  return v5;
}
