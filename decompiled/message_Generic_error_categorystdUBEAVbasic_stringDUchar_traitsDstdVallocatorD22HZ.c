size_t *__stdcall std::_Generic_error_category::message(size_t *a1, int ErrorMessage)
{
  char *v2; // eax

  v2 = strerror(ErrorMessage);
  sub_44C940(a1, v2);
  return a1;
}
