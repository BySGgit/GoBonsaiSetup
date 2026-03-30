_Ctypevec *__cdecl _Getctype(_Ctypevec *__return_ptr retstr)
{
  int v1; // eax
  const unsigned __int16 *v2; // eax
  const unsigned __int16 *v3; // eax

  retstr->_Page = *(_DWORD *)(___lc_handle_func() + 4);
  retstr->_Table = (const __int16 *)___lc_codepage_func();
  v1 = _calloc_crt(256, 2);
  retstr->_Delfl = v1;
  if ( v1 )
  {
    v2 = __pctype_func();
    memcpy_0((void *)retstr->_Delfl, v2, 0x200u);
    retstr->_LocaleName = (wchar_t *)1;
  }
  else
  {
    v3 = __pctype_func();
    retstr->_LocaleName = 0;
    retstr->_Delfl = (int)v3;
  }
  return retstr;
}
