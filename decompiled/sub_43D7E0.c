int __thiscall sub_43D7E0(int *this, int a2)
{
  int v2; // esi
  int v3; // eax
  int v4; // edx
  _DWORD *v5; // esi
  const unsigned __int16 *v6; // eax
  int result; // eax

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
    while ( *(_DWORD *)(*(_DWORD *)v4 + 44) != 27 || *(_DWORD *)(*(_DWORD *)v4 + 48) != 4 )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
    v5 = *(_DWORD **)v4;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
      v6 = L"Direct3D 10";
    else
      v6 = L"Unknown version";
  }
  else
  {
    v6 = L"Direct3D 9";
  }
  result = sub_434450(v5, v6);
  if ( result == -1 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
        return sub_434240((int)L"Direct3D 10", v5, 1);
      else
        return sub_434240((int)L"Unknown version", v5, a2);
    }
    else
    {
      return sub_434240((int)L"Direct3D 9", v5, 0);
    }
  }
  return result;
}
