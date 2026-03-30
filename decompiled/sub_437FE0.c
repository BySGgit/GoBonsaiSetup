bool sub_437FE0()
{
  HMODULE LibraryW; // eax

  if ( dword_4D7F34 )
    return 1;
  LibraryW = LoadLibraryW(L"d3d9.dll");
  dword_4D7F34 = LibraryW;
  if ( LibraryW )
  {
    Direct3DCreate9 = (IDirect3D9 *(__stdcall *)(UINT))GetProcAddress(LibraryW, "Direct3DCreate9");
    D3DPERF_BeginEvent = (int)GetProcAddress(dword_4D7F34, "D3DPERF_BeginEvent");
    D3DPERF_EndEvent = (int)GetProcAddress(dword_4D7F34, "D3DPERF_EndEvent");
    D3DPERF_SetMarker = (int)GetProcAddress(dword_4D7F34, "D3DPERF_SetMarker");
    D3DPERF_SetRegion = (int)GetProcAddress(dword_4D7F34, "D3DPERF_SetRegion");
    D3DPERF_QueryRepeatFrame = (int)GetProcAddress(dword_4D7F34, "D3DPERF_QueryRepeatFrame");
    D3DPERF_SetOptions = (int)GetProcAddress(dword_4D7F34, "D3DPERF_SetOptions");
    D3DPERF_GetStatus = (int)GetProcAddress(dword_4D7F34, "D3DPERF_GetStatus");
    LibraryW = dword_4D7F34;
  }
  return LibraryW != 0;
}
