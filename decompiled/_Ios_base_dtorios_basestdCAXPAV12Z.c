void __cdecl std::ios_base::_Ios_base_dtor(int ***a1)
{
  char *v1; // eax
  int *v2; // esi

  if ( !a1[2] || (v1 = (char *)&unk_4D6D2C + (_DWORD)a1[2], --*v1, *v1 <= 0) )
  {
    std::ios_base::_Tidy(a1);
    v2 = (int *)a1[12];
    if ( v2 )
    {
      sub_44DB20(v2);
      operator delete(v2);
    }
  }
}
