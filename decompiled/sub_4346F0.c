char __thiscall sub_4346F0(int this, int a2, int a3, int a4)
{
  char result; // al
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx

  if ( !*(_BYTE *)(this + 60) || !*(_BYTE *)(this + 4) || a2 != 256 )
    return 0;
  switch ( a3 )
  {
    case '!':
      v8 = (*(_DWORD *)(this + 88) - *(_DWORD *)(this + 84)) / 10;
      v9 = 10;
      if ( v8 >= 10 )
        v9 = (*(_DWORD *)(this + 88) - *(_DWORD *)(this + 84)) / 10;
      sub_434A20(v9 + *(_DWORD *)(this + 80), (_DWORD *)this, 1);
      result = 1;
      break;
    case '"':
      v6 = (*(_DWORD *)(this + 88) - *(_DWORD *)(this + 84)) / 10;
      v7 = 10;
      if ( v6 >= 10 )
        v7 = (*(_DWORD *)(this + 88) - *(_DWORD *)(this + 84)) / 10;
      sub_434A20(*(_DWORD *)(this + 80) - v7, (_DWORD *)this, 1);
      result = 1;
      break;
    case '#':
      sub_434A20(*(_DWORD *)(this + 88), (_DWORD *)this, 1);
      result = 1;
      break;
    case '$':
      sub_434A20(*(_DWORD *)(this + 84), (_DWORD *)this, 1);
      result = 1;
      break;
    case '%':
    case '(':
      sub_434A20(*(_DWORD *)(this + 80) - 1, (_DWORD *)this, 1);
      result = 1;
      break;
    case '&':
    case '\'':
      sub_434A20(*(_DWORD *)(this + 80) + 1, (_DWORD *)this, 1);
      result = 1;
      break;
    default:
      return 0;
  }
  return result;
}
