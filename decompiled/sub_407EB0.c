char *__thiscall sub_407EB0(char *this, char *a2)
{
  char v2; // bl
  char *v3; // edi
  char *result; // eax

  v2 = (char)a2;
  v3 = this;
  if ( (unsigned int)(this - 97) <= 0x19 )
    v3 = this - 32;
  if ( (_BYTE)a2 )
  {
    if ( (dword_4D8EC0 & 1) == 0 )
    {
      dword_4D8EC0 |= 1u;
      sub_43FD00();
      atexit(sub_472560);
    }
    a2 = v3;
    if ( (unsigned int)dword_4D8E3C < 0x100 )
      sub_408240((int)&dword_4D8E2C, &a2);
  }
  result = v3 - 17;
  switch ( (unsigned int)v3 )
  {
    case 0x11u:
      HIBYTE(word_4D8C98) = v2;
      break;
    case 0x20u:
      LOBYTE(word_4D8C98) = v2;
      break;
    case 0x41u:
      HIBYTE(dword_4D8C94) = v2;
      break;
    case 0x44u:
      BYTE2(dword_4D8C94) = v2;
      break;
    case 0x53u:
      BYTE1(dword_4D8C94) = v2;
      break;
    case 0x57u:
      LOBYTE(dword_4D8C94) = v2;
      break;
    default:
      return result;
  }
  return result;
}
