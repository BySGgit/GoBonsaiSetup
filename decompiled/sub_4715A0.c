int sub_4715A0()
{
  void *v1[5]; // [esp+8h] [ebp-2Ch] BYREF
  unsigned int v2; // [esp+1Ch] [ebp-18h]
  int v3; // [esp+30h] [ebp-4h]

  LOWORD(v1[0]) = 0;
  v2 = 7;
  v1[4] = 0;
  sub_4032D0(L"sunColor", (int)v1, 8u);
  v3 = 0;
  sub_40FFC0(v1);
  if ( v2 >= 8 )
    operator delete(v1[0]);
  return atexit(sub_472360);
}
