void __cdecl FindHandler(
        struct EHExceptionRecord *ExceptionRecord,
        struct EHRegistrationNode *a2,
        struct _CONTEXT *a3,
        struct _CONTEXT *a4,
        struct _s_FuncInfo *a5,
        unsigned __int8 a6,
        struct _s_HandlerType *a7,
        struct _s_CatchableType *TargetFrame)
{
  struct _s_FuncInfo *v8; // ebx
  __ehstate_t maxState; // eax
  __ehstate_t state; // ecx
  struct EHExceptionRecord *v11; // esi
  int arrayOfCatchableTypes; // ebx
  unsigned int magicNumber; // eax
  unsigned int v14; // eax
  int *v15; // edi
  int v16; // eax
  int v17; // esi
  int v18; // ebx
  unsigned int v19; // eax
  struct _s_FuncInfo *v20; // edi
  TryBlockMapEntry *v21; // eax
  int **p_pHandlerArray; // edi
  CatchableTypeArray *pCatchableTypeArray; // eax
  int *p_nCount; // edi
  int v25; // eax
  bool v26; // zf
  struct EHExceptionRecord *v27; // [esp-4h] [ebp-44h]
  ThrowInfo *pThrowInfo; // [esp-4h] [ebp-44h]
  _DWORD pExceptionObject[3]; // [esp+Ch] [ebp-34h] BYREF
  int *v30; // [esp+18h] [ebp-28h]
  struct _s_FuncInfo *v31; // [esp+1Ch] [ebp-24h]
  unsigned int v32; // [esp+20h] [ebp-20h] BYREF
  int **v33; // [esp+24h] [ebp-1Ch]
  int v34; // [esp+28h] [ebp-18h]
  int nCatchableTypes; // [esp+2Ch] [ebp-14h]
  unsigned int v36; // [esp+30h] [ebp-10h] BYREF
  int *v37; // [esp+34h] [ebp-Ch]
  int v38; // [esp+38h] [ebp-8h]
  char v39; // [esp+3Fh] [ebp-1h]

