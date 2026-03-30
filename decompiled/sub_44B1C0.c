void **__cdecl sub_44B1C0(void **a1, _DWORD *a2)
{
  unsigned int v2; // edi
  unsigned int v3; // eax
  bool v4; // cf
  int *v5; // eax

  a1[5] = (void *)7;
  a1[4] = 0;
  *(_WORD *)a1 = 0;
  v2 = (unsigned int)a1[4];
  v3 = a2[4] + 1;
  if ( v2 <= v3 && a1[5] != (void *)v3 && sub_4036F0(a1, v3, 1) )
  {
    v4 = (unsigned int)a1[5] < 8;
    a1[4] = (void *)v2;
    if ( v4 )
      v5 = (int *)a1;
    else
      v5 = (int *)*a1;
    *((_WORD *)v5 + v2) = 0;
  }
  sub_44A460((char *)a1, a2, 0, 0xFFFFFFFF);
  sub_44BC80((char *)a1, (char *)L" ", 1u);
  return a1;
}
