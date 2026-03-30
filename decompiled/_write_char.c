__int16 __usercall write_char@<ax>(int a1@<eax>, _DWORD *a2@<esi>, wchar_t Character)
{
  if ( ((*(_BYTE *)(a1 + 12) & 0x40) == 0 || *(_DWORD *)(a1 + 8))
    && (LOWORD(a1) = _fputwc_nolock(Character, (FILE *)a1), (_WORD)a1 == 0xFFFF) )
  {
    *a2 = -1;
  }
  else
  {
    ++*a2;
  }
  return a1;
}
