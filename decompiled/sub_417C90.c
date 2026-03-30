void __thiscall sub_417C90(int this)
{
  double v2; // st7
  int v3; // esi
  double v4; // st7
  bool v5; // c0
  bool v6; // c3
  double v7; // st7
  double v8; // st7
  float v9; // [esp+18h] [ebp-38h]
  double v10; // [esp+1Ch] [ebp-34h]
  void *v11[4]; // [esp+24h] [ebp-2Ch] BYREF
  int v12; // [esp+34h] [ebp-1Ch]
  unsigned int v13; // [esp+38h] [ebp-18h]
  int v14; // [esp+4Ch] [ebp-4h]

  sub_414E10(this);
  v2 = *(float *)(this + 420);
  ++*(_DWORD *)(this + 484);
  v9 = v2 * *(float *)flt_4D8618 / *(float *)(this + 444);
  if ( v9 > 0.1000000014901161 )
    v9 = flt_4CA5E8;
  *(float *)(this + 444) = *(float *)(this + 444) + v9;
  D3DXQuaternionSlerp(this + 304, this + 304, this + 320, LODWORD(flt_4D8624));
  D3DXQuaternionNormalize(this + 304, this + 304);
  if ( *(_BYTE *)(this + 512) )
  {
    if ( !*(_DWORD *)(this + 172) )
    {
      v3 = *(_DWORD *)(this + 180);
      if ( v3 )
        sub_450C80((_DWORD *)this, v3);
      (*(void (__thiscall **)(int))(*(_DWORD *)this + 8))(this);
    }
    sub_418BD0(this);
  }
  else
  {
    sub_417F40(this);
  }
  if ( (dword_4DBB10 & 1) == 0 )
  {
    dword_4DBB10 |= 1u;
    v14 = 0;
    v13 = 7;
    v12 = 0;
    LOWORD(v11[0]) = 0;
    sub_4032D0(L"healthEnergyAdjustment", (int)v11, 0x16u);
    LOBYTE(v14) = 1;
    sub_408600(v11, (int)&unk_4DBAEC, (int)&flt_4D6428);
    if ( v13 >= 8 )
      operator delete(v11[0]);
    v13 = 7;
    v12 = 0;
    LOWORD(v11[0]) = 0;
    atexit(sub_4724A0);
    v14 = -1;
  }
  v4 = *(float *)(this + 432);
  v5 = *(float *)flt_4D862C < v4;
  v6 = *(float *)flt_4D862C == v4;
  v7 = *(float *)(this + 456);
  if ( v5 || v6 )
    v8 = v7 + flt_4D6428;
  else
    v8 = v7 - flt_4D6428;
  *(float *)(this + 456) = v8;
  if ( *(float *)(this + 456) >= 0.0 )
  {
    if ( *(float *)(this + 456) > 1.0 )
      *(float *)(this + 456) = 1.0;
  }
  else
  {
    *(float *)(this + 456) = 0.0;
  }
  if ( *(float *)(this + 456) <= 0.0 && *(float *)(*(_DWORD *)(this + 180) + 456) > 0.0 )
  {
    v10 = *(float *)(this + 444) * 4.0;
    if ( (double)rand() / 32767.0 > v10
      || (*(float *)(this + 440) <= 2000.0 || *(float *)(this + 444) <= 0.1)
      && *(float *)(this + 440) > 1000.0
      && (double)rand() / 32767.0 < 0.009999999776482582 )
    {
      sub_40EEE0(this);
    }
  }
}
