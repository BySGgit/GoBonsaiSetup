int __cdecl _FindAndUnlinkFrame(int a1)
{
  int result; // eax

  if ( a1 == *(_DWORD *)(_getptd() + 152) )
  {
    result = _getptd();
    *(_DWORD *)(result + 152) = *(_DWORD *)(a1 + 4);
  }
  else
  {
    for ( result = *(_DWORD *)(_getptd() + 152); ; result = *(_DWORD *)(result + 4) )
    {
      if ( !*(_DWORD *)(result + 4) )
        _inconsistency();
      if ( a1 == *(_DWORD *)(result + 4) )
        break;
    }
    *(_DWORD *)(result + 4) = *(_DWORD *)(a1 + 4);
  }
  return result;
}
