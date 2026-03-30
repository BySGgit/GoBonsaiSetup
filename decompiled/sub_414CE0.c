_DWORD *__thiscall sub_414CE0(int this)
{
  double v2; // st7
  _DWORD *v3; // ecx
  _DWORD *result; // eax
  _DWORD *v5; // esi
  float v6; // [esp+10h] [ebp-14h]

  if ( this )
  {
    if ( (dword_4D8CF8 & 1) == 0 )
    {
      dword_4D8CF8 |= 1u;
      sub_413C20();
    }
    if ( byte_4D8229[11 * *(_DWORD *)(this + 4)] )
    {
      v2 = *(float *)(*(_DWORD *)(this + 180) + 428) * *(float *)(this + 512);
LABEL_10:
      *(float *)(this + 428) = v2;
      goto LABEL_11;
    }
    if ( (dword_4D8CE0 & 1) == 0 )
    {
      dword_4D8CE0 |= 1u;
      sub_40FBA0();
    }
    if ( byte_4D822A[11 * *(_DWORD *)(this + 4)] )
    {
      v6 = pow(*(float *)(this + 424), *(float *)flt_4D8628);
      *(float *)(this + 424) = v6;
      v2 = (1.0 - *(float *)flt_4D863C) * *(float *)(this + 428) + *(float *)flt_4D863C * v6;
      goto LABEL_10;
    }
  }
LABEL_11:
  v3 = *(_DWORD **)(this + 168);
  *(float *)(this + 424) = 0.0;
  result = (_DWORD *)*v3;
  if ( (_DWORD *)*v3 != v3 )
  {
    do
    {
      v5 = (_DWORD *)*result;
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)result[2] + 40))(result[2]);
      result = v5;
    }
    while ( v5 != *(_DWORD **)(this + 168) );
  }
  return result;
}
