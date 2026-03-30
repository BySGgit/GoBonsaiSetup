unsigned __int16 *__thiscall sub_44D120(void *this, int a2, unsigned __int16 *a3, unsigned __int16 *a4)
{
  unsigned __int16 *i; // esi

  for ( i = a3; i != a4; ++i )
  {
    if ( (*(unsigned __int8 (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)this + 8))(this, a2, *i) )
      break;
  }
  return i;
}
