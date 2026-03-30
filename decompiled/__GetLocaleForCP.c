_locale_t __cdecl _GetLocaleForCP(unsigned int Value)
{
  LONG *v1; // esi
  LONG v2; // edi
  LONG v3; // ebx
  _locale_t LocForCP; // eax
  unsigned __int64 v6; // [esp-4h] [ebp-14h]

  v1 = 0;
  while ( 1 )
  {
    v2 = Target[Value % 0x3E];
    v3 = v2;
    if ( v2 )
      break;
LABEL_5:
    if ( !v1 )
    {
      v1 = (LONG *)_malloc_crt(0xCu);
      if ( !v1 )
        return 0;
      LODWORD(v6) = Value;
      LocForCP = _CreateLocForCP(v6);
      v1[2] = (LONG)LocForCP;
      if ( !LocForCP )
      {
        free(v1);
        return 0;
      }
      v1[1] = Value;
    }
    *v1 = v2;
    if ( InterlockedCompareExchange((volatile LONG *)(4 * (Value % 0x3E) + 5074376), (LONG)v1, v2) == v2 )
      return (_locale_t)v1[2];
  }
  while ( *(_DWORD *)(v3 + 4) != Value )
  {
    v3 = *(_DWORD *)v3;
    if ( !v3 )
      goto LABEL_5;
  }
  if ( v1 )
  {
    _free_locale((_locale_t)v1[2]);
    free(v1);
  }
  return *(_locale_t *)(v3 + 8);
}
