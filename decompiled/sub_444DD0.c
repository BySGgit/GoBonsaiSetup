_DWORD *__stdcall sub_444DD0(_DWORD *a1, int a2)
{
  int v2; // edx
  int v3; // esi
  void *v4; // ecx
  int v5; // eax

  *(_DWORD *)((char *)a1 + *(_DWORD *)(*a1 + 4)) = &std::wistream::`vftable';
  v2 = *a1;
  a1[2] = 0;
  a1[3] = 0;
  v3 = (int)a1 + *(_DWORD *)(v2 + 4);
  sub_44C650((_DWORD *)v3);
  *(_DWORD *)(v3 + 56) = a2;
  *(_DWORD *)(v3 + 60) = 0;
  *(_WORD *)(v3 + 64) = sub_44A550(v4, v3);
  if ( !*(_DWORD *)(v3 + 56) )
  {
    v5 = *(_DWORD *)(v3 + 12) & 0x13 | 4;
    *(_DWORD *)(v3 + 12) = v5;
    if ( (v5 & *(_DWORD *)(v3 + 16)) != 0 )
      sub_44DDA0(0);
  }
  *(_DWORD *)((char *)a1 + *(_DWORD *)(a1[4] + 4) + 16) = &std::wostream::`vftable';
  *(_DWORD *)((char *)a1 + *(_DWORD *)(*a1 + 4)) = &std::wiostream::`vftable';
  return a1;
}
