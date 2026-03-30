int *__userpurge sub_446B80@<eax>(int a1@<esi>, void *Src, char *a3)
{
  int *result; // eax
  char *v4; // ebx
  int v5; // edi
  signed int v6; // ebx
  bool v7; // zf
  int v8; // ecx
  int v9; // ebx
  _DWORD pExceptionObject[3]; // [esp+4h] [ebp-Ch] BYREF

  result = (int *)(*(_DWORD *)(a1 + 64) & 6);
  v4 = a3;
  if ( (_BYTE)result != 6 )
  {
    v5 = 0;
    if ( a3 )
    {
      if ( (unsigned int)a3 > 0x7FFFFFFF || (v5 = (int)operator new(2 * (_DWORD)a3)) == 0 )
      {
        a3 = 0;
        std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&a3);
        pExceptionObject[0] = &std::bad_alloc::`vftable';
        _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
      }
    }
    v6 = 2 * (_DWORD)v4;
    memcpy_0((void *)v5, Src, v6);
    v7 = (*(_BYTE *)(a1 + 64) & 4) == 0;
    result = (int *)(v6 + v5);
    *(_DWORD *)(a1 + 60) = v6 + v5;
    if ( v7 )
    {
      **(_DWORD **)(a1 + 16) = v5;
      **(_DWORD **)(a1 + 32) = v5;
      **(_DWORD **)(a1 + 48) = v6 >> 1;
    }
    v8 = *(_DWORD *)(a1 + 64);
    if ( (v8 & 2) == 0 )
    {
      if ( (v8 & 0x10) == 0 )
        result = (int *)v5;
      **(_DWORD **)(a1 + 20) = v5;
      v9 = v6 - (_DWORD)result;
      **(_DWORD **)(a1 + 36) = result;
      result = *(int **)(a1 + 52);
      *result = (v5 + v9) >> 1;
      if ( !**(_DWORD **)(a1 + 32) )
      {
        **(_DWORD **)(a1 + 16) = v5;
        result = *(int **)(a1 + 32);
        *result = 0;
        **(_DWORD **)(a1 + 48) = v5 >> 1;
      }
    }
    *(_DWORD *)(a1 + 64) |= 1u;
  }
  return result;
}
