float *__userpurge sub_401120@<eax>(float *result@<eax>, float *a2@<ecx>, float *a3)
{
  double v3; // st7
  double v4; // st6
  float v5; // [esp+0h] [ebp-Ch]
  float v6; // [esp+4h] [ebp-8h]
  float v7; // [esp+8h] [ebp-4h]

  v5 = a2[2] * a3[1] - a2[1] * a3[2];
  v6 = *a2 * a3[2] - *a3 * a2[2];
  v3 = a2[1] * *a3;
  v4 = *a2 * a3[1];
  *result = v5;
  result[1] = v6;
  v7 = v3 - v4;
  result[2] = v7;
  return result;
}
