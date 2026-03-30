void *__cdecl CallCatchBlock(
        struct EHExceptionRecord *a1,
        struct EHRegistrationNode *a2,
        struct _CONTEXT *a3,
        const struct _s_FuncInfo *a4,
        void *a5,
        unsigned int a6)
{
  void *v6; // ecx
  void *v7; // ebx
  unsigned int magicNumber; // eax
  int v10; // [esp+10h] [ebp-3Ch] BYREF
  int v11; // [esp+18h] [ebp-34h]
  int v12; // [esp+1Ch] [ebp-30h]
  int v13; // [esp+20h] [ebp-2Ch]
  _DWORD *v14; // [esp+24h] [ebp-28h]
  __ehstate_t state; // [esp+28h] [ebp-24h]
  void *v16; // [esp+30h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  v7 = v6;
  v16 = v6;
  v11 = 0;
  state = a2[-1].state;
  v14 = _CreateFrameInfo(&v10, (int)a1->params.pExceptionObject);
  v13 = *(_DWORD *)(_getptd() + 136);
  v12 = *(_DWORD *)(_getptd() + 140);
  *(_DWORD *)(_getptd() + 136) = a1;
  *(_DWORD *)(_getptd() + 140) = a3;
  ms_exc.registration.TryLevel = 1;
  v16 = _CallCatchBlock2(a2, a4, v7, (int)a5, a6);
  ms_exc.registration.TryLevel = -2;
  a2[-1].state = state;
  _FindAndUnlinkFrame((int)v14);
  *(_DWORD *)(_getptd() + 136) = v13;
  *(_DWORD *)(_getptd() + 140) = v12;
  if ( a1->ExceptionCode == -529697949 && a1->NumberParameters == 3 )
  {
    magicNumber = a1->params.magicNumber;
    if ( (magicNumber == 429065504 || magicNumber == 429065505 || magicNumber == 429065506)
      && !v11
      && v16
      && _IsExceptionObjectToBeDestroyed((int)a1->params.pExceptionObject) )
    {
      __DestructExceptionObject(a1);
    }
  }
  return v16;
}
