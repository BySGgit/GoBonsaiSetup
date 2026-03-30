void __cdecl __noreturn _amsg_exit(int a1)
{
  _FF_MSGBANNER();
  _NMSG_WRITE(a1);
  _exit(255);
}
