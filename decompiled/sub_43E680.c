int __userpurge sub_43E680@<eax>(int a1@<eax>, int a2)
{
  int v2; // esi
  int v3; // ecx
  int v4; // edx
  _DWORD *v5; // edi
  const unsigned __int16 *v6; // eax
  int result; // eax

  v2 = *(_DWORD *)(a1 + 628);
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_6:
    v5 = 0;
  }
  else
  {
    v4 = *(_DWORD *)(a1 + 624);
    while ( *(_DWORD *)(*(_DWORD *)v4 + 44) != 21 || *(_DWORD *)(*(_DWORD *)v4 + 48) != 4 )
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
    case 16:
      v6 = L"Pure hardware vertex processing";
      break;
    case 32:
      v6 = L"Software vertex processing";
      break;
    case 64:
      v6 = L"Hardware vertex processing";
      break;
    case 128:
      v6 = L"Mixed vertex processing";
      break;
    default:
      v6 = L"Unknown vertex processing type";
      break;
  }
  result = sub_434450(v5, v6);
  if ( result == -1 )
  {
    switch ( a2 )
    {
      case 16:
        result = sub_434240((int)L"Pure hardware vertex processing", v5, a2);
        break;
      case 32:
        result = sub_434240((int)L"Software vertex processing", v5, a2);
        break;
      case 64:
        result = sub_434240((int)L"Hardware vertex processing", v5, a2);
        break;
      case 128:
        result = sub_434240((int)L"Mixed vertex processing", v5, a2);
        break;
      default:
        result = sub_434240((int)L"Unknown vertex processing type", v5, a2);
        break;
    }
  }
  return result;
}
