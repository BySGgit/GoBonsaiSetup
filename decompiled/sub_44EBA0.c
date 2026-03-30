char ***__stdcall sub_44EBA0(char ***a1, int ***a2)
{
  char **v2; // eax
  int v4; // [esp+0h] [ebp-30h] BYREF
  _DWORD pExceptionObject[3]; // [esp+10h] [ebp-20h] BYREF
  char *v6[5]; // [esp+1Ch] [ebp-14h] BYREF

  v6[1] = (char *)&v4;
  a1[1] = 0;
  v2 = (char **)operator new(0x30u);
  if ( !v2 )
  {
    v6[0] = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)v6);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  *a1 = v2;
  *v2 = (char *)v2;
  (*a1)[1] = (char *)*a1;
  v6[4] = (char *)1;
  sub_44ED10((int)a1, **a1, **a2, (int *)*a2, (int)a1);
  return a1;
}
