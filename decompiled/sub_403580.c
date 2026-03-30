void __stdcall sub_403580(const void **a1, unsigned int a2, const void *a3)
{
  const void **v3; // edi
  unsigned int v4; // esi
  unsigned int v5; // ebx
  unsigned int v6; // ecx
  void *v7; // eax
  unsigned int v8; // ecx
  void *v9; // ebx
  const void *v10; // ecx
  const void *v11; // eax
  int v12; // [esp+0h] [ebp-30h] BYREF
  _DWORD pExceptionObject[3]; // [esp+10h] [ebp-20h] BYREF
  char *v14[5]; // [esp+1Ch] [ebp-14h] BYREF

  v14[1] = (char *)&v12;
  v3 = a1;
  v4 = a2 | 7;
  if ( (a2 | 7) <= 0x7FFFFFFE )
  {
    v5 = (unsigned int)a1[5];
    v6 = v5 >> 1;
    if ( v5 >> 1 > v4 / 3 )
    {
      v4 = v6 + v5;
      if ( v5 > 2147483646 - v6 )
        v4 = 2147483646;
    }
  }
  else
  {
    v4 = a2;
  }
  v7 = 0;
  v8 = v4 + 1;
  v14[4] = 0;
  if ( v4 != -1 && (v8 > 0x7FFFFFFF || (v7 = operator new(2 * v8)) == 0) )
  {
    v14[0] = 0;
    std::exception::exception((std::exception *)pExceptionObject, (const char *const *)v14);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  v9 = v7;
  v10 = a3;
  if ( a3 )
  {
    if ( (unsigned int)a1[5] < 8 )
      v11 = a1;
    else
      v11 = *a1;
    memcpy_0(v9, v11, 2 * (_DWORD)a3);
    v10 = a3;
  }
  if ( (unsigned int)a1[5] >= 8 )
  {
    operator delete((void *)*a1);
    v10 = a3;
  }
  *a1 = v9;
  a1[5] = (const void *)v4;
  a1[4] = v10;
  if ( v4 >= 8 )
    v3 = (const void **)v9;
  *((_WORD *)v3 + (_DWORD)v10) = 0;
}
