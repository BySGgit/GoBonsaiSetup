_DWORD *__usercall sub_446A10@<eax>(_DWORD *result@<eax>, int *a2@<ecx>)
{
  int v2; // edx
  int v3; // ecx

  v2 = a2[3];
  v3 = *a2;
  result[1] = 0;
  *result = v3;
  result[2] = v2;
  return result;
}
