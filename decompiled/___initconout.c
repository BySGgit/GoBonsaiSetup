HANDLE __initconout()
{
  HANDLE result; // eax

  result = CreateFileW(L"CONOUT$", 0x40000000u, 3u, 0, 3u, 0, 0);
  hConsoleOutput = result;
  return result;
}
