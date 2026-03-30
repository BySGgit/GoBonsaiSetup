int __cdecl sub_44D5C0(int *a1, int a2)
{
  char v2; // bl
  void *v3; // esi
  const char *v4; // ecx
  int v5; // eax
  _BYTE v7[36]; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  v2 = 0;
  if ( a1 && !*a1 )
  {
    v3 = operator new(0x20u);
    v8 = 0;
    if ( v3 )
    {
      v4 = *(const char **)(*(_DWORD *)a2 + 24);
      if ( !v4 )
        v4 = (const char *)(*(_DWORD *)a2 + 28);
      sub_44D440(v4, (struct std::_Locinfo *)v7);
      v2 = 1;
      v5 = sub_44D3F0((int)v3);
    }
    else
    {
      v5 = 0;
    }
    v8 = -1;
    *a1 = v5;
    if ( (v2 & 1) != 0 )
      sub_44D510((struct std::_Locinfo *)v7);
  }
  return 2;
}
