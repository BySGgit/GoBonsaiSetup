void __cdecl FindHandlerForForeignException(
        struct EHExceptionRecord *a1,
        struct EHRegistrationNode *a2,
        struct _CONTEXT *a3,
        struct _CONTEXT *a4,
        struct _s_FuncInfo *a5,
        int a6,
        struct _s_HandlerType *a7,
        struct _s_CatchableType *a8)
{
  _DWORD *v8; // edi
  int v9; // esi
  TryBlockMapEntry *v10; // eax
  int *p_nCatches; // eax
  int v12; // ecx
  int v13; // edx
  unsigned int v14; // [esp+4h] [ebp-Ch] BYREF
  int *v15; // [esp+8h] [ebp-8h]
  unsigned int v16; // [esp+Ch] [ebp-4h] BYREF

  if ( a1->ExceptionCode != -2147483645 )
  {
    if ( !*(_DWORD *)(_getptd() + 128)
      || (v8 = (_DWORD *)(_getptd() + 128), *v8 == _encoded_null())
      || a1->ExceptionCode == -532459699
      || a1->ExceptionCode == -532462766
      || !_CallSETranslator(a1, a2, a3, a4, a5, (int)a7, (struct EHRegistrationNode *)a8) )
    {
      if ( !a5->nTryBlocks )
        _inconsistency();
      v9 = a6;
      v10 = _GetRangeOfTrysToCheck(a5, (int)a7, a6, &v16, &v14);
      if ( v16 < v14 )
      {
        p_nCatches = &v10->nCatches;
        v15 = p_nCatches;
        do
        {
          if ( v9 >= *(p_nCatches - 3) && v9 <= *(p_nCatches - 2) )
          {
            v12 = p_nCatches[1] + 16 * *p_nCatches;
            v13 = *(_DWORD *)(v12 - 12);
            if ( (!v13 || !*(_BYTE *)(v13 + 8)) && (*(_BYTE *)(v12 - 16) & 0x40) == 0 )
            {
              CatchIt((int *)(v12 - 16), p_nCatches - 3, a2, (EXCEPTION_RECORD *)a1, a3, a4, a5, 0, a7, a8);
              v9 = a6;
              p_nCatches = v15;
            }
          }
          ++v16;
          p_nCatches += 5;
          v15 = p_nCatches;
        }
        while ( v16 < v14 );
      }
    }
  }
}
