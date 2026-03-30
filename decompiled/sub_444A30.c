char *__thiscall sub_444A30(char *this, char a2)
{
  char *v2; // esi

  v2 = this - 96;
  sub_440350(this - 96);
  if ( (a2 & 1) != 0 )
    operator delete(v2);
  return v2;
}
