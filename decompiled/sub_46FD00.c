int sub_46FD00()
{
  void *v1[5]; // [esp+8h] [ebp-2Ch] BYREF
  unsigned int v2; // [esp+1Ch] [ebp-18h]
  int v3; // [esp+30h] [ebp-4h]

  LOWORD(v1[0]) = 0;
  v2 = 7;
  v1[4] = 0;
  sub_4032D0(L"toggleFirstPerson", (int)v1, 0x11u);
  v3 = 0;
  sub_401CE0(v1, (int)&unk_4D82E8, (int)sub_4022A0);
  if ( v2 >= 8 )
    operator delete(v1[0]);
  return atexit(sub_471E90);
}
