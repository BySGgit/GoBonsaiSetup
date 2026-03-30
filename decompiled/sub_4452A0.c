_DWORD *__thiscall sub_4452A0(void *this, _DWORD *a2, int a3, _DWORD *a4, int a5, __int16 a6, int a7)
{
  const char *v7; // eax
  size_t v8; // eax
  _BYTE v11[8]; // [esp+10h] [ebp-50h] BYREF
  char Buffer[68]; // [esp+18h] [ebp-48h] BYREF

  v7 = sub_447330(v11, *(_DWORD *)(a5 + 20), "lu");
  v8 = sprintf_s(Buffer, 0x40u, v7, a7);
  sub_4473B0((int)this, a2, a5, a6, Buffer, v8, a3, a4);
  return a2;
}
