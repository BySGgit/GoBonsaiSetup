errno_t __cdecl _itoa_s(int Value, char *Buffer, size_t BufferCount, int Radix)
{
  if ( Radix == 10 && Value < 0 )
    return xtoa_s(Value, Buffer, BufferCount, 0xAu, 1);
  else
    return xtoa_s(Value, Buffer, BufferCount, Radix, 0);
}
