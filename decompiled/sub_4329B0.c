char __thiscall sub_4329B0(_BYTE *this, int a2, int a3, int a4, int a5, int a6)
{
  int v8; // eax
  void (__stdcall *v9)(int, _DWORD, _BYTE *, _DWORD); // ecx
  HWND v10; // eax

  if ( !*(this + 60) || !*(this + 4) )
    return 0;
  if ( a2 == 513 )
  {
LABEL_14:
    if ( !(*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)this + 52))(this, a3, a4) )
      return 0;
    *(this + 600) = 1;
    v10 = (HWND)sub_41B5D0();
    SetCapture(v10);
    if ( !*(this + 6) && (_BYTE *)dword_4D7F28 != this )
      sub_4302A0((int)this);
    return 1;
  }
  if ( a2 != 514 )
  {
    if ( a2 != 515 )
      return 0;
    goto LABEL_14;
  }
  if ( !*(this + 600) )
    return 0;
  *(this + 600) = 0;
  ReleaseCapture();
  if ( !*(_BYTE *)(*((_DWORD *)this + 6) + 1) )
    sub_4315F0();
  if ( (*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)this + 52))(this, a3, a4) )
  {
    v8 = *((_DWORD *)this + 6);
    v9 = *(void (__stdcall **)(int, _DWORD, _BYTE *, _DWORD))(v8 + 576);
    if ( v9 )
      v9(257, *((_DWORD *)this + 11), this, *(_DWORD *)(v8 + 580));
  }
  return 1;
}
