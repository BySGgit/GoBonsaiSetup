int sub_470520()
{
  void *v1[5]; // [esp+8h] [ebp-2Ch] BYREF
  unsigned int v2; // [esp+1Ch] [ebp-18h]
  int v3; // [esp+30h] [ebp-4h]

  LOWORD(v1[0]) = 0;
  v2 = 7;
  v1[4] = 0;
  sub_4032D0(L"enableSun", (int)v1, 9u);
  v3 = 0;
  sub_4038B0(v1, (int)&unk_4D86C0, (int)&byte_4D523F);
  if ( v2 >= 8 )
    operator delete(v1[0]);
  return atexit(sub_4721E0);
}
