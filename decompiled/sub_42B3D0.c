void *sub_42B3D0()
{
  void *v0; // eax
  void *v1; // eax
  void *result; // eax
  int v3; // [esp+8h] [ebp-14h] BYREF
  int v4; // [esp+Ch] [ebp-10h] BYREF
  int v5; // [esp+18h] [ebp-4h]

  if ( (dword_4D8EBC & 1) == 0 )
  {
    dword_4D8EBC |= 1u;
    v5 = 0;
    if ( !dword_4D7F1C )
    {
      v0 = operator new(0x44u);
      if ( v0 )
        v1 = (void *)sub_42B4A0((int)v0);
      else
        v1 = 0;
      dword_4D7F1C = v1;
    }
    atexit(sub_472520);
    v5 = -1;
  }
  result = dword_4D7F1C;
  if ( dword_4D7F1C )
  {
    if ( !*(_BYTE *)dword_4D7F1C )
    {
      *((_BYTE *)dword_4D7F1C + 52) = 0;
      sub_41C0B0(&v4, &v3);
      sub_42B4F0(v4, v3);
      return dword_4D7F1C;
    }
  }
  return result;
}
