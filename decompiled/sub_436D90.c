char __stdcall sub_436D90(const void **a1, const unsigned __int16 *a2)
{
  signed int v2; // ebx
  _WORD *v3; // eax
  int v4; // edi
  void *v5; // esi
  int v6; // eax

  v2 = wcslen(a2) + 1;
  if ( v2 >= 0xFFFF )
    return 0;
  if ( (int)a1[1] < v2 )
  {
    do
    {
      v3 = a1[1];
      if ( v3 == (_WORD *)0xFFFF )
        break;
      if ( v3 )
      {
        v4 = 2 * (_DWORD)v3;
        if ( 2 * (int)v3 > 0xFFFF )
          v4 = 0xFFFF;
      }
      else
      {
        v4 = 256;
      }
      v5 = operator new[](2 * v4);
      if ( !v5 )
        break;
      memset(v5, 0, 2 * v4);
      if ( *a1 )
      {
        memcpy_0(v5, *a1, 2 * (_DWORD)a1[1]);
        operator delete[]((void *)*a1);
      }
      *a1 = v5;
      a1[1] = (const void *)v4;
    }
    while ( v4 < v2 );
  }
  v6 = (int)a1[1];
  if ( v6 < v2 )
    return 0;
  if ( v6 > 0 )
    sub_4193D0(v6, *a1, (int)a2, 2147483646);
  *((_BYTE *)a1 + 12) = 1;
  return 1;
}
