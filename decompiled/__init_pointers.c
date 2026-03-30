int _init_pointers()
{
  void *v0; // esi

  v0 = (void *)_encoded_null();
  sub_458A58(v0);
  sub_459E0A(v0);
  sub_45B798(v0);
  sub_4625D2((int)v0);
  _initp_misc_winsig(v0);
  return _initp_eh_hooks(v0);
}
