void __usercall sub_4441D0(_DWORD *a1@<ecx>, int *a2@<edi>)
{
  unsigned int v3; // ecx
  int v4; // esi
  _DWORD *v5; // eax
  int v6; // ecx
  int v7; // ecx

  v3 = a2[1];
  if ( (unsigned int)a1 >= v3 || *a2 > (unsigned int)a1 )
  {
    if ( v3 == a2[2] )
      sub_444D50(a2);
    v7 = a2[1];
    if ( v7 )
    {
      *(_DWORD *)(v7 + 20) = 7;
      *(_DWORD *)(v7 + 16) = 0;
      *(_WORD *)v7 = 0;
      sub_4037B0(0xFFFFFFFF, v7, a1, 0);
    }
  }
  else
  {
    v4 = ((int)a1 - *a2) / 28;
    if ( v3 == a2[2] )
      sub_444D50(a2);
    v5 = (_DWORD *)(*a2 + 28 * v4);
    v6 = a2[1];
    if ( v6 )
    {
      *(_DWORD *)(v6 + 20) = 7;
      *(_DWORD *)(v6 + 16) = 0;
      *(_WORD *)v6 = 0;
      sub_4037B0(0xFFFFFFFF, v6, v5, 0);
    }
  }
  a2[1] += 28;
}
