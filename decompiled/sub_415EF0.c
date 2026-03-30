void __thiscall sub_415EF0(void *this)
{
  double v2; // st7
  double v3; // st7
  int v4; // eax
  float v5; // [esp+8h] [ebp-4h]
  float v6; // [esp+8h] [ebp-4h]
  float v7; // [esp+8h] [ebp-4h]

  sub_414E10((int)this);
  if ( 0.0 == *((float *)this + 108) )
  {
    (*(void (__thiscall **)(void *))(*(_DWORD *)this + 44))(this);
  }
  else
  {
    v2 = *((float *)this + 111);
    *((_DWORD *)this + 120) = 1;
    if ( *((float *)this + 113) <= v2 )
    {
      sub_413CF0(*((_DWORD *)this + 45));
      v7 = (*((float *)this + 108) - *(float *)flt_4D862C) / (*(float *)flt_4D8630 - *(float *)flt_4D862C);
      if ( v7 >= 0.0 )
      {
        if ( v7 > 1.0 )
          v7 = 1.0;
      }
      else
      {
        v7 = 0.0;
      }
      v4 = sub_416300(*((_DWORD *)this + 45));
      if ( !v4 || !*(_BYTE *)(v4 + 512) )
        sub_415C10((int)this, v7);
    }
    else
    {
      v3 = *(float *)flt_4D8630;
      if ( *(float *)flt_4D8630 >= (double)*((float *)this + 108) )
        v3 = *((float *)this + 108);
      *((float *)this + 109) = v3;
      v5 = *((float *)this + 109) * flt_4D8620;
      v6 = v5 + *((float *)this + 111);
      *((float *)this + 111) = v6;
      if ( *((float *)this + 113) <= (double)v6 )
        *((float *)this + 111) = *((float *)this + 113);
    }
  }
}
