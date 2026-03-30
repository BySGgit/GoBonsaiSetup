int __thiscall sub_401CE0(_DWORD *this, int a2, int a3)
{
  bool v3; // zf
  char *v4; // edi
  _DWORD *v5; // eax
  int v7; // [esp-8h] [ebp-20h]

  *(_DWORD *)(a2 + 20) = 7;
  *(_DWORD *)(a2 + 16) = 0;
  *(_WORD *)a2 = 0;
  sub_4037B0(0xFFFFFFFF, a2, this, 0);
  v3 = (dword_4D8EC0 & 1) == 0;
  *(_DWORD *)(a2 + 28) = a3;
  *(_DWORD *)(a2 + 32) = 13;
  if ( v3 )
  {
    dword_4D8EC0 |= 1u;
    sub_43FD00();
    atexit(sub_472560);
  }
  v4 = dword_4D8E20 + 4;
  v7 = *((_DWORD *)dword_4D8E20 + 1);
  a3 = a2;
  v5 = sub_40FD70(dword_4D8E20, v7, &a3);
  if ( dword_4D8E24 == 1073741822 )
    std::_Xlength_error("list<T> too long");
  ++dword_4D8E24;
  *(_DWORD *)v4 = v5;
  *(_DWORD *)v5[1] = v5;
  sub_44A640((int **)&dword_4D8E20);
  return a2;
}
