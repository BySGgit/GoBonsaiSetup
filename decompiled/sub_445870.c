_DWORD *__thiscall sub_445870(void *this, _DWORD *a2, int a3, _DWORD *a4, int a5, __int16 a6, const void *a7)
{
  size_t v8; // eax
  char Buffer[68]; // [esp+10h] [ebp-48h] BYREF

  v8 = sprintf_s(Buffer, 0x40u, "%p", a7);
  sub_4473B0((int)this, a2, a5, a6, Buffer, v8, a3, a4);
  return a2;
}
