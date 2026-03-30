int __thiscall sub_432DF0(int this, char a2, char a3)
{
  int result; // eax
  int (__stdcall *v4)(int, _DWORD, int, _DWORD); // edx

  *(_BYTE *)(this + 604) = a2;
  result = *(_DWORD *)(this + 24);
  v4 = *(int (__stdcall **)(int, _DWORD, int, _DWORD))(result + 576);
  if ( v4 && (a3 || *(_BYTE *)result) )
    return v4(1025, *(_DWORD *)(this + 44), this, *(_DWORD *)(result + 580));
  return result;
}
