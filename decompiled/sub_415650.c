char __stdcall sub_415650(int a1)
{
  int v2; // esi
  _DWORD *v3; // esi
  _DWORD *v4; // ebx
  int v5; // edi
  float *v6; // eax
  double v7; // st7
  float *v9; // [esp+8h] [ebp-30h]
  float v10; // [esp+8h] [ebp-30h]
  float v11; // [esp+Ch] [ebp-2Ch]
  _DWORD *v12; // [esp+10h] [ebp-28h]
  float v13[3]; // [esp+14h] [ebp-24h] BYREF
  float v14[3]; // [esp+20h] [ebp-18h] BYREF
  float v15[3]; // [esp+2Ch] [ebp-Ch] BYREF
  float v16; // [esp+3Ch] [ebp+4h]
  float i; // [esp+3Ch] [ebp+4h]

  v2 = *(_DWORD *)(a1 + 180);
  if ( 0.0 == *(float *)(a1 + 456) )
    return 0;
  v16 = *(float *)(dword_4D7EE8 + 216) / 365.0;
  if ( (int)v16 - (int)((*(float *)(dword_4D7EE8 + 216) - *(float *)(v2 + 440)) / 365.0) <= 1 || sub_4155A0(v2) )
    return 0;
  if ( *(float *)(v2 + 444) <= 0.2000000029802322 || *(_DWORD *)(v2 + 172) != 1 )
  {
    v3 = *(_DWORD **)(v2 + 168);
    v4 = (_DWORD *)*v3;
    v12 = v3;
    v11 = *(float *)(a1 + 444) * 0.699999988079071;
    for ( i = *(float *)(a1 + 444) * 0.300000011920929; v4 != v3; v4 = (_DWORD *)*v4 )
    {
      v5 = v4[2];
      if ( v5 != a1 && 0.0 != *(float *)(v5 + 456) && i <= (double)*(float *)(v5 + 444) )
      {
        v9 = sub_40D6C0(v4[2], v14);
        v6 = sub_40D6C0(a1, v15);
        sub_401430(v13, v9, v6);
        v7 = sub_401080(v13);
        v10 = v11 + *(float *)(v5 + 444);
        if ( v10 > v7 )
          return 0;
        v3 = v12;
      }
    }
  }
  return 1;
}
