int __cdecl sub_44BBB0(_DWORD *a1, int a2)
{
  _DWORD *v2; // edi
  char v3; // bl
  _DWORD *v4; // esi
  const char *v5; // ecx
  _BYTE v7[36]; // [esp+1Ch] [ebp-30h] BYREF
  int v8; // [esp+48h] [ebp-4h]

  v2 = a1;
  v3 = 0;
  if ( a1 && !*a1 )
  {
    v4 = operator new(0x18u);
    v8 = 0;
    if ( v4 )
    {
      v5 = *(const char **)(*(_DWORD *)a2 + 24);
      if ( !v5 )
        v5 = (const char *)(*(_DWORD *)a2 + 28);
      sub_44D440(v5, (struct std::_Locinfo *)v7);
      v3 = 1;
      v4[1] = 0;
      v8 = 2;
      *v4 = &std::numpunct<wchar_t>::`vftable';
      sub_44BE10((int)v4);
      v2 = a1;
    }
    else
    {
      v4 = 0;
    }
    *v2 = v4;
    v8 = -1;
    if ( (v3 & 1) != 0 )
      sub_44D510((struct std::_Locinfo *)v7);
  }
  return 4;
}