  v8 = a5;
  maxState = a5->maxState;
  v39 = 0;
  if ( maxState > 128 )
    state = a2->state;
  else
    state = SLOBYTE(a2->state);
  v38 = state;
  if ( state < -1 || state >= maxState )
    _inconsistency();
  v11 = ExceptionRecord;
  if ( ExceptionRecord->ExceptionCode != -529697949 )
  {
LABEL_61:
    if ( v8->nTryBlocks )
    {
      if ( a6 )
        goto LABEL_28;
      FindHandlerForForeignException(v11, a2, a3, a4, v8, v38, a7, TargetFrame);
    }
    goto LABEL_64;
  }
  arrayOfCatchableTypes = 429065504;
  if ( ExceptionRecord->NumberParameters == 3 )
  {
    magicNumber = ExceptionRecord->params.magicNumber;
    if ( (magicNumber == 429065504 || magicNumber == 429065505 || magicNumber == 429065506)
      && !ExceptionRecord->params.pThrowInfo )
    {
      if ( !*(_DWORD *)(_getptd() + 136) )
        return;
      v11 = *(struct EHExceptionRecord **)(_getptd() + 136);
      ExceptionRecord = v11;
      a3 = *(struct _CONTEXT **)(_getptd() + 140);
      if ( !unknown_libname_5(v11) )
        _inconsistency();
      if ( v11->ExceptionCode == -529697949 && v11->NumberParameters == 3 )
      {
        v14 = v11->params.magicNumber;
        if ( (v14 == 429065504 || v14 == 429065505 || v14 == 429065506) && !v11->params.pThrowInfo )
          _inconsistency();
      }
      if ( *(_DWORD *)(_getptd() + 148) )
      {
        v15 = *(int **)(_getptd() + 148);
        v16 = _getptd();
        v27 = ExceptionRecord;
        v17 = 0;
        *(_DWORD *)(v16 + 148) = 0;
        if ( !IsInExceptionSpec(v15, v27) )
        {
          v18 = 0;
          if ( *v15 > 0 )
          {
            do
            {
              if ( type_info::operator==(
                     *(const char **)(v18 + v15[1] + 4),
                     (int)&std::bad_exception `RTTI Type Descriptor') )
              {
                __DestructExceptionObject(ExceptionRecord);
                ExceptionRecord = (struct EHExceptionRecord *)"bad exception";
                std::exception::exception((std::exception *)pExceptionObject, (char **)&ExceptionRecord);
                pExceptionObject[0] = &std::bad_exception::`vftable';
                _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_exception_std__);
              }
              ++v17;
              v18 += 16;
            }
            while ( v17 < *v15 );
          }
LABEL_28:
          terminate();
        }
        v11 = ExceptionRecord;
      }
    }
  }
  if ( v11->ExceptionCode != -529697949
    || v11->NumberParameters != 3
    || (v19 = v11->params.magicNumber, v19 != 429065504) && v19 != 429065505 && v19 != 429065506 )
  {
    v8 = a5;
    goto LABEL_61;
  }
  v20 = a5;
  if ( a5->nTryBlocks )
  {
    v21 = _GetRangeOfTrysToCheck(a5, (int)a7, v38, &v36, &v32);
    if ( v36 < v32 )
    {
      p_pHandlerArray = (int **)&v21->pHandlerArray;
      v33 = (int **)&v21->pHandlerArray;
      do
      {
        v30 = (int *)(p_pHandlerArray - 4);
        if ( (int)*(p_pHandlerArray - 4) <= v38 && v38 <= (int)*(p_pHandlerArray - 3) )
        {
          v37 = *p_pHandlerArray;
          v34 = (int)*(p_pHandlerArray - 1);
          if ( v34 > 0 )
          {
            while ( 1 )
            {
              pCatchableTypeArray = v11->params.pThrowInfo->pCatchableTypeArray;
              arrayOfCatchableTypes = (int)pCatchableTypeArray->arrayOfCatchableTypes;
              nCatchableTypes = pCatchableTypeArray->nCatchableTypes;
              if ( nCatchableTypes > 0 )
                break;
LABEL_45:
              --v34;
              v37 += 4;
              if ( v34 <= 0 )
                goto $NextTryBlock$28284;
            }
            while ( 1 )
            {
              pThrowInfo = v11->params.pThrowInfo;
              v31 = *(struct _s_FuncInfo **)arrayOfCatchableTypes;
              if ( __TypeMatch((int)v37, (int)v31, pThrowInfo) )
                break;
              --nCatchableTypes;
              arrayOfCatchableTypes += 4;
              if ( nCatchableTypes <= 0 )
                goto LABEL_45;
            }
            arrayOfCatchableTypes = (int)v37;
            v39 = 1;
            CatchIt(v37, v30, a2, (EXCEPTION_RECORD *)v11, a3, a4, a5, v31, a7, TargetFrame);
            v11 = ExceptionRecord;
            p_pHandlerArray = v33;
          }
        }
$NextTryBlock$28284:
        ++v36;
        p_pHandlerArray += 5;
        v33 = p_pHandlerArray;
      }
      while ( v36 < v32 );
      v20 = a5;
    }
  }
  if ( a6 )
    __DestructExceptionObject(v11);
  if ( !v39 && (*(_DWORD *)v20 & 0x1FFFFFFFu) >= 0x19930521 )
  {
    p_nCount = &v20->pESTypeList->nCount;
    if ( p_nCount )
    {
      if ( !IsInExceptionSpec(p_nCount, v11) )
      {
        _getptd();
        _getptd();
        *(_DWORD *)(_getptd() + 136) = v11;
        v25 = _getptd();
        v26 = TargetFrame == 0;
        *(_DWORD *)(v25 + 140) = a3;
        if ( v26 )
          _UnwindNestedFrames(
            (struct _EXCEPTION_REGISTRATION_RECORD **)arrayOfCatchableTypes,
            a2,
            (PEXCEPTION_RECORD)v11);
        else
          _UnwindNestedFrames(
            (struct _EXCEPTION_REGISTRATION_RECORD **)arrayOfCatchableTypes,
            TargetFrame,
            (PEXCEPTION_RECORD)v11);
        __FrameUnwindToState((int)a2, (int)a4, (int)a5, -1);
        CallUnexpected();
      }
    }
  }
LABEL_64:
  if ( *(_DWORD *)(_getptd() + 148) )
    _inconsistency();
}
