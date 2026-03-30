__int16 __cdecl _Getwctype(wchar_t SrcStr, const _Ctypevec *a2)
{
  BOOL StringTypeW; // eax
  WORD CharType; // [esp+0h] [ebp-4h] BYREF

  StringTypeW = GetStringTypeW(1u, &SrcStr, 1, &CharType);
  return StringTypeW ? CharType : 0;
}
