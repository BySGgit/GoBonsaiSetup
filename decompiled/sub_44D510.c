void __stdcall sub_44D510(struct std::_Locinfo *a1)
{
  std::_Locinfo::_Locinfo_dtor(a1);
  if ( *((_DWORD *)a1 + 7) )
    free(*((void **)a1 + 7));
  *((_DWORD *)a1 + 7) = 0;
  if ( *((_DWORD *)a1 + 5) )
    free(*((void **)a1 + 5));
  *((_DWORD *)a1 + 5) = 0;
  if ( *((_DWORD *)a1 + 3) )
    free(*((void **)a1 + 3));
  *((_DWORD *)a1 + 3) = 0;
  if ( *((_DWORD *)a1 + 1) )
    free(*((void **)a1 + 1));
  *((_DWORD *)a1 + 1) = 0;
  std::_Lockit::~_Lockit(a1);
}
