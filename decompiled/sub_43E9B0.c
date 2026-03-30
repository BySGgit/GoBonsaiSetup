int __thiscall sub_43E9B0(int *this, int a2)
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
    case 0:
      v6 = L"D3D10_DRIVER_TYPE_HARDWARE";
      break;
    case 1:
      v6 = L"D3D10_DRIVER_TYPE_REFERENCE";
      break;
    case 2:
      v6 = L"D3D10_DRIVER_TYPE_NULL";
      break;
    case 3:
      v6 = L"D3D10_DRIVER_TYPE_SOFTWARE";
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
      case 0:
        result = sub_434240((int)L"D3D10_DRIVER_TYPE_HARDWARE", v5, a2);
        break;
      case 1:
        result = sub_434240((int)L"D3D10_DRIVER_TYPE_REFERENCE", v5, a2);
        break;
      case 2:
        result = sub_434240((int)L"D3D10_DRIVER_TYPE_NULL", v5, a2);
        break;
      case 3:
        result = sub_434240((int)L"D3D10_DRIVER_TYPE_SOFTWARE", v5, a2);
        break;
      default:
        result = sub_434240((int)L"Unknown devType", v5, a2);
        break;
    }
  }
  return result;
}
