signed int __usercall sub_41E700@<eax>(_DWORD *a1@<edi>)
{
  _BYTE *EngineInstance; // esi
  bool v2; // zf
  _BYTE *v3; // esi
  char v4; // bl
  _BYTE *v5; // esi
  char v6; // bl
  signed int result; // eax
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int Val[19]; // [esp+Ch] [ebp-50h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v2 = byte_4CA649 == 0;
  EngineInstance[777] = 1;
  if ( !v2 )
    LeaveCriticalSection(&CriticalSection);
  v3 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = v3[773];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v4 )
    goto LABEL_17;
  v5 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = v5[776];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v6 )
    return -2147467259;
  result = sub_41CC30(L"Direct3D Window");
  if ( result >= 0 )
  {
LABEL_17:
    Val[0] = 2;
    Val[1] = 2;
    Val[2] = 2;
    Val[3] = 2;
    Val[4] = 2;
    Val[5] = 2;
    Val[6] = 2;
    Val[7] = 2;
    Val[8] = 2;
    Val[9] = 2;
    Val[10] = 2;
    Val[11] = 2;
    Val[12] = 2;
    Val[13] = 2;
    Val[14] = 2;
    Val[15] = 2;
    Val[16] = 2;
    v8 = sub_4283D0(Val, a1, a1);
    v9 = v8;
    if ( v8 >= 0 )
    {
      v10 = sub_41E880(a1, 0, 0, 0, 1);
      return v10 >= 0 ? 0 : v10;
    }
    else
    {
      sub_4256B0(v8);
      return v9;
    }
  }
  return result;
}
