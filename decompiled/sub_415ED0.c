int __thiscall sub_415ED0(int *this)
{
  int v2; // esi

  v2 = *(this + 45);
  if ( v2 )
    sub_450C80(this, v2);
  return (*(int (__thiscall **)(int *))(*this + 8))(this);
}
