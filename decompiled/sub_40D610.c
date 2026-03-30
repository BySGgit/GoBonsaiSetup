float *__usercall sub_40D610@<eax>(float *a1@<esi>)
{
  int v1; // eax
  float v3; // [esp+0h] [ebp-10h]
  float v4; // [esp+4h] [ebp-Ch]
  float v5; // [esp+4h] [ebp-Ch]
  float v6; // [esp+8h] [ebp-8h]
  float v7; // [esp+Ch] [ebp-4h]
  float v8; // [esp+Ch] [ebp-4h]

  v1 = rand();
  v6 = (double)v1 / 32767.0 + (double)v1 / 32767.0 - 1.0;
  v3 = (double)rand() / 32767.0 * 6.283185482025146 + 0.0;
  v4 = 1.0 - v6 * v6;
  v5 = sqrt(v4);
  v7 = cos(v3);
  *a1 = v7 * v5;
  v8 = sin(v3);
  a1[1] = v8 * v5;
  a1[2] = v6;
  return a1;
}
