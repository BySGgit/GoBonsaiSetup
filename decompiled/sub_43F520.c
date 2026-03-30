int __stdcall sub_43F520(int a1)
{
  int v2; // ecx

  v2 = dword_4D82C4;
  *(_DWORD *)a1 = dword_4D82C0;
  *(float *)(a1 + 16) = 1.0;
  *(_DWORD *)(a1 + 4) = v2;
  *(float *)(a1 + 20) = 1.0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 44) = 0;
  *(float *)(a1 + 24) = 1.0;
  *(float *)(a1 + 28) = 1.0;
  *(_DWORD *)(a1 + 40) = 22;
  return a1;
}
