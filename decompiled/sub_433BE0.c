void __thiscall sub_433BE0(_DWORD *this)
{
  int v2; // eax
  void (__stdcall *v3)(int, _DWORD, _DWORD *, _DWORD); // ecx

  if ( !*((_BYTE *)this + 804) && *(this + 151) != -1 )
  {
    if ( *(_BYTE *)(*(this + 6) + 1)
      && (_DWORD *)dword_4D7F28 != this
      && (*(unsigned __int8 (__thiscall **)(_DWORD *))(*this + 28))(this) )
    {
      if ( dword_4D7F28 )
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_4D7F28 + 36))(dword_4D7F28);
      (*(void (__thiscall **)(_DWORD *))(*this + 32))(this);
      dword_4D7F28 = (int)this;
    }
    if ( ++*(this + 151) >= *(this + 219) )
      *(this + 151) = 0;
    v2 = *(this + 6);
    *(this + 152) = *(this + 151);
    v3 = *(void (__stdcall **)(int, _DWORD, _DWORD *, _DWORD))(v2 + 576);
    if ( v3 )
      v3(513, *(this + 11), this, *(_DWORD *)(v2 + 580));
  }
}
