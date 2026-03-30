void *sub_428650()
{
  void *v0; // eax
  void *v1; // eax
  void *result; // eax
  int v3; // [esp+8h] [ebp-14h] BYREF
  int v4; // [esp+Ch] [ebp-10h] BYREF
  int v5; // [esp+18h] [ebp-4h]

  if ( (dword_4D8EA4 & 1) == 0 )
  {
    dword_4D8EA4 |= 1u;
    v5 = 0;
    if ( !dword_4D7F18 )
    {
      v0 = operator new(0x64u);
      if ( v0 )
        v1 = (void *)sub_428710((int)v0);
      else
        v1 = 0;
      dword_4D7F18 = v1;
    }
    atexit(sub_4724F0);
    v5 = -1;
  }
  result = dword_4D7F18;
  if ( dword_4D7F18 )
  {
    if ( !*(_BYTE *)dword_4D7F18 )
    {
      sub_41C030(&v4, &v3);
      sub_428830(v4, v3);
      return dword_4D7F18;
    }
  }
  return result;
}
