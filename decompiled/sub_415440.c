int __thiscall sub_415440(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // ebx
  int v5; // eax

  v2 = (_DWORD *)*(this + 42);
  v3 = (_DWORD *)*v2;
  v4 = 0;
  if ( (_DWORD *)*v2 != v2 )
  {
    do
    {
      v5 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v3[2] + 60))(v3[2]);
      v3 = (_DWORD *)*v3;
      v4 += v5;
    }
    while ( v3 != (_DWORD *)*(this + 42) );
  }
  return v4;
}
