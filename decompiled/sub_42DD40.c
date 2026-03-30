float *__usercall sub_42DD40@<eax>(float *result@<eax>, unsigned int a2@<ecx>)
{
  *result = (double)BYTE2(a2) / 255.0;
  result[1] = (double)BYTE1(a2) / 255.0;
  result[2] = (double)(unsigned __int8)a2 / 255.0;
  result[3] = (double)HIBYTE(a2) / 255.0;
  return result;
}
