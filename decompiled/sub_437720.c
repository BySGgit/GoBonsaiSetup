const wchar_t *__userpurge sub_437720@<eax>(int a1@<eax>, char a2)
{
  const wchar_t *v2; // esi

  if ( a1 > 827606349 )
  {
    if ( a1 > 861165636 )
    {
      switch ( a1 )
      {
        case 877942852:
          v2 = L"D3DFMT_DXT4";
          goto LABEL_69;
        case 894720068:
          v2 = L"D3DFMT_DXT5";
          goto LABEL_69;
        case 1498831189:
          v2 = L"D3DFMT_UYVY";
          goto LABEL_69;
      }
    }
    else
    {
      switch ( a1 )
      {
        case 861165636:
          v2 = L"D3DFMT_DXT3";
          goto LABEL_69;
        case 827611204:
          v2 = L"D3DFMT_DXT1";
          goto LABEL_69;
        case 844388420:
          v2 = L"D3DFMT_DXT2";
          goto LABEL_69;
        case 844715353:
          v2 = L"D3DFMT_YUY2";
          goto LABEL_69;
      }
    }
LABEL_65:
    v2 = L"Unknown format";
    goto LABEL_69;
  }
  if ( a1 == 827606349 )
  {
    v2 = L"D3DFMT_MULTI2_ARGB8";
  }
  else
  {
    switch ( a1 )
    {
      case 0:
        v2 = L"D3DFMT_UNKNOWN";
        break;
      case 20:
        v2 = L"D3DFMT_R8G8B8";
        break;
      case 21:
        v2 = L"D3DFMT_A8R8G8B8";
        break;
      case 22:
        v2 = L"D3DFMT_X8R8G8B8";
        break;
      case 23:
        v2 = L"D3DFMT_R5G6B5";
        break;
      case 24:
        v2 = L"D3DFMT_X1R5G5B5";
        break;
      case 25:
        v2 = L"D3DFMT_A1R5G5B5";
        break;
      case 26:
        v2 = L"D3DFMT_A4R4G4B4";
        break;
      case 27:
        v2 = L"D3DFMT_R3G3B2";
        break;
      case 28:
        v2 = L"D3DFMT_A8";
        break;
      case 29:
        v2 = L"D3DFMT_A8R3G3B2";
        break;
      case 30:
        v2 = L"D3DFMT_X4R4G4B4";
        break;
      case 31:
        v2 = L"D3DFMT_A2B10G10R10";
        break;
      case 32:
        v2 = L"D3DFMT_A8B8G8R8";
        break;
      case 33:
        v2 = L"D3DFMT_X8B8G8R8";
        break;
      case 34:
        v2 = L"D3DFMT_G16R16";
        break;
      case 35:
        v2 = L"D3DFMT_A2R10G10B10";
        break;
      case 36:
        v2 = L"D3DFMT_A16B16G16R16";
        break;
      case 40:
        v2 = L"D3DFMT_A8P8";
        break;
      case 41:
        v2 = L"D3DFMT_P8";
        break;
      case 50:
        v2 = L"D3DFMT_L8";
        break;
      case 51:
        v2 = L"D3DFMT_A8L8";
        break;
      case 52:
        v2 = L"D3DFMT_A4L4";
        break;
      case 60:
        v2 = L"D3DFMT_V8U8";
        break;
      case 61:
        v2 = L"D3DFMT_L6V5U5";
        break;
      case 62:
        v2 = L"D3DFMT_X8L8V8U8";
        break;
      case 63:
        v2 = L"D3DFMT_Q8W8V8U8";
        break;
      case 64:
        v2 = L"D3DFMT_V16U16";
        break;
      case 67:
        v2 = L"D3DFMT_A2W10V10U10";
        break;
      case 70:
        v2 = L"D3DFMT_D16_LOCKABLE";
        break;
      case 71:
        v2 = L"D3DFMT_D32";
        break;
      case 73:
        v2 = L"D3DFMT_D15S1";
        break;
      case 75:
        v2 = L"D3DFMT_D24S8";
        break;
      case 77:
        v2 = L"D3DFMT_D24X8";
        break;
      case 79:
        v2 = L"D3DFMT_D24X4S4";
        break;
      case 80:
        v2 = L"D3DFMT_D16";
        break;
      case 81:
        v2 = L"D3DFMT_L16";
        break;
      case 100:
        v2 = L"D3DFMT_VERTEXDATA";
        break;
      case 101:
        v2 = L"D3DFMT_INDEX16";
        break;
      case 102:
        v2 = L"D3DFMT_INDEX32";
        break;
      case 110:
        v2 = L"D3DFMT_Q16W16V16U16";
        break;
      case 111:
        v2 = L"D3DFMT_R16F";
        break;
      case 112:
        v2 = L"D3DFMT_G16R16F";
        break;
      case 113:
        v2 = L"D3DFMT_A16B16G16R16F";
        break;
      case 114:
        v2 = L"D3DFMT_R32F";
        break;
      case 115:
        v2 = L"D3DFMT_G32R32F";
        break;
      case 116:
        v2 = L"D3DFMT_A32B32G32R32F";
        break;
      case 117:
        v2 = L"D3DFMT_CxV8U8";
        break;
      default:
        goto LABEL_65;
    }
  }
LABEL_69:
  if ( a2 || !wcsstr(v2, L"D3DFMT_") )
    return v2;
  else
    return &v2[lstrlenW(L"D3DFMT_")];
}
