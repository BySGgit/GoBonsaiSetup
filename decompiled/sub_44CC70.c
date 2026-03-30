wchar_t __cdecl sub_44CC70(char a1, _Cvtvec *a2)
{
  wchar_t v3[2]; // [esp+0h] [ebp-8h] BYREF
  int v4; // [esp+4h] [ebp-4h] BYREF

  *(_DWORD *)v3 = 0;
  v4 = 0;
  _Mbrtowc(v3, &a1, 1u, (mbstate_t *)&v4, a2);
  return v3[0];
}
