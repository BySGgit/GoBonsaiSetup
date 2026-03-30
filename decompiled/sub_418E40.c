void __thiscall sub_418E40(int this)
{
  int v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  int v5; // ecx

  if ( *(_BYTE *)(this + 236) )
  {
    v2 = *(_DWORD *)(this + 180);
    if ( !v2 )
      goto LABEL_14;
    if ( (dword_4D8CD0 & 1) == 0 )
    {
      dword_4D8CD0 |= 1u;
      sub_40FA00();
    }
    if ( !byte_4D8228[11 * *(_DWORD *)(v2 + 4)] )
    {
LABEL_14:
      if ( sub_415650(this) )
        sub_418D50(this);
    }
  }
  v3 = *(_DWORD **)(this + 168);
  v4 = (_DWORD *)*v3;
  if ( (_DWORD *)*v3 != v3 )
  {
    do
    {
      v5 = v4[2];
      v4 = (_DWORD *)*v4;
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 48))(v5);
    }
    while ( v4 != *(_DWORD **)(this + 168) );
  }
  if ( *(_BYTE *)(this + 236) )
    sub_40EEE0(this);
}
