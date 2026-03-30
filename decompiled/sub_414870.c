void __usercall sub_414870(int a1@<edi>)
{
  double v1; // st7
  bool v2; // zf
  double v3; // st6
  _DWORD *v4; // eax
  _DWORD *v5; // ebp
  int v6; // ebx
  float *v7; // eax
  float v8; // [esp+14h] [ebp-28h]
  float v9; // [esp+14h] [ebp-28h]
  float v10; // [esp+14h] [ebp-28h]
  float v11[2]; // [esp+18h] [ebp-24h] BYREF
  float v12; // [esp+20h] [ebp-1Ch]
  float v13[6]; // [esp+24h] [ebp-18h] BYREF

  v8 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)a1 + 56))(a1) * *(float *)flt_4D85FC;
  *(float *)(a1 + 464) = v8;
  *(float *)(a1 + 460) = v8;
  if ( (dword_4D8DA0 & 1) == 0 )
  {
    dword_4D8DA0 |= 1u;
    v13[5] = 0.0;
    sub_415800();
  }
  v1 = 0.0;
  if ( byte_4D8226[11 * *(_DWORD *)(a1 + 4)] )
  {
    *(float *)(a1 + 464) = 0.0;
    *(float *)(a1 + 460) = 0.0;
  }
  v2 = *(_DWORD *)(a1 + 172) == 0;
  v11[0] = 0.0;
  v11[1] = 0.0;
  v3 = *(float *)(a1 + 448) * 0.5;
  *(float *)(a1 + 468) = 0.0;
  *(float *)(a1 + 472) = 0.0;
  v12 = v3;
  *(float *)(a1 + 476) = v12;
  if ( !v2 )
  {
    v9 = *(float *)(a1 + 460);
    *(float *)(a1 + 468) = *(float *)(a1 + 468) * v9;
    *(float *)(a1 + 472) = *(float *)(a1 + 472) * v9;
    *(float *)(a1 + 476) = v9 * *(float *)(a1 + 476);
    v4 = *(_DWORD **)(a1 + 168);
    v5 = (_DWORD *)*v4;
    if ( (_DWORD *)*v4 != v4 )
    {
      do
      {
        v6 = v5[2];
        sub_4085B0(v6 + 468, v11, v6 + 40);
        v7 = sub_401470(v13, v11, *(float *)(v6 + 460));
        *(float *)(a1 + 468) = *v7 + *(float *)(a1 + 468);
        *(float *)(a1 + 472) = v7[1] + *(float *)(a1 + 472);
        *(float *)(a1 + 476) = v7[2] + *(float *)(a1 + 476);
        *(float *)(a1 + 460) = *(float *)(a1 + 460) + *(float *)(v6 + 460);
        v5 = (_DWORD *)*v5;
      }
      while ( v5 != *(_DWORD **)(a1 + 168) );
      v1 = 0.0;
    }
    if ( v1 < *(float *)(a1 + 460) )
    {
      v10 = 1.0 / *(float *)(a1 + 460);
      *(float *)(a1 + 468) = *(float *)(a1 + 468) * v10;
      *(float *)(a1 + 472) = *(float *)(a1 + 472) * v10;
      *(float *)(a1 + 476) = v10 * *(float *)(a1 + 476);
    }
  }
}
