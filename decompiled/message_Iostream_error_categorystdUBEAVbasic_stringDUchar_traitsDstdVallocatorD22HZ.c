size_t *__stdcall std::_Iostream_error_category::message(size_t *a1, int ErrorMessage)
{
  char *v3; // [esp-4h] [ebp-8h]

  if ( ErrorMessage == 1 )
  {
    sub_44C940(a1, "iostream stream error");
  }
  else
  {
    v3 = strerror(ErrorMessage);
    sub_44C940(a1, v3);
  }
  return a1;
}
