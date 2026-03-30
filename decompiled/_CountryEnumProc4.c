BOOL __stdcall CountryEnumProc(LPSTR a1)
{
  DWORD *v1; // esi
  int v2; // ecx
  int v3; // edi
  CHAR LCData[120]; // [esp+8h] [ebp-7Ch] BYREF

  v1 = _getptd();
  v3 = LcidFromHexString(v2, a1);
  if ( GetLocaleInfoA(v3, v1[44] != 0 ? 7 : 4098, LCData, 120) )
  {
    if ( !_stricmp((const char *)v1[40], LCData) )
    {
      if ( TestDefaultCountry(v3) )
      {
        v1[41] |= 4u;
        v1[46] = v3;
        v1[45] = v3;
      }
    }
    return (v1[41] & 4) == 0;
  }
  else
  {
    v1[41] = 0;
    return 1;
  }
}
