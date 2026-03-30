int swprintf_s(wchar_t *const Buffer, const size_t BufferCount, const wchar_t *const Format, ...)
{
  va_list ArgList; // [esp+14h] [ebp+14h] BYREF

  va_start(ArgList, Format);
  return _vswprintf_s_l(Buffer, BufferCount, Format, 0, ArgList);
}
