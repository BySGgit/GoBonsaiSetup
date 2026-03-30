bool sub_4389F0()
{
  WCHAR Dst[260]; // [esp+0h] [ebp-20Ch] BYREF

  return ExpandEnvironmentStringsW(L"%SystemRoot%\\ehome\\ehshell.exe", Dst, 0x104u)
      && GetFileAttributesW(Dst) != -1
      && (int)ShellExecuteW(0, L"open", Dst, 0, 0, 1) > 32;
}
