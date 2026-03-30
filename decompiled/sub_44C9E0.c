void *__thiscall sub_44C9E0(int this, unsigned int a2, size_t Size)
{
  const void **v3; // edi
  unsigned int v4; // esi
  unsigned int v5; // ebx
  unsigned int v6; // ecx
  void *v7; // eax
  const void *v8; // eax
  void *result; // eax
  int v10; // [esp+0h] [ebp-38h] BYREF
  _DWORD pExceptionObject[3]; // [esp+10h] [ebp-28h] BYREF
  char *v12[6]; // [esp+20h] [ebp-18h] BYREF
  void *v13; // [esp+40h] [ebp+8h]

  v12[2] = (char *)&v10;
  v3 = (const void **)this;
  v12[1] = (char *)this;
  v4 = a2 | 0xF;
  if ( (a2 | 0xF) == 0xFFFFFFFF )
  {
    v4 = a2;
  }
  else
  {
    v5 = *(_DWORD *)(this + 20);
    v6 = v5 >> 1;
    if ( v5 >> 1 > v4 / 3 )
    {
      v4 = v6 + v5;
      if ( v5 > -2 - v6 )
        v4 = -2;
    }
  }
  v7 = 0;
  v12[5] = 0;
  if ( v4 != -1 )
  {
    v7 = operator new(v4 + 1);
    if ( !v7 )
    {
      v12[0] = 0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)v12);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
  }
  v13 = v7;
  if ( Size )
  {
    if ( (unsigned int)v3[5] < 0x10 )
      v8 = v3;
    else
      v8 = *v3;
    memcpy_0(v13, v8, Size);
  }
  if ( (unsigned int)v3[5] >= 0x10 )
    operator delete((void *)*v3);
  result = v13;
  *(_BYTE *)v3 = 0;
  *v3 = v13;
  v3[5] = (const void *)v4;
  v3[4] = (const void *)Size;
  if ( v4 >= 0x10 )
    v3 = (const void **)v13;
  *((_BYTE *)v3 + Size) = 0;
  return result;
}
