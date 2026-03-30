const wchar_t *__usercall sub_43EE70@<eax>(int a1@<eax>)
{
  const wchar_t *result; // eax

  switch ( a1 )
  {
    case 0:
      result = L"D3DMULTISAMPLE_NONE";
      break;
    case 1:
      result = L"D3DMULTISAMPLE_NONMASKABLE";
      break;
    case 2:
      result = L"D3DMULTISAMPLE_2_SAMPLES";
      break;
    case 3:
      result = L"D3DMULTISAMPLE_3_SAMPLES";
      break;
    case 4:
      result = L"D3DMULTISAMPLE_4_SAMPLES";
      break;
    case 5:
      result = L"D3DMULTISAMPLE_5_SAMPLES";
      break;
    case 6:
      result = L"D3DMULTISAMPLE_6_SAMPLES";
      break;
    case 7:
      result = L"D3DMULTISAMPLE_7_SAMPLES";
      break;
    case 8:
      result = L"D3DMULTISAMPLE_8_SAMPLES";
      break;
    case 9:
      result = L"D3DMULTISAMPLE_9_SAMPLES";
      break;
    case 10:
      result = L"D3DMULTISAMPLE_10_SAMPLES";
      break;
    case 11:
      result = L"D3DMULTISAMPLE_11_SAMPLES";
      break;
    case 12:
      result = L"D3DMULTISAMPLE_12_SAMPLES";
      break;
    case 13:
      result = L"D3DMULTISAMPLE_13_SAMPLES";
      break;
    case 14:
      result = L"D3DMULTISAMPLE_14_SAMPLES";
      break;
    case 15:
      result = L"D3DMULTISAMPLE_15_SAMPLES";
      break;
    case 16:
      result = L"D3DMULTISAMPLE_16_SAMPLES";
      break;
    default:
      result = L"Unknown Multisample Type";
      break;
  }
  return result;
}
