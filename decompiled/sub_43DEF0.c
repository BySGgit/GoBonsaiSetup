int __fastcall sub_43DEF0(int a1, int a2, int Args)
{
  int v3; // ecx
  int v4; // eax
  int v5; // esi
  _DWORD *v6; // edi
  wchar_t *v7; // eax
  int v8; // edx
  wchar_t v9; // cx
  int result; // eax
  wchar_t Buffer[50]; // [esp+Ch] [ebp-68h] BYREF

  v3 = *(_DWORD *)(a2 + 628);
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_6:
    v6 = 0;
  }
  else
  {
    v5 = *(_DWORD *)(a2 + 624);
    while ( *(_DWORD *)(*(_DWORD *)v5 + 44) != 11 || *(_DWORD *)(*(_DWORD *)v5 + 48) != 4 )
    {
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        goto LABEL_6;
    }
    v6 = *(_DWORD **)v5;
  }
  v7 = Buffer;
  if ( Args )
  {
    sub_419310(Buffer, (wchar_t *)L"%d Hz", Args);
  }
  else
  {
    v8 = 50;
    while ( v8 != -2147483596 )
    {
      v9 = *(wchar_t *)((char *)v7 + (char *)L"Default Rate" - (char *)Buffer);
      if ( !v9 )
        break;
      *v7++ = v9;
      if ( !--v8 )
      {
        *(v7 - 1) = 0;
        goto LABEL_16;
      }
    }
    *v7 = 0;
  }
LABEL_16:
  result = sub_434450(v6, Buffer);
  if ( result == -1 )
    return sub_434240((int)Buffer, v6, Args);
  return result;
}
