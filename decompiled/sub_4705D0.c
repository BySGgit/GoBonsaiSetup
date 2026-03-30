int sub_4705D0()
{
  void *v1[5]; // [esp+8h] [ebp-2Ch] BYREF
  unsigned int v2; // [esp+1Ch] [ebp-18h]
  int v3; // [esp+30h] [ebp-4h]

  LOWORD(v1[0]) = 0;
  v2 = 7;
  v1[4] = 0;
  sub_4032D0(L"cloudWindSpeed", (int)v1, 0xEu);
  v3 = 0;
  sub_408600(v1, (int)&unk_4D86E4, (int)&flt_4D5270);
  if ( v2 >= 8 )
    operator delete(v1[0]);
  return atexit(sub_4721F0);
}
