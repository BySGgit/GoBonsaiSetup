bool sub_4380B0()
{
  HMODULE LibraryW; // eax
  HMODULE v1; // eax
  HMODULE v2; // eax

  if ( dword_4D7F60 || dword_4D7F58 || dword_4D7F64 )
    return 1;
  LibraryW = LoadLibraryW(L"d3d10.dll");
  dword_4D7F60 = LibraryW;
  if ( LibraryW )
  {
    D3D10CreateStateBlock = (HRESULT (__stdcall *)(ID3D10Device *, D3D10_STATE_BLOCK_MASK *, ID3D10StateBlock **))GetProcAddress(LibraryW, "D3D10CreateStateBlock");
    D3D10CreateDevice = (HRESULT (__stdcall *)(IDXGIAdapter *, D3D10_DRIVER_TYPE, HMODULE, UINT, UINT, ID3D10Device **))GetProcAddress(dword_4D7F60, "D3D10CreateDevice");
    D3D10StateBlockMaskUnion = (HRESULT (__stdcall *)(D3D10_STATE_BLOCK_MASK *, D3D10_STATE_BLOCK_MASK *, D3D10_STATE_BLOCK_MASK *))GetProcAddress(dword_4D7F60, "D3D10StateBlockMaskUnion");
    D3D10StateBlockMaskIntersect = (HRESULT (__stdcall *)(D3D10_STATE_BLOCK_MASK *, D3D10_STATE_BLOCK_MASK *, D3D10_STATE_BLOCK_MASK *))GetProcAddress(dword_4D7F60, "D3D10StateBlockMaskIntersect");
    D3D10StateBlockMaskDifference = (HRESULT (__stdcall *)(D3D10_STATE_BLOCK_MASK *, D3D10_STATE_BLOCK_MASK *, D3D10_STATE_BLOCK_MASK *))GetProcAddress(dword_4D7F60, "D3D10StateBlockMaskDifference");
    D3D10StateBlockMaskEnableCapture = (HRESULT (__stdcall *)(D3D10_STATE_BLOCK_MASK *, D3D10_DEVICE_STATE_TYPES, UINT, UINT))GetProcAddress(dword_4D7F60, "D3D10StateBlockMaskEnableCapture");
    D3D10StateBlockMaskDisableCapture = (HRESULT (__stdcall *)(D3D10_STATE_BLOCK_MASK *, D3D10_DEVICE_STATE_TYPES, UINT, UINT))GetProcAddress(dword_4D7F60, "D3D10StateBlockMaskDisableCapture");
    D3D10StateBlockMaskEnableAll = (HRESULT (__stdcall *)(D3D10_STATE_BLOCK_MASK *))GetProcAddress(
                                                                                      dword_4D7F60,
                                                                                      "D3D10StateBlockMaskEnableAll");
    D3D10StateBlockMaskDisableAll = (HRESULT (__stdcall *)(D3D10_STATE_BLOCK_MASK *))GetProcAddress(
                                                                                       dword_4D7F60,
                                                                                       "D3D10StateBlockMaskDisableAll");
    D3D10StateBlockMaskGetSetting = (BOOL (__stdcall *)(D3D10_STATE_BLOCK_MASK *, D3D10_DEVICE_STATE_TYPES, UINT))GetProcAddress(dword_4D7F60, "D3D10StateBlockMaskGetSetting");
  }
  v1 = LoadLibraryW(L"dxgi.dll");
  dword_4D7F58 = (int)v1;
  if ( v1 )
    CreateDXGIFactory = (HRESULT (__stdcall *)(const IID *const, void **))GetProcAddress(v1, "CreateDXGIFactory");
  v2 = LoadLibraryW(L"d3d10_1.dll");
  dword_4D7F64 = (int)v2;
  if ( v2 )
    D3D10CreateDevice1 = (HRESULT (__stdcall *)(IDXGIAdapter *, D3D10_DRIVER_TYPE, HMODULE, UINT, D3D10_FEATURE_LEVEL1, UINT, ID3D10Device1 **))GetProcAddress(v2, "D3D10CreateDevice1");
  return dword_4D7F58 && dword_4D7F60;
}
