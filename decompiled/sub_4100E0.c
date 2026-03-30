int __stdcall sub_4100E0(int a1)
{
  int v1; // edi
  int v2; // ebx
  int v4; // [esp+14h] [ebp-1Ch]
  float v5; // [esp+18h] [ebp-18h]
  float v6; // [esp+20h] [ebp-10h]

  sub_401830(a1);
  v1 = a1 + 196;
  *(_DWORD *)a1 = &Sky::`vftable';
  `eh vector constructor iterator'((void *)(a1 + 196), 0xF0u, 10, sub_410280, sub_4102A0);
  *(float *)(a1 + 2608) = 0.0;
  *(_DWORD *)(a1 + 4) = 2;
  *(float *)(a1 + 2612) = 0.0;
  v5 = -((double)rand() / 32767.0 * 0.199999988079071 + 0.5);
  v4 = rand();
  *(float *)(a1 + 2596) = v5;
  *(float *)(a1 + 2600) = 1.0;
  v6 = (double)v4 / 32767.0 * 1.399999976158142 - 0.699999988079071;
  *(float *)(a1 + 2604) = v6;
  D3DXVec3Normalize(a1 + 2596, a1 + 2596);
  v2 = 10;
  do
  {
    sub_4102C0(v1, 1);
    v1 += 240;
    --v2;
  }
  while ( v2 );
  return a1;
}
