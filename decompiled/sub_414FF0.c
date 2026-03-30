_DWORD *__thiscall sub_414FF0(_DWORD *this)
{
  _DWORD *result; // eax
  _DWORD *v3; // esi
  int v4; // ecx

  result = (_DWORD *)*(this + 42);
  v3 = (_DWORD *)*result;
  if ( (_DWORD *)*result != result )
  {
    do
    {
      v4 = v3[2];
      v3 = (_DWORD *)*v3;
      result = (_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
    }
    while ( v3 != (_DWORD *)*(this + 42) );
  }
  return result;
}
