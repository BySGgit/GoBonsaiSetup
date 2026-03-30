void __thiscall sub_414270(int this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // ecx

  v2 = *(_DWORD **)(this + 168);
  v3 = (_DWORD *)*v2;
  if ( (_DWORD *)*v2 != v2 )
  {
    do
    {
      v4 = v3[2];
      v3 = (_DWORD *)*v3;
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 48))(v4);
    }
    while ( v3 != *(_DWORD **)(this + 168) );
  }
  if ( *(_BYTE *)(this + 236) )
    sub_40EEE0(this);
}
