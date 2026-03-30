int __cdecl rand()
{
  int v0; // ecx
  unsigned int v1; // eax

  v0 = _getptd();
  v1 = 214013 * *(_DWORD *)(v0 + 20) + 2531011;
  *(_DWORD *)(v0 + 20) = v1;
  return HIWORD(v1) & 0x7FFF;
}
