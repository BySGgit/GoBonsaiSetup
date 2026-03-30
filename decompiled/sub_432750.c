BOOL __thiscall sub_432750(struct tagRECT *this)
{
  return SetRect(
           this + 4,
           this->right,
           this->bottom,
           this->right + *((_DWORD *)this + 4),
           this->bottom + *((_DWORD *)this + 5));
}
