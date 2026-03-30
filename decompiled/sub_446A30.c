int __thiscall sub_446A30(int *this, unsigned int a2)
{
  int result; // eax
  _DWORD *v4; // eax
  int v5; // ebx
  _DWORD *v6; // [esp-Ch] [ebp-30h]
  int v7; // [esp+0h] [ebp-24h] BYREF
  void *v8; // [esp+10h] [ebp-14h]
  int *v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+20h] [ebp-4h]

  v9 = &v7;
  if ( a2 > 0x9249249 )
    std::_Xlength_error("vector<T> too long");
  result = (*(this + 2) - *this) / 28;
  if ( result < a2 )
  {
    v4 = sub_448F90(a2);
    v10 = 0;
    v6 = (_DWORD *)*(this + 1);
    v8 = v4;
    sub_44C4D0(v6, v4);
    v5 = (*(this + 1) - *this) / 28;
    if ( *this )
    {
      sub_446B40(*this, *(this + 1));
      operator delete((void *)*this);
    }
    result = (int)v8;
    *(this + 2) = (int)v8 + 28 * a2;
    *(this + 1) = result + 28 * v5;
    *this = result;
  }
  return result;
}
