__int16 *__thiscall sub_40CFA0(_DWORD *this)
{
  char *v1; // esi
  _DWORD *v2; // eax
  int v4; // [esp-8h] [ebp-24h]
  int v5[2]; // [esp+8h] [ebp-14h] BYREF
  int v6; // [esp+18h] [ebp-4h]

  word_4D85C4 = 0;
  v5[1] = (int)&word_4D85C4;
  dword_4D85D8 = 7;
  dword_4D85D4 = 0;
  sub_4037B0(0xFFFFFFFF, (int)&word_4D85C4, this, 0);
  v6 = 0;
  dword_4D85E0 = (int)&dword_4D8644;
  dword_4D85E4 = 7;
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    sub_43FD00();
    atexit(sub_472560);
    LOBYTE(v6) = 0;
  }
  v1 = dword_4D8E20 + 4;
  v4 = *((_DWORD *)dword_4D8E20 + 1);
  v5[0] = (int)&word_4D85C4;
  v2 = sub_40FD70(dword_4D8E20, v4, v5);
  if ( dword_4D8E24 == 1073741822 )
    std::_Xlength_error("list<T> too long");
  ++dword_4D8E24;
  *(_DWORD *)v1 = v2;
  *(_DWORD *)v2[1] = v2;
  sub_44A640((int **)&dword_4D8E20);
  return &word_4D85C4;
}
