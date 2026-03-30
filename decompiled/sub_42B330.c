void **__stdcall sub_42B330(void **a1)
{
  sub_42C0E0((int)a1);
  if ( ((int)a1[15] <= 0 || a1[14]) && a1[14] )
  {
    free(a1[14]);
    a1[14] = 0;
  }
  a1[16] = 0;
  a1[15] = 0;
  if ( (int)a1[4] <= 0 || a1[3] )
  {
    if ( a1[3] )
    {
      free(a1[3]);
      a1[3] = 0;
    }
  }
  a1[5] = 0;
  a1[4] = 0;
  operator delete(a1);
  return a1;
}
