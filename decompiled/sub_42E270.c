int __fastcall sub_42E270(int a1, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  int v5; // eax
  int result; // eax
  int v7; // esi
  int v8; // eax

  v3 = 0;
  dword_4D8C74 = a3;
  if ( dword_4D8C8C <= 0 )
  {
LABEL_6:
    v7 = 0;
    if ( dword_4D8C80 <= 0 )
    {
LABEL_9:
      v8 = D3DXCreateSprite(a3, &dword_4D8C3C);
      return v8 >= 0 ? 0 : v8;
    }
    else
    {
      while ( 1 )
      {
        result = sub_431860(v7, a2, (int)&dword_4D8C38);
        if ( result < 0 )
          break;
        if ( ++v7 >= dword_4D8C80 )
          goto LABEL_9;
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v4 = *(_DWORD **)(dword_4D8C88 + 4 * v3);
      v5 = v4[132];
      if ( v5 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(v4[132]);
        v4[132] = 0;
      }
      result = D3DXCreateFontW(dword_4D8C74, v4[130], 0, v4[131], 1, 0, 1, 0, 0, 0, v4, v4 + 132);
      if ( result < 0 )
        break;
      if ( ++v3 >= dword_4D8C8C )
        goto LABEL_6;
    }
  }
  return result;
}
