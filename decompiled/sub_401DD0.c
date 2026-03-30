void __stdcall sub_401DD0(int a1)
{
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    sub_43FD00();
    atexit(sub_472560);
  }
  sub_440650((int)&dword_4D8E20, a1);
  if ( *(_DWORD *)(a1 + 20) >= 8u )
    operator delete(*(void **)a1);
  *(_DWORD *)(a1 + 20) = 7;
  *(_DWORD *)(a1 + 16) = 0;
  *(_WORD *)a1 = 0;
}
