void __thiscall sub_417440(int this)
{
  void *v2; // eax
  float v3; // [esp+8h] [ebp-20h]
  float v4; // [esp+Ch] [ebp-1Ch]
  float v5[3]; // [esp+10h] [ebp-18h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  if ( !*(_DWORD *)(this + 172) && *(float *)(this + 432) > 0.0 )
  {
    v4 = (double)rand() / 32767.0 * 0.1599999964237213 - 0.07999999821186066;
    v3 = (double)rand() / 32767.0 * 0.1599999964237213 - 0.07999999821186066;
    v5[0] = v4;
    v5[1] = 0.0;
    v5[2] = v3;
    v2 = operator new(0x220u);
    v6 = 0;
    if ( v2 )
      sub_4159C0(&unk_4D8BA8, this, (int)v2, (int)v5);
    v6 = -1;
  }
  sub_414E10(this);
}
