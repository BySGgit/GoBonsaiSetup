float *__usercall sub_401000@<eax>(float *a1@<esi>)
{
  float *result; // eax
  float v2; // [esp+0h] [ebp-4h]

  v2 = *a1 - (double)(int)(*a1 / 6.283185482025146) * 6.283185482025146;
  *a1 = v2;
  if ( v2 < 0.0 )
    *a1 = v2 + 6.283185482025146;
  result = a1;
  if ( *a1 > 3.141592741012573 )
    *a1 = *a1 - 6.283185482025146;
  return result;
}
