void *__set_flsgetvalue()
{
  void *Value; // esi

  Value = TlsGetValue(dwTlsIndex);
  if ( !Value )
  {
    Value = DecodePointer(lpTlsValue);
    TlsSetValue(dwTlsIndex, Value);
  }
  return Value;
}
