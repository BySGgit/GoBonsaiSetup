int __cdecl _vsnwprintf(wchar_t *Buffer, size_t BufferCount, const wchar_t *Format, va_list Args)
{
  return _vsnwprintf_l(Buffer, BufferCount, Format, 0, Args);
}
