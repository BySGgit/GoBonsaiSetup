int __stdcall sub_44DC50(_BYTE **a1)
{
  int result; // eax

  if ( !__uncaught_exception() )
    sub_44DBA0(*a1);
  result = *(_DWORD *)&(*a1)[*(_DWORD *)(*(_DWORD *)*a1 + 4) + 56];
  if ( result )
    return (*(int (__thiscall **)(int))(*(_DWORD *)result + 8))(result);
  return result;
}
