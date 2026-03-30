float *__usercall sub_401590@<eax>(float *result@<eax>, float *a2@<ecx>)
{
  *result = *a2;
  result[1] = a2[1];
  result[2] = a2[2];
  return result;
}
