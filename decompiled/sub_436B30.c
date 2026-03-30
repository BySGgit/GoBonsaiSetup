int __usercall sub_436B30@<eax>(int a1@<esi>)
{
  int v1; // eax
  int result; // eax
  int v3; // edi
  int v4; // eax
  int v5; // [esp-2Ch] [ebp-38h]
  __int16 v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h] BYREF

  if ( *(_DWORD *)(a1 + 16) )
    off_4D5254[0](a1 + 16);
  v7 = 0;
  v6 = 0;
  off_4D5244(0, (int)&v7, (int)&v6);
  v1 = *(_DWORD *)(a1 + 8);
  if ( !v1 )
    return -2147467259;
  if ( *(_DWORD *)(v1 + 532) )
  {
    v3 = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v1 + 532) + 32))(*(_DWORD *)(v1 + 532));
  }
  else if ( *(_DWORD *)(v1 + 528) )
  {
    v3 = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v1 + 528) + 32))(*(_DWORD *)(v1 + 528));
  }
  else
  {
    v3 = 0;
  }
  v5 = 3 * lstrlenW(*(LPCWSTR *)a1) / 2 + 16;
  v4 = lstrlenW(*(LPCWSTR *)a1);
  result = off_4D5248(v3, *(_DWORD *)a1, v4 + 1, v5, -1, 4320, 0, (int)&v7, (int)&v6, 0, 0, 0, a1 + 16);
  if ( result >= 0 )
    *(_BYTE *)(a1 + 12) = 0;
  return result;
}
