float *__usercall sub_401500@<eax>(float *result@<eax>, float *a2@<ecx>, float a3)
{
  double v3; // st7
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+4h] [ebp-8h]
  float v6; // [esp+8h] [ebp-4h]

  v4 = *a2 * a3;
  v5 = a2[1] * a3;
  v3 = a3 * a2[2];
  *result = v4;
  result[1] = v5;
  v6 = v3;
  result[2] = v6;
  return result;
}
