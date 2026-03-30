int __thiscall sub_43D980(int *this, int a2)
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
    while ( *(_DWORD *)(*(_DWORD *)v4 + 44) != 4 || *(_DWORD *)(*(_DWORD *)v4 + 48) != 4 )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
    v5 = *(_DWORD **)v4;
  }
  switch ( a2 )
  {
    case 1:
      v6 = L"D3DDEVTYPE_HAL";
      break;
    case 2:
      v6 = L"D3DDEVTYPE_REF";
      break;
    case 3:
      v6 = L"D3DDEVTYPE_SW";
      break;
    default:
      v6 = L"Unknown devType";
      break;
  }
  result = sub_434450(v5, v6);
  if ( result == -1 )
  {
    switch ( a2 )
    {
      case 1:
        return sub_434240((int)L"D3DDEVTYPE_HAL", v5, 1);
      case 2:
        return sub_434240((int)L"D3DDEVTYPE_REF", v5, 2);
      case 3:
        return sub_434240((int)L"D3DDEVTYPE_SW", v5, 3);
      default:
        return sub_434240((int)L"Unknown devType", v5, a2);
    }
  }
  return result;
}
