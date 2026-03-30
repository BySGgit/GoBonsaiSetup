void sub_43FBB0()
{
  char *v0; // eax
  char *v1; // ecx
  char *v2; // esi

  if ( dword_4D8E7C )
  {
    sub_446B40((int)dword_4D8E7C, dword_4D8E80);
    operator delete(dword_4D8E7C);
  }
  dword_4D8E7C = 0;
  dword_4D8E80 = 0;
  dword_4D8E84 = 0;
  if ( dword_4D8E6C )
  {
    sub_446B40((int)dword_4D8E6C, dword_4D8E70);
    operator delete(dword_4D8E6C);
  }
  dword_4D8E6C = 0;
  dword_4D8E70 = 0;
  dword_4D8E74 = 0;
  if ( (unsigned int)dword_4D8E64 >= 8 )
    operator delete(dword_4D8E50);
  dword_4D8E64 = 7;
  dword_4D8E60 = 0;
  LOWORD(dword_4D8E50) = 0;
  sub_444140((int)&dword_4D8E44);
  operator delete(dword_4D8E44);
  sub_444CE0((int)&dword_4D8E2C);
  operator delete(dword_4D8E2C);
  dword_4D8E2C = 0;
  v0 = *(char **)dword_4D8E20;
  *(_DWORD *)dword_4D8E20 = dword_4D8E20;
  *((_DWORD *)dword_4D8E20 + 1) = dword_4D8E20;
  v1 = dword_4D8E20;
  dword_4D8E24 = 0;
  if ( v0 != dword_4D8E20 )
  {
    do
    {
      v2 = *(char **)v0;
      operator delete(v0);
      v1 = dword_4D8E20;
      v0 = v2;
    }
    while ( v2 != dword_4D8E20 );
  }
  operator delete(v1);
}
