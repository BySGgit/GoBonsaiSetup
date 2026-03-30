BOOL __thiscall std::error_condition::operator==(_DWORD *this, _DWORD *a2)
{
  return *(this + 1) == a2[1] && *this == *a2;
}
