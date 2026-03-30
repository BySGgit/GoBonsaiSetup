float *__userpurge sub_407B90@<eax>(float *result@<eax>, float *a2@<ecx>, float *a3)
{
  *result = *a3 - *a2;
  result[1] = a3[1] - a2[1];
  return result;
}
