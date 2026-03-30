UINT __usercall ProcessCodePage@<eax>(int a1@<ecx>, int a2@<edi>, const char *a3@<esi>)
{
  WCHAR LCData[2]; // [esp+0h] [ebp-4h] BYREF

  *(_DWORD *)LCData = a1;
  if ( a3 && *a3 && strcmp(a3, "ACP") )
  {
    if ( strcmp(a3, "OCP") )
    {
      *(_DWORD *)LCData = atol(a3);
      return *(_DWORD *)LCData;
    }
    if ( GetLocaleInfoW(*(_DWORD *)(a2 + 28), 0x2000000Bu, LCData, 2) )
      return *(_DWORD *)LCData;
    return 0;
  }
  if ( !GetLocaleInfoW(*(_DWORD *)(a2 + 28), 0x20001004u, LCData, 2) )
    return 0;
  if ( *(_DWORD *)LCData )
    return *(_DWORD *)LCData;
  return GetACP();
}
