int __cdecl _CallSETranslator(
        struct EHExceptionRecord *a1,
        struct EHRegistrationNode *a2,
        void *a3,
        void *a4,
        const struct _s_FuncInfo *a5,
        int a6,
        struct EHRegistrationNode *a7)
{
  int v8; // [esp+0h] [ebp-3Ch] BYREF
  int v9; // [esp+4h] [ebp-38h]
  _DWORD v10[2]; // [esp+8h] [ebp-34h] BYREF
  void (__cdecl *v11)(unsigned int, _DWORD *); // [esp+10h] [ebp-2Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+14h] [ebp-28h]
  enum _EXCEPTION_DISPOSITION (__cdecl *v13)(PEXCEPTION_RECORD, PVOID, void *, void *); // [esp+18h] [ebp-24h]
  const struct _s_FuncInfo *v14; // [esp+20h] [ebp-1Ch]
  struct EHRegistrationNode *v15; // [esp+24h] [ebp-18h]
  int v16; // [esp+28h] [ebp-14h]
  struct EHRegistrationNode *v17; // [esp+2Ch] [ebp-10h]
  int *v18; // [esp+30h] [ebp-Ch]
  int *v19; // [esp+34h] [ebp-8h]
  int v20; // [esp+38h] [ebp-4h]
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  if ( a1 == (struct EHExceptionRecord *)291 )
  {
    a2->pNext = (EHRegistrationNode *)&_ExceptionContinuation_27230;
    return 1;
  }
  else
  {
    v13 = TranslatorGuardHandler;
    v14 = a5;
    v15 = a2;
    v16 = a6;
    v17 = a7;
    v20 = 0;
    v18 = &v8;
    v19 = &savedregs;
    ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
    v9 = 1;
    v10[0] = a1;
    v10[1] = a3;
    v11 = *(void (__cdecl **)(unsigned int, _DWORD *))(_getptd() + 128);
    v11(a1->ExceptionCode, v10);
    v9 = 0;
    if ( v20 )
      ExceptionList->Next = NtCurrentTeb()->NtTib.ExceptionList->Next;
    return v9;
  }
}
