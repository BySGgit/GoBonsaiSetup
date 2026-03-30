int __thiscall sub_43DDC0(int *this, int Args, int a3)
{
  int v3; // edx
  int v4; // eax
  int v5; // esi
  _DWORD *v6; // esi
  int result; // eax
  wchar_t Buffer[50]; // [esp+Ch] [ebp-68h] BYREF

  v3 = *(this + 157);
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_6:
    v6 = 0;
  }
  else
  {
    v5 = *(this + 156);
    while ( *(_DWORD *)(*(_DWORD *)v5 + 44) != 30 || *(_DWORD *)(*(_DWORD *)v5 + 48) != 4 )
    {
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        goto LABEL_6;
    }
    v6 = *(_DWORD **)v5;
  }
  sub_419310(Buffer, (wchar_t *)L"%d by %d", Args, a3);
  result = sub_434450(v6, Buffer);
  if ( result == -1 )
    return sub_434240((int)Buffer, v6, (unsigned __int16)Args | ((unsigned __int16)a3 << 16));
  return result;
}
