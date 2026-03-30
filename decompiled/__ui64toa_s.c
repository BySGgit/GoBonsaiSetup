errno_t __cdecl _ui64toa_s(unsigned __int64 Value, char *Buffer, size_t BufferCount, int Radix)
{
  return x64toa_s(Buffer, Value, BufferCount, Radix, 0);
}
