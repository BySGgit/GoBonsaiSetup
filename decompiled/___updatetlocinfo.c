DWORD __updatetlocinfo()
{
  DWORD *v0; // esi
  DWORD v1; // esi
  volatile LONG *v3; // [esp+10h] [ebp-1Ch]

  v0 = _getptd();
  if ( (dword_4C9918 & v0[28]) != 0 && v0[27] )
  {
    v1 = _getptd()[27];
  }
  else
  {
    _lock(12);
    v3 = _updatetlocinfoEx_nolock((volatile LONG **)v0 + 27, off_4C9B60);
    _unlock(12);
    v1 = (DWORD)v3;
  }
  if ( !v1 )
    _amsg_exit(32);
  return v1;
}
