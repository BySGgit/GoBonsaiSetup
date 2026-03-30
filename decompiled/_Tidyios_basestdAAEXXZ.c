void __thiscall std::ios_base::_Tidy(int ***this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  _DWORD *v5; // edi

  std::ios_base::_Callfns(this, 0);
  v2 = *(this + 10);
  if ( v2 )
  {
    do
    {
      v3 = (_DWORD *)*v2;
      operator delete(v2);
      v2 = v3;
    }
    while ( v3 );
  }
  v4 = *(this + 11);
  *(this + 10) = 0;
  if ( v4 )
  {
    do
    {
      v5 = (_DWORD *)*v4;
      operator delete(v4);
      v4 = v5;
    }
    while ( v5 );
  }
  *(this + 11) = 0;
}
