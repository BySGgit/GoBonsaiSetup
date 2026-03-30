_locale_t __cdecl _CreateLocForCP(unsigned __int64 Value)
{
  char Locale; // [esp+0h] [ebp-24h] BYREF
  char Buffer[31]; // [esp+1h] [ebp-23h] BYREF

  Locale = 46;
  _ui64toa_s((unsigned int)Value, Buffer, 0x1Fu, 10);
  return _create_locale(0, &Locale);
}
