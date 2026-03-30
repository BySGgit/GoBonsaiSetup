_BYTE *__cdecl _NMSG_WRITE(int a1)
{
  _BYTE *result; // eax
  _BYTE *v2; // edi
  size_t v3; // eax
  void *v4; // esi
  unsigned int i; // eax
  size_t v6; // eax
  DWORD NumberOfBytesWritten; // [esp+Ch] [ebp-1FCh] BYREF
  char Buffer[500]; // [esp+10h] [ebp-1F8h] BYREF

  result = _GET_RTERRMSG(a1);
  v2 = result;
  NumberOfBytesWritten = (DWORD)result;
  if ( result )
  {
    if ( _set_error_mode(3) == 1 || (result = (_BYTE *)_set_error_mode(3)) == 0 && dword_4C9230 == 1 )
    {
      result = GetStdHandle(0xFFFFFFF4);
      v4 = result;
      if ( result && result != (_BYTE *)-1 )
      {
        for ( i = 0; i < 0x1F4; ++i )
        {
          Buffer[i] = v2[2 * i];
          if ( !*(_WORD *)&v2[2 * i] )
            break;
        }
        Buffer[499] = 0;
        v6 = strlen(Buffer);
        return (_BYTE *)WriteFile(v4, Buffer, v6, &NumberOfBytesWritten, 0);
      }
    }
    else if ( a1 != 252 )
    {
      if ( wcscpy_s(&word_4D72E0, 0x314u, aRuntimeErrorPr) )
        _invoke_watson(0, 0, 0, 0, 0);
      word_4D751A = 0;
      if ( !GetModuleFileNameW(0, String, 0x104u) && wcscpy_s(String, 0x2FBu, L"<program name unknown>")
        || wcslen(String) + 1 > 0x3C
        && (v3 = wcslen(String),
            wcsncpy_s((wchar_t *)(2 * v3 + 5075612), 763 - ((int)(2 * v3 + 5075612 - (_DWORD)String) >> 1), L"...", 3u))
        || wcscat_s(&word_4D72E0, 0x314u, L"\n\n")
        || wcscat_s(&word_4D72E0, 0x314u, (const wchar_t *)NumberOfBytesWritten) )
      {
        _invoke_watson(0, 0, 0, 0, 0);
      }
      return (_BYTE *)sub_46556C((int)&word_4D72E0, (int)L"Microsoft Visual C++ Runtime Library", 73744);
    }
  }
  return result;
}
