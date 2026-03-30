int __fastcall sub_431860(int a1, int a2, int a3)
{
  int v3; // esi
  int v4; // ecx
  int result; // eax
  _DWORD v6[7]; // [esp+38h] [ebp-20h] BYREF

  v3 = *(_DWORD *)(*(_DWORD *)(a3 + 68) + 4 * a1);
  if ( *(_BYTE *)v3 )
  {
    if ( !*(_WORD *)(v3 + 12) )
      return 0;
    result = D3DXCreateTextureFromFileExW(*(_DWORD *)(a3 + 60), v3 + 12, -1, -1, 1, 0, 0, 1, -1, -1, 0, v6, 0, v3 + 540);
    if ( result < 0 )
      return result;
    goto LABEL_12;
  }
  v4 = *(_DWORD *)(v3 + 8);
  if ( v4 == 0xFFFF && *(_DWORD *)(v3 + 4) == 0xFFFF )
  {
    result = D3DXCreateTextureFromFileInMemoryEx(
               *(_DWORD *)(a3 + 60),
               "DDS |",
               262272,
               -1,
               -1,
               1,
               0,
               0,
               1,
               -1,
               -1,
               0,
               v6,
               0,
               v3 + 540);
    if ( result < 0 )
      return result;
    goto LABEL_12;
  }
  if ( !v4 )
    v4 = v3 + 12;
  result = D3DXCreateTextureFromResourceExW(
             *(_DWORD *)(a3 + 60),
             *(_DWORD *)(v3 + 4),
             v4,
             -1,
             -1,
             1,
             0,
             0,
             1,
             -1,
             -1,
             0,
             v6,
             0,
             v3 + 540);
  if ( result >= 0 )
  {
LABEL_12:
    *(_DWORD *)(v3 + 532) = v6[0];
    *(_DWORD *)(v3 + 536) = v6[1];
    return 0;
  }
  return result;
}
