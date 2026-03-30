int __userpurge sub_4332C0@<eax>(int a1@<edi>, int a2)
{
  sub_432780();
  *(_DWORD *)(a1 + 48) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_BYTE *)(a1 + 600) = 0;
  *(_DWORD *)(a1 + 52) = 0;
  *(_DWORD *)a1 = &CDXUTComboBox::`vftable';
  sub_434BB0();
  *(_DWORD *)(a1 + 872) = 0;
  *(_DWORD *)(a1 + 876) = 0;
  *(_DWORD *)(a1 + 880) = 0;
  *(_DWORD *)(a1 + 24) = a2;
  *(_BYTE *)(a1 + 804) = 0;
  *(_DWORD *)(a1 + 604) = -1;
  *(_DWORD *)(a1 + 608) = -1;
  *(_DWORD *)(a1 + 48) = 4;
  *(_DWORD *)(a1 + 612) = 100;
  *(_DWORD *)(a1 + 800) = 16;
  return a1;
}
