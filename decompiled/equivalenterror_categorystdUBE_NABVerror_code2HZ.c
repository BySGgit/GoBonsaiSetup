BOOL __thiscall std::error_category::equivalent(
        std::error_category *this,
        std::error_category **a2,
        std::error_category *a3)
{
  return this == a2[1] && *a2 == a3;
}
