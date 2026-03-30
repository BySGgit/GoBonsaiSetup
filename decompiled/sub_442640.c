void sub_442640()
{
  if ( (dword_4D8EC0 & 1) == 0 )
  {
    dword_4D8EC0 |= 1u;
    sub_43FD00();
    atexit(sub_472560);
  }
  sub_444140((int)&dword_4D8E44);
}
