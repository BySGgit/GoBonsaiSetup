int __thiscall sub_437390(int *this)
{
  int result; // eax
  int (__stdcall *v3)(int, _DWORD, int *, _DWORD); // ecx

  if ( *(_BYTE *)(*(this + 6) + 1)
    && (int *)dword_4D7F28 != this
    && (*(unsigned __int8 (__thiscall **)(int *))(*this + 28))(this) )
  {
    if ( dword_4D7F28 )
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_4D7F28 + 36))(dword_4D7F28);
    (*(void (__thiscall **)(int *))(*this + 32))(this);
    dword_4D7F28 = (int)this;
  }
  result = *(this + 6);
  v3 = *(int (__stdcall **)(int, _DWORD, int *, _DWORD))(result + 576);
  if ( v3 )
    return v3(257, *(this + 11), this, *(_DWORD *)(result + 580));
  return result;
}
