BOOL __thiscall std::error_category::equivalent(
        std::error_category *this,
        int a2,
        const struct std::error_condition *a3)
{
  _DWORD *v3; // eax
  _BYTE v5[8]; // [esp+0h] [ebp-8h] BYREF

  v3 = (_DWORD *)(*(int (__thiscall **)(std::error_category *, _BYTE *, int))(*(_DWORD *)this + 12))(this, v5, a2);
  return std::error_condition::operator==(v3, a3);
}
