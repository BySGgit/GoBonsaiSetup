void __usercall _call_reportfault(int a1@<edi>, int a2@<esi>, int a3, int a4, int a5)
{
  int v5; // ecx
  int v6; // edx
  unsigned int v7; // kr00_4
  BOOL v8; // edi
  struct _EXCEPTION_POINTERS ExceptionInfo; // [esp+8h] [ebp-328h] BYREF
  _DWORD v10[20]; // [esp+10h] [ebp-320h] BYREF
  _DWORD v11[35]; // [esp+60h] [ebp-2D0h] BYREF
  __int16 v12; // [esp+ECh] [ebp-244h]
  __int16 v13; // [esp+F0h] [ebp-240h]
  __int16 v14; // [esp+F4h] [ebp-23Ch]
  __int16 v15; // [esp+F8h] [ebp-238h]
  int v16; // [esp+FCh] [ebp-234h]
  int v17; // [esp+100h] [ebp-230h]
  int v18; // [esp+104h] [ebp-22Ch]
  int v19; // [esp+108h] [ebp-228h]
  int v20; // [esp+10Ch] [ebp-224h]
  _DWORD *v21; // [esp+110h] [ebp-220h]
  int v22; // [esp+114h] [ebp-21Ch]
  void *v23; // [esp+118h] [ebp-218h]
  __int16 v24; // [esp+11Ch] [ebp-214h]
  unsigned int v25; // [esp+120h] [ebp-210h]
  void **v26; // [esp+124h] [ebp-20Ch]
  __int16 v27; // [esp+128h] [ebp-208h]
  int savedregs; // [esp+330h] [ebp+0h]
  void *retaddr; // [esp+334h] [ebp+4h] BYREF

  if ( a3 != -1 )
    sub_462469();
  memset(&v10[1], 0, 0x4Cu);
  ExceptionInfo.ExceptionRecord = (PEXCEPTION_RECORD)v10;
  ExceptionInfo.ContextRecord = (PCONTEXT)v11;
  v21 = v11;
  v20 = v5;
  v19 = v6;
  v18 = a3;
  v17 = a2;
  v16 = a1;
  v27 = __SS__;
  v24 = __CS__;
  v15 = __DS__;
  v14 = __ES__;
  v13 = __FS__;
  v12 = __GS__;
  v7 = __readeflags();
  v25 = v7;
  v26 = &retaddr;
  v11[0] = 65537;
  v23 = retaddr;
  v22 = savedregs;
  v10[0] = a4;
  v10[1] = a5;
  v10[3] = retaddr;
  v8 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(0);
  if ( !UnhandledExceptionFilter(&ExceptionInfo) && !v8 && a3 != -1 )
    sub_462469();
}
