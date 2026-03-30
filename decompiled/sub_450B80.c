int __thiscall sub_450B80(_DWORD *this, int a2, float a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  void (__stdcall *v6)(int, _DWORD); // edx

  v4 = (_DWORD *)*(this + 42);
  v5 = (_DWORD *)*v4;
  if ( (_DWORD *)*v4 != v4 )
  {
    do
    {
      v6 = *(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v5[2] + 28);
      v5 = (_DWORD *)*v5;
      v6(a2, LODWORD(a3));
    }
    while ( v5 != (_DWORD *)*(this + 42) );
  }
  return (*(int (__thiscall **)(_DWORD *, int, _DWORD))(*this + 24))(this, a2, LODWORD(a3));
}
