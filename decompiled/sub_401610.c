void __fastcall sub_401610(float *a1, float *a2)
{
  if ( *a2 > (double)*a1 )
    *a2 = *a1;
  if ( a2[1] > (double)a1[1] )
    a2[1] = a1[1];
  if ( a2[2] > (double)a1[2] )
    a2[2] = a1[2];
  if ( a2[3] < (double)a1[3] )
    a2[3] = a1[3];
  if ( a2[4] < (double)a1[4] )
    a2[4] = a1[4];
  if ( a2[5] < (double)a1[5] )
    a2[5] = a1[5];
}
