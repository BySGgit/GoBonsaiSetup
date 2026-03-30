unsigned int __thiscall sub_444D50(int *this)
{
  unsigned int v1; // esi
  unsigned int result; // eax
  unsigned int v3; // eax

  if ( (unsigned int)((*(this + 1) - *this) / 28) > 0x9249248 )
    std::_Xlength_error("vector<T> too long");
  v1 = (*(this + 1) - *this) / 28 + 1;
  result = (*(this + 2) - *this) / 28;
  if ( v1 > result )
  {
    if ( 153391689 - (result >> 1) >= result )
      v3 = (result >> 1) + result;
    else
      v3 = 0;
    if ( v3 < v1 )
      v3 = (*(this + 1) - *this) / 28 + 1;
    return sub_446A30(this, v3);
  }
  return result;
}
