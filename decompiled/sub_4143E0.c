int __thiscall sub_4143E0(int this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  int result; // eax
  float v9; // [esp+18h] [ebp-74h]
  float v10; // [esp+18h] [ebp-74h]
  float v11; // [esp+18h] [ebp-74h]
  float v12; // [esp+1Ch] [ebp-70h]

  v2 = *(_DWORD **)(this + 168);
  v3 = (_DWORD *)*v2;
  if ( (_DWORD *)*v2 != v2 )
  {
    do
    {
      v4 = v3[2];
      v3 = (_DWORD *)*v3;
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(v4);
    }
    while ( v3 != *(_DWORD **)(this + 168) );
  }
  sub_414870();
  if ( (dword_4DBC64 & 1) == 0 )
  {
    dword_4DBC64 |= 1u;
    sub_4032D0(14);
    sub_4038B0(&unk_4DBC40, &byte_4D6356);
    atexit(sub_472420);
  }
  if ( byte_4D6356 && *(_DWORD *)(this + 172) && flt_4D6358 < (double)*(float *)(this + 460) )
  {
    if ( *(_DWORD *)(this + 180) )
      sub_414A70(this);
    sub_414BB0();
  }
  if ( (dword_4DBC64 & 2) == 0 )
  {
    dword_4DBC64 |= 2u;
    sub_4032D0(19);
    sub_4038B0(&unk_4DBC1C, &byte_4D8DA5);
    atexit(sub_472410);
  }
  if ( byte_4D8DA5 )
  {
    sub_401470(10.0);
    v5 = sub_4013F0(this + 24);
    sub_44E5D0(this + 24, v5, 0.0);
  }
  v9 = *(float *)(this + 220) * *(float *)(this + 200)
     + *(float *)(this + 196) * *(float *)(this + 216)
     + *(float *)(this + 224) * *(float *)(this + 204);
  v10 = (v9 + 1.0) * 0.5;
  v11 = v10 * 0.1000000014901161;
  v12 = 1.0 - v11;
  sub_401500(v12);
  v6 = sub_401500(v11);
  v7 = (_DWORD *)sub_4013F0(v6);
  *(_DWORD *)(this + 216) = *v7;
  *(_DWORD *)(this + 220) = v7[1];
  *(_DWORD *)(this + 224) = v7[2];
  result = sub_40CF00();
  *(float *)(this + 228) = (*(float *)(this + 208) - *(float *)(this + 228)) * 0.1000000014901161
                         + *(float *)(this + 228);
  *(float *)(this + 232) = 0.1000000014901161 * (*(float *)(this + 212) - *(float *)(this + 232))
                         + *(float *)(this + 232);
  return result;
}
