int __usercall sub_44D3F0@<eax>(int a1@<esi>)
{
  int v1; // edx
  _Ctypevec v3; // [esp+0h] [ebp-14h] BYREF

  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)a1 = &std::ctype<wchar_t>::`vftable';
  *(_Ctypevec *)(a1 + 8) = *_Getctype(&v3);
  *(_DWORD *)(a1 + 24) = _Getcvt((_Cvtvec *)v3._Page);
  *(_DWORD *)(a1 + 28) = v1;
  return a1;
}
