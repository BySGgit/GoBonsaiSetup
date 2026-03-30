char __thiscall sub_44D3A0(int this, wchar_t a2, char a3)
{
  bool v3; // zf
  char result; // al
  mbstate_t v5; // [esp+0h] [ebp-10h] BYREF

  v5._Wchar = 0;
  v3 = _Wcrtomb((char *)&v5._Byte, a2, &v5, (const _Cvtvec *)(this + 24)) == 1;
  result = a3;
  if ( v3 )
    return v5._Byte;
  return result;
}
