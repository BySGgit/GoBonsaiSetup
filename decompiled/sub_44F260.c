int sub_44F260()
{
  int *v0; // esi
  int result; // eax

  v0 = &dword_4D8040;
  do
  {
    if ( *v0 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)*v0 + 8))(*v0);
      *v0 = 0;
    }
    result = 0;
    *v0 = 0;
    *((_WORD *)v0 - 32) = 0;
    v0 += 17;
  }
  while ( (int)v0 < (int)&unk_4D8260 );
  return result;
}
