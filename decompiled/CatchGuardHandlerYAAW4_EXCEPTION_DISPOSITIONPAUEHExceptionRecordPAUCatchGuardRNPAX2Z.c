int __cdecl CatchGuardHandler(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3)
{
  return __InternalCxxFrameHandler(
           a1,
           (struct EHRegistrationNode *)a2[1].frameHandler,
           a3,
           0,
           (struct _s_FuncInfo *)a2[1].pNext,
           a2[1].state,
           a2,
           0);
}
