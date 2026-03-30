_DWORD *__userpurge sub_408240@<eax>(int a1@<esi>, _DWORD *a2)
{
  int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // ebx
  unsigned int v5; // edi
  void *v6; // eax
  _DWORD *result; // eax
  char *v8; // [esp+0h] [ebp-10h] BYREF
  _DWORD pExceptionObject[3]; // [esp+4h] [ebp-Ch] BYREF

  v2 = *(_DWORD *)(a1 + 16);
  if ( (((_BYTE)v2 + *(_BYTE *)(a1 + 12)) & 3) == 0 && *(_DWORD *)(a1 + 8) <= (unsigned int)(v2 + 4) >> 2 )
    sub_4082F0(a1);
  v3 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(a1 + 16) + *(_DWORD *)(a1 + 12);
  v5 = v4 >> 2;
  if ( v3 <= v4 >> 2 )
    v5 -= v3;
  if ( !*(_DWORD *)(*(_DWORD *)(a1 + 4) + 4 * v5) )
  {
    v6 = operator new(0x10u);
    if ( !v6 )
    {
      v8 = 0;
      std::exception::exception((std::exception *)pExceptionObject, (const char *const *)&v8);
      pExceptionObject[0] = &std::bad_alloc::`vftable';
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
    }
    *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4 * v5) = v6;
  }
  result = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 4 * v5) + 4 * (v4 & 3));
  if ( result )
    *result = *a2;
  ++*(_DWORD *)(a1 + 16);
  return result;
}
