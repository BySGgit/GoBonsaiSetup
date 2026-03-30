size_t *__thiscall sub_448C60(char **this, size_t *a2)
{
  char *v2; // ecx

  v2 = *(this + 2);
  a2[5] = 15;
  a2[4] = 0;
  *(_BYTE *)a2 = 0;
  sub_44C850(a2, v2, strlen(v2));
  return a2;
}
