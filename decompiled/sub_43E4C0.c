int __thiscall sub_43E4C0(int *this, int Args)
{
  int v2; // edx
  int v3; // eax
  int v4; // esi
  _DWORD *v5; // esi
  int result; // eax
  wchar_t Buffer[50]; // [esp+8h] [ebp-68h] BYREF

  v2 = *(this + 157);
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_6:
    v5 = 0;
  }
  else
  {
    v4 = *(this + 156);
    while ( *(_DWORD *)(*(_DWORD *)v4 + 44) != 36 || *(_DWORD *)(*(_DWORD *)v4 + 48) != 4 )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
    v5 = *(_DWORD **)v4;
  }
  sub_419310(Buffer, (wchar_t *)L"%u", Args);
  result = sub_434450(v5, Buffer);
  if ( result == -1 )
    return sub_434240((int)Buffer, v5, Args);
  return result;
}
