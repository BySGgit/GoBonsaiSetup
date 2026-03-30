void __cdecl srand(unsigned int Seed)
{
  *(_DWORD *)(_getptd() + 20) = Seed;
}
