void __stdcall sub_412080(_DWORD *a1)
{
  void (__thiscall *v1)(int); // edx
  void (__thiscall *v2)(int); // edx

  *a1 = &BonsaiController::`vftable';
  if ( dword_4D7EE4 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_4D7EE8 + 8))(dword_4D7EE8);
    v1 = *(void (__thiscall **)(int))(*(_DWORD *)dword_4D7EF0 + 8);
    dword_4D7EE8 = 0;
    v1(dword_4D7EF0);
    v2 = *(void (__thiscall **)(int))(*(_DWORD *)dword_4D7EEC + 8);
    dword_4D7EF0 = 0;
    v2(dword_4D7EEC);
    dword_4D7EEC = 0;
    sub_450F00();
    dword_4D7EE4 = 0;
  }
  sub_4019F0(a1 + 8);
}
