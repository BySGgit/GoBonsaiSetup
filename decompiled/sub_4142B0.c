void __thiscall sub_4142B0(int *this)
{
  int v2; // esi

  while ( 1 )
  {
    v2 = *(this + 45);
    if ( !v2 )
      goto LABEL_5;
    if ( (dword_4D7CF8 & 1) == 0 )
    {
      dword_4D7CF8 |= 1u;
      sub_4079C0();
    }
    if ( !byte_4D8225[11 * *(_DWORD *)(v2 + 4)] )
LABEL_5:
      v2 = 0;
    if ( *(float *)(v2 + 444) >= 0.69999999 || sub_4154B0(v2) > 1 )
      break;
    this = (int *)*(this + 45);
    if ( this )
    {
      if ( (dword_4D8CD0 & 1) == 0 )
      {
        dword_4D8CD0 |= 1u;
        sub_40FA00();
      }
      if ( byte_4D8228[11 * *(this + 1)] )
        return;
    }
  }
  if ( (dword_4D7CF8 & 1) == 0 )
  {
    dword_4D7CF8 |= 1u;
    sub_4079C0();
  }
  if ( byte_4D8225[11 * *(this + 1)] )
    sub_40EEE0((int)this);
}
