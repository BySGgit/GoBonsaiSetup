void *__userpurge sub_415AB0@<eax>(int a1@<esi>, float a2)
{
  void *v2; // eax
  void *result; // eax
  float v4; // [esp+14h] [ebp-58h]
  float v5; // [esp+14h] [ebp-58h]
  int v6[18]; // [esp+18h] [ebp-54h] BYREF
  int v7; // [esp+68h] [ebp-4h]

  v4 = ((double)rand() / 32767.0 * 0.2000000476837158 + 0.8999999761581421) * 1.570796370506287 + *(float *)(a1 + 512);
  *(float *)(a1 + 512) = v4;
  if ( v4 > 6.283185482025146 )
    *(float *)(a1 + 512) = v4 - 6.283185482025146;
  sub_4158D0(v6, 0.0, 1.0, *(float *)(a1 + 512));
  v2 = operator new(0x220u);
  v7 = 0;
  if ( v2 )
    sub_4163B0(*(void **)(a1 + 180), (int)v2, a2, v6);
  v7 = -1;
  v5 = *(float *)(a1 + 512) + 3.141592741012573;
  sub_4158D0(v6, 0.0, 1.0, v5);
  result = operator new(0x220u);
  v7 = 1;
  if ( result )
    result = (void *)sub_4163B0(*(void **)(a1 + 180), (int)result, a2, v6);
  ++*(_DWORD *)(a1 + 516);
  return result;
}
