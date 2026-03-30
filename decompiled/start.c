int start()
{
  __security_init_cookie();
  return __tmainCRTStartup();
}
