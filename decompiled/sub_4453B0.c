_DWORD *__thiscall sub_4453B0(void *this, _DWORD *a2, int a3, _DWORD *a4, int a5, __int16 a6, int a7, int a8)
{
  const char *v8; // eax
  size_t v9; // eax
  _BYTE v12[8]; // [esp+10h] [ebp-50h] BYREF
  char Buffer[68]; // [esp+18h] [ebp-48h] BYREF

  v8 = sub_447330(v12, *(_DWORD *)(a5 + 20), "Lu");
  v9 = sprintf_s(Buffer, 0x40u, v8, a7, a8);
  sub_4473B0((int)this, a2, a5, a6, Buffer, v9, a3, a4);
  return a2;
}
