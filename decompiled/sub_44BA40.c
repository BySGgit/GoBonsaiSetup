int __cdecl sub_44BA40(_DWORD *a1, int a2)
{
  _DWORD *v2; // edi
  char v3; // bl
  _DWORD *v4; // esi
  const char *v5; // edi
  int v6; // edx
  _Cvtvec *v8; // [esp+0h] [ebp-44h]
  _BYTE v9[36]; // [esp+14h] [ebp-30h] BYREF
  int v10; // [esp+40h] [ebp-4h]

  v2 = a1;
  v3 = 0;
  if ( a1 && !*a1 )
  {
    v4 = operator new(0x10u);
    v10 = 0;
    if ( v4 )
    {
      v5 = *(const char **)(*(_DWORD *)a2 + 24);
      if ( !v5 )
        v5 = (const char *)(*(_DWORD *)a2 + 28);
      sub_44D440(v5, (struct std::_Locinfo *)v9);
      v3 = 1;
      v4[1] = 0;
      *v4 = &std::num_get<wchar_t,std::istreambuf_iterator<wchar_t>>::`vftable';
      v2 = a1;
      v4[2] = _Getcvt(v8);
      v4[3] = v6;
    }
    else
    {
      v4 = 0;
    }
    v10 = -1;
    *v2 = v4;
    if ( (v3 & 1) != 0 )
      sub_44D510((struct std::_Locinfo *)v9);
  }
  return 4;
}
