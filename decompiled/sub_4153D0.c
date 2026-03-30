double __thiscall sub_4153D0(int this)
{
  double v2; // st7
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  float v6; // [esp+8h] [ebp-14h]
  float v7; // [esp+Ch] [ebp-10h]
  float v8[3]; // [esp+10h] [ebp-Ch] BYREF

  v2 = sub_4015F0(v8, (float *)(this + 104))[1];
  v3 = *(_DWORD **)(this + 168);
  v6 = v2;
  v4 = (_DWORD *)*v3;
  if ( (_DWORD *)*v3 != v3 )
  {
    do
    {
      v7 = sub_4153D0(v4[2]);
      if ( v7 > (double)v6 )
        v6 = v7;
      v4 = (_DWORD *)*v4;
    }
    while ( v4 != *(_DWORD **)(this + 168) );
  }
  return v6;
}
