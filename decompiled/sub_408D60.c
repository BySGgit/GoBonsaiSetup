void __thiscall sub_408D60(float *this)
{
  double v2; // st7
  float *v3; // ebx
  float *v4; // eax
  double v5; // st7
  double v6; // st6
  double v7; // st7
  double v8; // st6
  float v9; // [esp+10h] [ebp-20h]
  float v10; // [esp+14h] [ebp-1Ch]

  if ( *(this + 68) <= (double)*(this + 67) )
  {
    if ( *(this + 68) < (double)*(this + 67) )
    {
      *(this + 67) = *(this + 67) - 0.1000000014901161;
      if ( *(this + 68) > (double)*(this + 67) )
        *(this + 67) = *(this + 68);
    }
  }
  else
  {
    *(this + 67) = *(this + 67) + 0.1000000014901161;
    if ( *(this + 68) < (double)*(this + 67) )
      *(this + 67) = *(this + 68);
  }
  v2 = *(this + 49);
  if ( *(this + 51) <= v2 )
  {
    if ( *(this + 51) >= v2 )
      goto LABEL_14;
    *(this + 49) = *(this + 49) - 0.25;
    if ( *(this + 51) > (double)*(this + 49) )
      goto LABEL_12;
  }
  else
  {
    *(this + 49) = v2 + 0.25;
    if ( *(this + 51) < (double)*(this + 49) )
LABEL_12:
      *(this + 49) = *(this + 51);
  }
  flt_4D7E88 = *(this + 49);
LABEL_14:
  if ( *(this + 52) <= (double)*(this + 50) )
  {
    if ( *(this + 52) < (double)*(this + 50) )
    {
      *(this + 50) = *(this + 50) - 0.25;
      if ( *(this + 52) > (double)*(this + 50) )
        *(this + 50) = *(this + 52);
    }
  }
  else
  {
    *(this + 50) = *(this + 50) + 0.25;
    if ( *(this + 52) < (double)*(this + 50) )
      *(this + 50) = *(this + 52);
  }
  v3 = this + 53;
  sub_401430(this + 53);
  v10 = sub_4084F0();
  v9 = 0.30000001;
  if ( v10 < 0.300000011920929 )
    v9 = v10;
  v4 = (float *)sub_401470(v9);
  *v3 = *v3 - *v4;
  *(this + 54) = *(this + 54) - v4[1];
  *(this + 55) = *(this + 55) - v4[2];
  v5 = *(this + 59);
  if ( *(this + 63) <= v5 )
  {
    if ( *(this + 63) >= v5 )
    {
      v7 = 0.1000000014901161;
    }
    else
    {
      v7 = 0.1000000014901161;
      *(this + 59) = *(this + 59) - 0.1000000014901161;
      if ( *(this + 63) > (double)*(this + 59) )
        *(this + 59) = *(this + 63);
    }
  }
  else
  {
    v6 = v5 + 0.1000000014901161;
    v7 = 0.1000000014901161;
    *(this + 59) = v6;
    if ( *(this + 63) < (double)*(this + 59) )
      *(this + 59) = *(this + 63);
  }
  v8 = *(this + 60);
  if ( *(this + 64) > v8 )
  {
    *(this + 60) = v8 + v7;
    if ( *(this + 64) >= (double)*(this + 60) )
      goto LABEL_35;
    goto LABEL_34;
  }
  if ( *(this + 64) < v8 )
  {
    *(this + 60) = *(this + 60) - v7;
    if ( *(this + 64) > (double)*(this + 60) )
LABEL_34:
      *(this + 60) = *(this + 64);
  }
LABEL_35:
  if ( *(this + 65) <= (double)*(this + 61) )
  {
    if ( *(this + 65) < (double)*(this + 61) )
    {
      *(this + 61) = *(this + 61) - v7;
      if ( *(this + 65) > (double)*(this + 61) )
        *(this + 61) = *(this + 65);
    }
  }
  else
  {
    *(this + 61) = v7 + *(this + 61);
    if ( *(this + 65) < (double)*(this + 61) )
      *(this + 61) = *(this + 65);
  }
}
