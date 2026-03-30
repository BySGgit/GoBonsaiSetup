int sprintf_s(char *const Buffer, const size_t BufferCount, const char *const Format, ...)
{
  va_list ArgList; // [esp+14h] [ebp+14h] BYREF

  va_start(ArgList, Format);
  return _vsprintf_s_l(Buffer, BufferCount, Format, 0, ArgList);
}
