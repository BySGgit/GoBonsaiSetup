char __usercall IsInExceptionSpec@<al>(int *a1@<edi>, struct EHExceptionRecord *a2)
{
  CatchableTypeArray *pCatchableTypeArray; // eax
  int nCatchableTypes; // ebx
  int *arrayOfCatchableTypes; // esi
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]
  char v8; // [esp+Bh] [ebp-1h]

  if ( !a1 )
    _inconsistency();
  v8 = 0;
  v6 = 0;
  if ( *a1 > 0 )
  {
    v7 = 0;
    do
    {
      pCatchableTypeArray = a2->params.pThrowInfo->pCatchableTypeArray;
      nCatchableTypes = pCatchableTypeArray->nCatchableTypes;
      arrayOfCatchableTypes = (int *)pCatchableTypeArray->arrayOfCatchableTypes;
      while ( nCatchableTypes > 0 )
      {
        if ( __TypeMatch(v7 + a1[1], *arrayOfCatchableTypes, &a2->params.pThrowInfo->attributes) )
        {
          v8 = 1;
          break;
        }
        --nCatchableTypes;
        ++arrayOfCatchableTypes;
      }
      ++v6;
      v7 += 16;
    }
    while ( v6 < *a1 );
  }
  return v8;
}
