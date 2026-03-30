float *__userpurge sub_4014B0@<eax>(float *result@<eax>, float *a2@<ecx>, float a3)
{
  double v3; // st7
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+4h] [ebp-8h]
  float v6; // [esp+8h] [ebp-4h]
  float v7; // [esp+10h] [ebp+4h]

  v7 = 1.0 / a3;
  v4 = *a2 * v7;
  v5 = a2[1] * v7;
  v3 = v7 * a2[2];
  *result = v4;
  result[1] = v5;
  v6 = v3;
  result[2] = v6;
  return result;
}
