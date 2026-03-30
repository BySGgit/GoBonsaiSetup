int __cdecl flsall(int a1)
{
  int i; // esi
  int *v2; // eax
  int v3; // eax
  int v4; // ecx
  int result; // eax
  int v6; // [esp+10h] [ebp-24h]
  int v7; // [esp+18h] [ebp-1Ch]

  v7 = 0;
  v6 = 0;
  _lock(1);
  for ( i = 0; i < dword_4DCF20; ++i )
  {
    v2 = (int *)(dword_4DBF04 + 4 * i);
    if ( *v2 )
    {
      v3 = *v2;
      if ( (*(_BYTE *)(v3 + 12) & 0x83) != 0 )
      {
        _lock_file2(i, v3);
        v4 = *(_DWORD *)(*(_DWORD *)(dword_4DBF04 + 4 * i) + 12);
        if ( (v4 & 0x83) != 0 )
        {
          if ( a1 == 1 )
          {
            if ( _fflush_nolock(*(FILE **)(dword_4DBF04 + 4 * i)) != -1 )
              ++v7;
          }
          else if ( !a1 && (v4 & 2) != 0 && _fflush_nolock(*(FILE **)(dword_4DBF04 + 4 * i)) == -1 )
          {
            v6 = -1;
          }
        }
        _unlock_file2(i, *(_DWORD *)(dword_4DBF04 + 4 * i));
      }
    }
  }
  _unlock(1);
  result = v7;
  if ( a1 != 1 )
    return v6;
  return result;
}
