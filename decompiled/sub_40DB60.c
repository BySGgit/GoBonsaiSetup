void __thiscall sub_40DB60(int this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  int v4; // ecx
  double v5; // st7
  int v6; // ecx
  int v7; // eax
  float *v8; // eax
  float v9; // [esp+18h] [ebp-14h]
  float v10[4]; // [esp+1Ch] [ebp-10h] BYREF

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
  if ( !*(_BYTE *)(dword_4D7EEC + 420) )
  {
    if ( HIBYTE(dword_4D8C94) )
    {
      v5 = 1.0;
      goto LABEL_7;
    }
    if ( BYTE2(dword_4D8C94) )
    {
      v5 = -1.0;
LABEL_7:
      v9 = v5;
      v10[0] = *(float *)(dword_4D7EE8 + 224);
      v6 = *(_DWORD *)(dword_4D7EE8 + 228);
      v7 = *(_DWORD *)(dword_4D7EE8 + 232);
      v10[0] = v9 * 0.03333333507180214 * 4.0 + v10[0];
      *(float *)(this + 224) = v10[0];
      *(_DWORD *)(this + 228) = v6;
      *(_DWORD *)(this + 232) = v7;
    }
  }
  D3DXQuaternionRotationYawPitchRoll(v10, LODWORD(flt_4D5348), LODWORD(flt_4D534C), LODWORD(flt_4D5350));
  v8 = *(float **)(this + 240);
  v8[80] = v10[0];
  v8[81] = v10[1];
  v8[82] = v10[2];
  v8[83] = v10[3];
  *(_DWORD *)(this + 200) = *(_DWORD *)(*(_DWORD *)(this + 240) + 480);
  sub_40F140((_DWORD *)this);
}
