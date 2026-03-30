int __usercall sub_4387B0@<eax>(int a1@<eax>)
{
  int result; // eax

  switch ( a1 )
  {
    case 20:
    case 21:
    case 22:
    case 26:
    case 27:
    case 29:
    case 30:
      result = 28;
      break;
    case 23:
      result = 85;
      break;
    case 24:
    case 25:
      result = 86;
      break;
    case 28:
      result = 65;
      break;
    case 31:
    case 35:
      result = 24;
      break;
    case 32:
    case 33:
      result = 87;
      break;
    case 34:
      result = 35;
      break;
    case 36:
      result = 11;
      break;
    case 111:
      result = 54;
      break;
    case 112:
      result = 34;
      break;
    case 113:
      result = 10;
      break;
    case 114:
      result = 41;
      break;
    case 115:
      result = 16;
      break;
    case 116:
      result = 2;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
