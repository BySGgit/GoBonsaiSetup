int __thiscall sub_433260(int this, char a2, char a3, char a4)
{
  int result; // eax
  int (__stdcall *v6)(int, _DWORD, int, _DWORD); // ecx

  if ( a2 && a3 )
    sub_430250(*(_DWORD *)(this + 24), *(_DWORD *)(this + 640));
  result = *(_DWORD *)(this + 24);
  *(_BYTE *)(this + 604) = a2;
  v6 = *(int (__stdcall **)(int, _DWORD, int, _DWORD))(result + 576);
  if ( v6 && (a4 || *(_BYTE *)result) )
    return v6(769, *(_DWORD *)(this + 44), this, *(_DWORD *)(result + 580));
  return result;
}
