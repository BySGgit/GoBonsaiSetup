int __thiscall sub_44DBA0(_BYTE *this)
{
  int result; // eax
  int v3; // esi
  _DWORD *v4; // ecx
  int v5; // eax
  _DWORD v6[8]; // [esp+0h] [ebp-20h] BYREF

  v6[4] = v6;
  v6[7] = 0;
  result = *(_DWORD *)(*(_DWORD *)this + 4);
  if ( (*(this + result + 20) & 2) != 0 )
  {
    v3 = 0;
    if ( (*(this + result + 12) & 6) == 0 )
    {
      result = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + result + 56) + 52))(*(_DWORD *)(this + result + 56));
      if ( result == -1 )
        v3 = 4;
    }
    v4 = this + *(_DWORD *)(*(_DWORD *)this + 4);
    if ( v3 )
    {
      v5 = v3 | v4[3];
      if ( !v4[14] )
        LOBYTE(v5) = v5 | 4;
      result = v5 & 0x17;
      v4[3] = result;
      if ( (result & v4[4]) != 0 )
        sub_44DDA0(0);
    }
  }
  return result;
}
