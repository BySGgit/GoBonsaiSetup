char __thiscall sub_433660(int this, int a2, int a3, int a4)
{
  int v5; // eax
  int v6; // eax
  void (__stdcall *v7)(int, _DWORD, int, _DWORD); // ecx
  bool v8; // al
  int v9; // eax
  void (__stdcall *v10)(int, _DWORD, int, _DWORD); // ecx
  char result; // al
  int v12; // eax
  int v13; // eax
  bool v14; // zf
  int v15; // eax
  void (__stdcall *v16)(int, _DWORD, int, _DWORD); // ecx

  if ( !*(_BYTE *)(this + 60) || !*(_BYTE *)(this + 4) )
    return 0;
  if ( (*(unsigned __int8 (__thiscall **)(int, int, int, int))(*(_DWORD *)(this + 616) + 20))(this + 616, a2, a3, a4) )
    return 1;
  if ( a2 != 256 )
    return 0;
  switch ( a3 )
  {
    case 13:
      if ( !*(_BYTE *)(this + 804) )
        return 0;
      v5 = *(_DWORD *)(this + 608);
      if ( *(_DWORD *)(this + 604) != v5 )
      {
        *(_DWORD *)(this + 604) = v5;
        v6 = *(_DWORD *)(this + 24);
        v7 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v6 + 576);
        if ( v7 )
          v7(513, *(_DWORD *)(this + 44), this, *(_DWORD *)(v6 + 580));
      }
      *(_BYTE *)(this + 804) = 0;
      goto LABEL_15;
    case 37:
    case 38:
      v12 = *(_DWORD *)(this + 608);
      if ( v12 <= 0 )
        return 1;
      v13 = v12 - 1;
      goto LABEL_20;
    case 39:
    case 40:
      v13 = *(_DWORD *)(this + 608) + 1;
      if ( v13 >= *(_DWORD *)(this + 876) )
        return 1;
LABEL_20:
      v14 = *(_BYTE *)(this + 804) == 0;
      *(_DWORD *)(this + 608) = v13;
      *(_DWORD *)(this + 604) = v13;
      if ( v14 )
      {
        v15 = *(_DWORD *)(this + 24);
        v16 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v15 + 576);
        if ( v16 )
          v16(513, *(_DWORD *)(this + 44), this, *(_DWORD *)(v15 + 580));
      }
      return 1;
    case 115:
      if ( (a4 & 0x40000000) != 0 )
        return 1;
      v8 = *(_BYTE *)(this + 804) == 0;
      *(_BYTE *)(this + 804) = v8;
      if ( v8 )
        return 1;
      v9 = *(_DWORD *)(this + 24);
      v10 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v9 + 576);
      if ( v10 )
        v10(513, *(_DWORD *)(this + 44), this, *(_DWORD *)(v9 + 580));
LABEL_15:
      if ( *(_BYTE *)(*(_DWORD *)(this + 24) + 1) )
        return 1;
      sub_4315F0();
      result = 1;
      break;
    default:
      return 0;
  }
  return result;
}
