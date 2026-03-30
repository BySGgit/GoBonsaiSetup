char __thiscall sub_432D30(_BYTE *this, int a2, int a3, int a4, int a5, int a6)
{
  HWND v8; // eax

  if ( !*(this + 60) || !*(this + 4) )
    return 0;
  if ( a2 == 513 )
  {
LABEL_11:
    if ( !(*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)this + 52))(this, a3, a4) )
      return 0;
    *(this + 600) = 1;
    v8 = (HWND)sub_41B5D0();
    SetCapture(v8);
    if ( !*(this + 6) && (_BYTE *)dword_4D7F28 != this )
      sub_4302A0((int)this);
    return 1;
  }
  if ( a2 != 514 )
  {
    if ( a2 != 515 )
      return 0;
    goto LABEL_11;
  }
  if ( !*(this + 600) )
    return 0;
  *(this + 600) = 0;
  ReleaseCapture();
  if ( (*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)this + 52))(this, a3, a4) )
    (*(void (__thiscall **)(_BYTE *, bool, int))(*(_DWORD *)this + 80))(this, *(this + 604) == 0, 1);
  return 1;
}
