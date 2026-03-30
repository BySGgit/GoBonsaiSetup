const wchar_t *__userpurge sub_437B00@<eax>(int a1@<eax>, char a2)
{
  const wchar_t *v2; // esi

  switch ( a1 )
  {
    case 1:
      v2 = L"DXGI_FORMAT_R32G32B32A32_TYPELESS";
      break;
    case 2:
      v2 = L"DXGI_FORMAT_R32G32B32A32_FLOAT";
      break;
    case 3:
      v2 = L"DXGI_FORMAT_R32G32B32A32_UINT";
      break;
    case 4:
      v2 = L"DXGI_FORMAT_R32G32B32A32_SINT";
      break;
    case 5:
      v2 = L"DXGI_FORMAT_R32G32B32_TYPELESS";
      break;
    case 6:
      v2 = L"DXGI_FORMAT_R32G32B32_FLOAT";
      break;
    case 7:
      v2 = L"DXGI_FORMAT_R32G32B32_UINT";
      break;
    case 8:
      v2 = L"DXGI_FORMAT_R32G32B32_SINT";
      break;
    case 9:
      v2 = L"DXGI_FORMAT_R16G16B16A16_TYPELESS";
      break;
    case 10:
      v2 = L"DXGI_FORMAT_R16G16B16A16_FLOAT";
      break;
    case 11:
      v2 = L"DXGI_FORMAT_R16G16B16A16_UNORM";
      break;
    case 12:
      v2 = L"DXGI_FORMAT_R16G16B16A16_UINT";
      break;
    case 13:
      v2 = L"DXGI_FORMAT_R16G16B16A16_SNORM";
      break;
    case 14:
      v2 = L"DXGI_FORMAT_R16G16B16A16_SINT";
      break;
    case 15:
      v2 = L"DXGI_FORMAT_R32G32_TYPELESS";
      break;
    case 16:
      v2 = L"DXGI_FORMAT_R32G32_FLOAT";
      break;
    case 17:
      v2 = L"DXGI_FORMAT_R32G32_UINT";
      break;
    case 18:
      v2 = L"DXGI_FORMAT_R32G32_SINT";
      break;
    case 19:
      v2 = L"DXGI_FORMAT_R32G8X24_TYPELESS";
      break;
    case 20:
      v2 = L"DXGI_FORMAT_D32_FLOAT_S8X24_UINT";
      break;
    case 21:
      v2 = L"DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS";
      break;
    case 22:
      v2 = L"DXGI_FORMAT_X32_TYPELESS_G8X24_UINT";
      break;
    case 23:
      v2 = L"DXGI_FORMAT_R10G10B10A2_TYPELESS";
      break;
    case 24:
      v2 = L"DXGI_FORMAT_R10G10B10A2_UNORM";
      break;
    case 25:
      v2 = L"DXGI_FORMAT_R10G10B10A2_UINT";
      break;
    case 26:
      v2 = L"DXGI_FORMAT_R11G11B10_FLOAT";
      break;
    case 27:
      v2 = L"DXGI_FORMAT_R8G8B8A8_TYPELESS";
      break;
    case 28:
      v2 = L"DXGI_FORMAT_R8G8B8A8_UNORM";
      break;
    case 29:
      v2 = L"DXGI_FORMAT_R8G8B8A8_UNORM_SRGB";
      break;
    case 30:
      v2 = L"DXGI_FORMAT_R8G8B8A8_UINT";
      break;
    case 31:
      v2 = L"DXGI_FORMAT_R8G8B8A8_SNORM";
      break;
    case 32:
      v2 = L"DXGI_FORMAT_R8G8B8A8_SINT";
      break;
    case 33:
      v2 = L"DXGI_FORMAT_R16G16_TYPELESS";
      break;
    case 34:
      v2 = L"DXGI_FORMAT_R16G16_FLOAT";
      break;
    case 35:
      v2 = L"DXGI_FORMAT_R16G16_UNORM";
      break;
    case 36:
      v2 = L"DXGI_FORMAT_R16G16_UINT";
      break;
    case 37:
      v2 = L"DXGI_FORMAT_R16G16_SNORM";
      break;
    case 38:
      v2 = L"DXGI_FORMAT_R16G16_SINT";
      break;
    case 39:
      v2 = L"DXGI_FORMAT_R32_TYPELESS";
      break;
    case 40:
      v2 = L"DXGI_FORMAT_D32_FLOAT";
      break;
    case 41:
      v2 = L"DXGI_FORMAT_R32_FLOAT";
      break;
    case 42:
      v2 = L"DXGI_FORMAT_R32_UINT";
      break;
    case 43:
      v2 = L"DXGI_FORMAT_R32_SINT";
      break;
    case 44:
      v2 = L"DXGI_FORMAT_R24G8_TYPELESS";
      break;
    case 45:
      v2 = L"DXGI_FORMAT_D24_UNORM_S8_UINT";
      break;
    case 46:
      v2 = L"DXGI_FORMAT_R24_UNORM_X8_TYPELESS";
      break;
    case 47:
      v2 = L"DXGI_FORMAT_X24_TYPELESS_G8_UINT";
      break;
    case 48:
      v2 = L"DXGI_FORMAT_R8G8_TYPELESS";
      break;
    case 49:
      v2 = L"DXGI_FORMAT_R8G8_UNORM";
      break;
    case 50:
      v2 = L"DXGI_FORMAT_R8G8_UINT";
      break;
    case 51:
      v2 = L"DXGI_FORMAT_R8G8_SNORM";
      break;
    case 52:
      v2 = L"DXGI_FORMAT_R8G8_SINT";
      break;
    case 53:
      v2 = L"DXGI_FORMAT_R16_TYPELESS";
      break;
    case 54:
      v2 = L"DXGI_FORMAT_R16_FLOAT";
      break;
    case 55:
      v2 = L"DXGI_FORMAT_D16_UNORM";
      break;
    case 56:
      v2 = L"DXGI_FORMAT_R16_UNORM";
      break;
    case 57:
      v2 = L"DXGI_FORMAT_R16_UINT";
      break;
    case 58:
      v2 = L"DXGI_FORMAT_R16_SNORM";
      break;
    case 59:
      v2 = L"DXGI_FORMAT_R16_SINT";
      break;
    case 60:
      v2 = L"DXGI_FORMAT_R8_TYPELESS";
      break;
    case 61:
      v2 = L"DXGI_FORMAT_R8_UNORM";
      break;
    case 62:
      v2 = L"DXGI_FORMAT_R8_UINT";
      break;
    case 63:
      v2 = L"DXGI_FORMAT_R8_SNORM";
      break;
    case 64:
      v2 = L"DXGI_FORMAT_R8_SINT";
      break;
    case 65:
      v2 = L"DXGI_FORMAT_A8_UNORM";
      break;
    case 66:
      v2 = L"DXGI_FORMAT_R1_UNORM";
      break;
    case 67:
      v2 = L"DXGI_FORMAT_R9G9B9E5_SHAREDEXP";
      break;
    case 68:
      v2 = L"DXGI_FORMAT_R8G8_B8G8_UNORM";
      break;
    case 69:
      v2 = L"DXGI_FORMAT_G8R8_G8B8_UNORM";
      break;
    case 70:
      v2 = L"DXGI_FORMAT_BC1_TYPELESS";
      break;
    case 71:
      v2 = L"DXGI_FORMAT_BC1_UNORM";
      break;
    case 72:
      v2 = L"DXGI_FORMAT_BC1_UNORM_SRGB";
      break;
    case 73:
      v2 = L"DXGI_FORMAT_BC2_TYPELESS";
      break;
    case 74:
      v2 = L"DXGI_FORMAT_BC2_UNORM";
      break;
    case 75:
      v2 = L"DXGI_FORMAT_BC2_UNORM_SRGB";
      break;
    case 76:
      v2 = L"DXGI_FORMAT_BC3_TYPELESS";
      break;
    case 77:
      v2 = L"DXGI_FORMAT_BC3_UNORM";
      break;
    case 78:
      v2 = L"DXGI_FORMAT_BC3_UNORM_SRGB";
      break;
    case 79:
      v2 = L"DXGI_FORMAT_BC4_TYPELESS";
      break;
    case 80:
      v2 = L"DXGI_FORMAT_BC4_UNORM";
      break;
    case 81:
      v2 = L"DXGI_FORMAT_BC4_SNORM";
      break;
    case 82:
      v2 = L"DXGI_FORMAT_BC5_TYPELESS";
      break;
    case 83:
      v2 = L"DXGI_FORMAT_BC5_UNORM";
      break;
    case 84:
      v2 = L"DXGI_FORMAT_BC5_SNORM";
      break;
    case 85:
      v2 = L"DXGI_FORMAT_B5G6R5_UNORM";
      break;
    case 86:
      v2 = L"DXGI_FORMAT_B5G5R5A1_UNORM";
      break;
    case 87:
      v2 = L"DXGI_FORMAT_B8G8R8A8_UNORM";
      break;
    default:
      v2 = L"Unknown format";
      break;
  }
  if ( a2 || !wcsstr(v2, L"DXGI_FORMAT_") )
    return v2;
  else
    return &v2[lstrlenW(L"DXGI_FORMAT_")];
}
