BOOL __usercall TestDefaultLanguage@<eax>(int a1@<eax>, int a2, char **a3)
{
  int v4; // ecx
  BOOL result; // eax
  const char *v6; // esi
  int PrimaryLen; // edi
  WCHAR LCData[2]; // [esp+4h] [ebp-4h] BYREF

  result = 0;
  if ( GetLocaleInfoW(a1 & 0x3FF | 0x400, 0x20000001u, LCData, 2) )
  {
    if ( a1 == *(_DWORD *)LCData )
      return 1;
    if ( !a2 )
      return 1;
    v6 = *a3;
    PrimaryLen = GetPrimaryLen(v4, *a3);
    if ( PrimaryLen != strlen(v6) )
      return 1;
  }
  return result;
}
