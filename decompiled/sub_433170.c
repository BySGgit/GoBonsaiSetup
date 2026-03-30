char __thiscall sub_433170(void *this, int a2, int a3, int a4, int a5, int a6)
{
  int v8; // eax
  void (__stdcall *v9)(int, _DWORD, void *, _DWORD); // ecx
  HWND v10; // eax

  if ( !*((_BYTE *)this + 60) || !*((_BYTE *)this + 4) )
    return 0;
  if ( a2 == 513 )
  {
LABEL_12:
    if ( !(*(int (__thiscall **)(void *, int, int))(*(_DWORD *)this + 52))(this, a3, a4) )
      return 0;
    *((_BYTE *)this + 600) = 1;
    v10 = (HWND)sub_41B5D0();
    SetCapture(v10);
    if ( !*((_BYTE *)this + 6) && (void *)dword_4D7F28 != this )
      sub_4302A0((int)this);
    return 1;
  }
  if ( a2 != 514 )
  {
    if ( a2 != 515 )
      return 0;
    goto LABEL_12;
  }
  if ( !*((_BYTE *)this + 600) )
    return 0;
  *((_BYTE *)this + 600) = 0;
  ReleaseCapture();
  if ( (*(int (__thiscall **)(void *, int, int))(*(_DWORD *)this + 52))(this, a3, a4) )
  {
    sub_430250(*((_DWORD *)this + 6), *((_DWORD *)this + 160));
    v8 = *((_DWORD *)this + 6);
    *((_BYTE *)this + 604) = *((_BYTE *)this + 604) == 0;
    v9 = *(void (__stdcall **)(int, _DWORD, void *, _DWORD))(v8 + 576);
    if ( v9 )
      v9(769, *((_DWORD *)this + 11), this, *(_DWORD *)(v8 + 580));
  }
  return 1;
}
