char __usercall sub_408060@<al>(int a1@<eax>, int a2@<ecx>)
{
  int v2; // eax

  switch ( a2 )
  {
    case 513:
      LOBYTE(word_4D8C9A) = 1;
      break;
    case 514:
      LOBYTE(word_4D8C9A) = 0;
      break;
    case 515:
      byte_4D8C9D = 1;
      break;
    case 516:
      LOBYTE(word_4D8CA3) = 1;
      break;
    case 517:
      LOBYTE(word_4D8CA3) = 0;
      break;
    case 518:
      byte_4D8CA6 = 1;
      break;
    case 519:
      LOBYTE(word_4D8C9E) = 1;
      byte_4D8CA2 = 1;
      LOBYTE(v2) = 1;
      break;
    case 520:
      LOBYTE(word_4D8C9E) = 0;
      break;
    case 521:
      byte_4D8CA1 = 1;
      break;
    case 522:
      v2 = SHIWORD(a1) / 120;
      flt_4D8CA8 = (double)v2 + flt_4D8CA8;
      break;
    default:
      return v2;
  }
  return v2;
}
