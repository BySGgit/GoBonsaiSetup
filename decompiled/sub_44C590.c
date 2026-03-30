wchar_t *__cdecl sub_44C590(const char *a1, _Cvtvec *a2)
{
  const char *v2; // ebx
  int v3; // esi
  size_t v4; // edi
  const char *i; // ebp
  int v6; // eax
  int v7; // esi
  wchar_t *v8; // ebp
  wchar_t *v9; // edi
  int v10; // eax
  mbstate_t v12; // [esp+10h] [ebp-Ch] BYREF
  size_t v13; // [esp+18h] [ebp-4h]

  v2 = a1;
  v3 = 0;
  v12._Wchar = 0;
  v4 = strlen(a1) + 1;
  v13 = v4;
  for ( i = a1; v4; v4 -= v6 )
  {
    v6 = _Mbrtowc((wchar_t *)&a1, i, v4, &v12, a2);
    if ( v6 <= 0 )
      break;
    i += v6;
    ++v3;
  }
  v7 = v3 + 1;
  v8 = (wchar_t *)operator new[](2 * v7);
  v9 = v8;
  for ( *(_DWORD *)&v12._Byte = 0; v7; --v7 )
  {
    v10 = _Mbrtowc(v9, v2, v13, (mbstate_t *)&v12._Byte, a2);
    if ( v10 <= 0 )
      break;
    v2 += v10;
    ++v9;
  }
  *v9 = 0;
  return v8;
}
