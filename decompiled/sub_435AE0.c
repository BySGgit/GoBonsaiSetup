bool __thiscall sub_435AE0(int this, int a2, int a3, int a4)
{
  char v5; // bl
  bool result; // al
  int v7; // eax
  int v8; // eax
  void (__stdcall *v9)(int, _DWORD, int, _DWORD); // ecx
  SHORT (__stdcall *v10)(int); // ebx
  int *v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // ecx

  if ( !*(_BYTE *)(this + 60) || !*(_BYTE *)(this + 4) )
    return 0;
  v5 = 0;
  if ( a2 != 256 )
    return v5;
  switch ( a3 )
  {
    case 9:
      return v5;
    case 35:
      v7 = lstrlenW(*(LPCWSTR *)(this + 80));
      sub_435650(v7, (_DWORD *)this);
      if ( GetKeyState(16) >= 0 )
        goto LABEL_6;
      goto LABEL_31;
    case 36:
      sub_435650(0, (_DWORD *)this);
      if ( GetKeyState(16) < 0 )
        goto LABEL_31;
LABEL_6:
      *(_DWORD *)(this + 300) = *(_DWORD *)(this + 292);
      sub_4370C0(this);
      return 1;
    case 37:
      v10 = GetKeyState;
      v11 = (int *)(this + 292);
      if ( GetKeyState(17) < 0 )
      {
        sub_436F60(this + 80, *v11, (int *)(this + 292));
        v12 = *v11;
        goto LABEL_28;
      }
      if ( *v11 <= 0 )
        goto LABEL_29;
      v12 = *v11 - 1;
      goto LABEL_28;
    case 38:
    case 40:
      goto LABEL_32;
    case 39:
      v10 = GetKeyState;
      if ( GetKeyState(17) >= 0 )
      {
        v13 = lstrlenW(*(LPCWSTR *)(this + 80));
        v14 = *(_DWORD *)(this + 292);
        v11 = (int *)(this + 292);
        if ( v14 >= v13 )
          goto LABEL_29;
        v12 = v14 + 1;
      }
      else
      {
        v11 = (int *)(this + 292);
        sub_436FF0(this + 80, *(_DWORD *)(this + 292), (int *)(this + 292));
        v12 = *(_DWORD *)(this + 292);
      }
LABEL_28:
      sub_435650(v12, (_DWORD *)this);
LABEL_29:
      if ( v10(16) >= 0 )
        *(_DWORD *)(this + 300) = *v11;
      goto LABEL_31;
    case 45:
      if ( GetKeyState(17) >= 0 )
      {
        if ( GetKeyState(16) >= 0 )
          *(_BYTE *)(this + 296) = *(_BYTE *)(this + 296) == 0;
        else
          sub_435A60((_DWORD *)this);
        return 0;
      }
      else
      {
        sub_4359A0(this);
        return 0;
      }
    case 46:
      if ( *(_DWORD *)(this + 292) == *(_DWORD *)(this + 300) )
      {
        if ( !sub_436C80(this + 80, *(_DWORD *)(this + 292)) )
          goto LABEL_31;
      }
      else
      {
        sub_4357D0(this);
      }
      v8 = *(_DWORD *)(this + 24);
      v9 = *(void (__stdcall **)(int, _DWORD, int, _DWORD))(v8 + 576);
      if ( v9 )
      {
        v9(1538, *(_DWORD *)(this + 44), this, *(_DWORD *)(v8 + 580));
        sub_4370C0(this);
        return 1;
      }
LABEL_31:
      sub_4370C0(this);
LABEL_32:
      result = 1;
      break;
    default:
      return a3 != 27;
  }
  return result;
}
