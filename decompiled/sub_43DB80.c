int __thiscall sub_43DB80(int *this, int a2)
{
  int v2; // esi
  int v3; // eax
  int v4; // edx
  _DWORD *v5; // esi
  const unsigned __int16 *v6; // eax
  int result; // eax
  const wchar_t *v8; // eax

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
    while ( *(_DWORD *)(*(_DWORD *)v4 + 44) != 7 || *(_DWORD *)(*(_DWORD *)v4 + 48) != 4 )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
    v5 = *(_DWORD **)v4;
  }
  v6 = sub_437720(a2, 1);
  result = sub_434450(v5, v6);
  if ( result == -1 )
  {
    v8 = sub_437720(a2, 1);
    return sub_434240((int)v8, v5, a2);
  }
  return result;
}
