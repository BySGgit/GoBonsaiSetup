int __cdecl iswctype(wint_t C, wctype_t Type)
{
  int v2; // ecx
  WORD v4; // ax
  WORD CharType[2]; // [esp+0h] [ebp-4h] BYREF

  *(_DWORD *)CharType = v2;
  if ( C == 0xFFFF )
    return 0;
  if ( C >= 0x100u )
  {
    if ( !GetStringTypeW(1u, &C, 1, CharType) )
      *(_DWORD *)CharType = 0;
    v4 = CharType[0];
  }
  else
  {
    v4 = *((_WORD *)off_4C93DC + C);
  }
  return Type & v4;
}
