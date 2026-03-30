int __usercall sub_4302A0@<eax>(int a1@<esi>)
{
  int result; // eax

  result = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 28))(a1);
  if ( (_BYTE)result )
  {
    if ( dword_4D7F28 )
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_4D7F28 + 36))(dword_4D7F28);
    result = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 32))(a1);
    dword_4D7F28 = a1;
  }
  return result;
}
