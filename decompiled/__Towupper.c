wchar_t __cdecl _Towupper(wchar_t SrcStr, const _Ctypevec *a2)
{
  wchar_t result; // ax
  bool v3; // zf
  WCHAR DestStr[2]; // [esp+0h] [ebp-4h] BYREF

  result = SrcStr;
  *(_DWORD *)DestStr = SrcStr;
  if ( SrcStr != 0xFFFF )
  {
    if ( a2->_Page || SrcStr >= 0x100u )
    {
      v3 = __crtLCMapStringW(a2->_Page, 0x200u, &SrcStr, 1, DestStr, 1) == 0;
      result = SrcStr;
      if ( !v3 )
        return DestStr[0];
    }
    else if ( (unsigned __int16)(SrcStr - 97) <= 0x19u )
    {
      return SrcStr - 32;
    }
  }
  return result;
}
