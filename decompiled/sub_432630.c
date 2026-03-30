int __thiscall sub_432630(int this)
{
  int result; // eax
  int v2; // esi
  unsigned int v3; // edx
  double v4; // st6
  unsigned int v5; // edx
  float v6; // [esp+10h] [ebp-20h]
  float v7; // [esp+14h] [ebp-1Ch]
  float v8; // [esp+18h] [ebp-18h]
  float v9; // [esp+1Ch] [ebp-14h]
  float v10; // [esp+20h] [ebp-10h]
  float v11; // [esp+24h] [ebp-Ch]
  float v12; // [esp+28h] [ebp-8h]
  float v13; // [esp+2Ch] [ebp-4h]

  result = 0;
  v2 = 0;
  for ( *(_WORD *)(this + 5) = 0; v2 < *(_DWORD *)(this + 36); *(float *)(result + 104) = v13 )
  {
    result = *(_DWORD *)(*(_DWORD *)(this + 32) + 4 * v2);
    v3 = *(_DWORD *)(result + 36);
    v6 = (double)BYTE2(v3) * 0.003921568859368563;
    ++v2;
    v7 = (double)BYTE1(v3) * 0.003921568859368563;
    *(float *)(result + 52) = v6;
    *(float *)(result + 56) = v7;
    v8 = (double)(unsigned __int8)v3 * 0.003921568859368563;
    v4 = (double)HIBYTE(v3);
    *(float *)(result + 60) = v8;
    v5 = *(_DWORD *)(result + 76);
    v9 = v4 * 0.003921568859368563;
    *(float *)(result + 64) = v9;
    v10 = (double)BYTE2(v5) * 0.003921568859368563;
    v11 = (double)BYTE1(v5) * 0.003921568859368563;
    *(float *)(result + 92) = v10;
    *(float *)(result + 96) = v11;
    v12 = (double)(unsigned __int8)v5 * 0.003921568859368563;
    *(float *)(result + 100) = v12;
    v13 = (double)HIBYTE(v5) * 0.003921568859368563;
  }
  return result;
}
