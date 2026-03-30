int __cdecl __InternalCxxFrameHandler(
        struct EHExceptionRecord *a1,
        struct EHRegistrationNode *a2,
        struct _CONTEXT *a3,
        struct _CONTEXT *a4,
        struct _s_FuncInfo *a5,
        struct _s_HandlerType *a6,
        struct _s_CatchableType *a7,
        unsigned __int8 a8)
{
  int (__cdecl *pForwardCompat)(); // edx

  if ( *(_DWORD *)(_getptd() + 524)
    || a1->ExceptionCode == -529697949
    || a1->ExceptionCode == -2147483610
    || (*(_DWORD *)a5 & 0x1FFFFFFFu) < 0x19930522
    || (a5->EHFlags & 1) == 0 )
  {
    if ( (a1->ExceptionFlags & 0x66) != 0 )
    {
      if ( a5->maxState )
      {
        if ( !a6 )
          __FrameUnwindToState((int)a2, (int)a4, (int)a5, -1);
      }
    }
    else if ( a5->nTryBlocks || (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930521 && a5->pESTypeList )
    {
      if ( a1->ExceptionCode == -529697949 && a1->NumberParameters >= 3 && a1->params.magicNumber > 0x19930522 )
      {
        pForwardCompat = a1->params.pThrowInfo->pForwardCompat;
        if ( pForwardCompat )
          return ((int (__cdecl *)(struct EHExceptionRecord *, struct EHRegistrationNode *, struct _CONTEXT *, struct _CONTEXT *, struct _s_FuncInfo *, struct _s_HandlerType *, struct _s_CatchableType *, _DWORD))pForwardCompat)(
                   a1,
                   a2,
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8);
      }
      FindHandler(a1, a2, a3, a4, a5, a8, a6, a7);
    }
  }
  return 1;
}
