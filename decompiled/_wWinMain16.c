int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
  void *v4; // esi
  _DWORD *EngineInstance; // esi
  int v6; // esi

  sub_41BCB0();
  sub_41BC30();
  sub_41BBB0();
  sub_41BB30();
  sub_41BD30();
  sub_41BDB0();
  sub_41BE30();
  sub_41BEB0();
  sub_41BF30();
  sub_41BFB0();
  sub_451D70();
  sub_41C130();
  sub_427FF0();
  sub_41CC30(L"Go Bonsai!");
  sub_41E0B0(dword_4CA628, dword_4CA62C);
  sub_41DD60();
  v4 = dword_4D82D0;
  if ( dword_4D82D0 )
  {
    sub_412080(dword_4D82D0);
    operator delete(v4);
  }
  dword_4D82D0 = 0;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = EngineInstance[192];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  return v6;
}
