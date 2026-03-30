int __thiscall sub_44D2D0(int this, char a2)
{
  bool v2; // sf
  int result; // eax
  wchar_t v4; // [esp+0h] [ebp-8h] BYREF
  int v5; // [esp+4h] [ebp-4h] BYREF

  v5 = 0;
  v2 = _Mbrtowc(&v4, &a2, 1u, (mbstate_t *)&v5, (const _Cvtvec *)(this + 24)) < 0;
  result = 0xFFFF;
  if ( !v2 )
    return v4;
  return result;
}
