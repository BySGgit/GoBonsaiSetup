int __stdcall sub_452800(int a1)
{
  int result; // eax

  sub_42E410();
  if ( dword_4D82C8 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D82C8 + 8))(dword_4D82C8);
    dword_4D82C8 = 0;
  }
  result = dword_4D82C0;
  if ( dword_4D82C0 )
  {
    result = (*(int (__stdcall **)(int))(*(_DWORD *)dword_4D82C0 + 8))(dword_4D82C0);
    dword_4D82C0 = 0;
  }
  return result;
}
