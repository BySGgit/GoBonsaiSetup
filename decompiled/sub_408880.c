int __usercall sub_408880@<eax>(float *a1@<esi>)
{
  int v1; // eax
  int v2; // eax
  int result; // eax
  float v4; // [esp+8h] [ebp-10h]
  float v5; // [esp+8h] [ebp-10h]
  float v6; // [esp+Ch] [ebp-Ch]
  float v7; // [esp+10h] [ebp-8h]
  float v8; // [esp+10h] [ebp-8h]

  a1[51] = ((double)rand() / 32767.0 * 0.699999988079071 + 0.800000011920929) * 9.0;
  a1[52] = ((double)rand() / 32767.0 * 0.4000000357627869 + 0.800000011920929) * 5.0;
  v4 = (double)rand() / 32767.0 * 4.0 - 2.0;
  v1 = rand();
  a1[56] = v4;
  a1[57] = 0.0;
  v7 = (double)v1 / 32767.0 * 4.0 - 2.0;
  a1[58] = v7;
  v5 = (double)rand() / 32767.0 + 0.0;
  v6 = (double)rand() / 32767.0 + 0.0;
  v2 = rand();
  a1[63] = v5;
  a1[59] = v5;
  a1[64] = v6;
  a1[60] = v6;
  v8 = (double)v2 / 32767.0 + 0.0;
  a1[65] = v8;
  a1[61] = v8;
  a1[66] = 1.0;
  a1[62] = 1.0;
  a1[68] = (double)rand() / 32767.0;
  result = rand();
  a1[67] = (double)result / 32767.0 * 0.800000011920929 + 0.2000000029802322;
  flt_4D7E88 = a1[51];
  return result;
}
