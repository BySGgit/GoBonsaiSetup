float *__usercall sub_408470@<eax>(float *result@<eax>, float *a2@<edi>)
{
  float *v2; // esi
  float v3; // [esp+8h] [ebp-4h]
  float v4; // [esp+8h] [ebp-4h]

  v2 = result;
  v3 = a2[1] * a2[1] + *a2 * *a2 + a2[2] * a2[2];
  v4 = sqrt(v3);
  if ( v4 <= 1.000000013351432e-10 )
  {
    *result = 0.0;
    result[1] = 0.0;
    result[2] = 1.0;
  }
  else
  {
    sub_408450(a2, result, v4);
    return v2;
  }
  return result;
}
