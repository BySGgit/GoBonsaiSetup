int __thiscall sub_448CB0(_DWORD *this, int a2)
{
  const void *v2; // eax

  v2 = (const void *)*(this + 4);
  *(_DWORD *)(a2 + 20) = 7;
  *(_DWORD *)(a2 + 16) = 0;
  *(_WORD *)a2 = 0;
  sub_4032D0(v2, a2, wcslen((const unsigned __int16 *)v2));
  return a2;
}
