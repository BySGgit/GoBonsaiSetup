void __stdcall sub_406C20(char *a1)
{
  char *v1; // ebx
  char *v2; // eax
  char *v3; // esi
  char *v4; // edi
  char **v5; // eax
  char *v6; // [esp-4h] [ebp-2Ch]
  _DWORD pExceptionObject[6]; // [esp+10h] [ebp-18h] BYREF

  v1 = a1;
  if ( (dword_4D8E14 & 1) == 0 )
  {
    dword_4D8E14 |= 1u;
    pExceptionObject[5] = 0;
    dword_4D8E0C = 0;
    v2 = (char *)operator new(0xCu);
    if ( !v2 )
    {
      a1 = 0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a1);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
    dword_4D8E08 = v2;
    *(_DWORD *)v2 = v2;
    *((_DWORD *)dword_4D8E08 + 1) = dword_4D8E08;
    atexit(sub_472020);
  }
  v3 = *(char **)dword_4D8E08;
  v4 = dword_4D8E08;
  while ( v3 != v4 )
  {
    if ( *((char **)v3 + 2) == v1 )
    {
      v5 = (char **)*((_DWORD *)v3 + 1);
      v6 = v3;
      v3 = *(char **)v3;
      *v5 = v3;
      *((_DWORD *)v3 + 1) = v5;
      operator delete(v6);
      --dword_4D8E0C;
    }
    else
    {
      v3 = *(char **)v3;
    }
  }
}
