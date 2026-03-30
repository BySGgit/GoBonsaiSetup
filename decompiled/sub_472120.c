void __cdecl sub_472120()
{
  char *v0; // eax
  char *v1; // ecx
  char *v2; // esi

  v0 = *(char **)dword_4D866C;
  *(_DWORD *)dword_4D866C = dword_4D866C;
  *((_DWORD *)dword_4D866C + 1) = dword_4D866C;
  v1 = dword_4D866C;
  dword_4D8670 = 0;
  if ( v0 != dword_4D866C )
  {
    do
    {
      v2 = *(char **)v0;
      operator delete(v0);
      v1 = dword_4D866C;
      v0 = v2;
    }
    while ( v2 != dword_4D866C );
  }
  operator delete(v1);
}
