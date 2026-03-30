int sub_419310(wchar_t *Buffer, wchar_t *Format, ...)
{
  int v2; // ecx
  int result; // eax
  unsigned int v4; // esi
  int v5; // edi
  int v6; // eax
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, Format);
  result = 0;
  if ( v2 <= 0 )
    result = -2147024809;
  if ( result >= 0 )
  {
    v4 = v2 - 1;
    v5 = 0;
    v6 = _vsnwprintf(Buffer, v2 - 1, Format, va);
    if ( v6 < 0 || v6 > v4 )
    {
      Buffer[v4] = 0;
      return -2147024774;
    }
    else if ( v6 == v4 )
    {
      Buffer[v4] = 0;
      return 0;
    }
    return v5;
  }
  return result;
}
