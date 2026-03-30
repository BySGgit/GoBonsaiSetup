int __usercall sub_429DC0@<eax>(_DWORD *a1@<esi>, _DWORD *a2, _DWORD *a3)
{
  int *EngineInstance; // edi
  int v4; // edi
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int result; // eax
  _DWORD v10[3]; // [esp+Ch] [ebp-18h] BYREF
  int v11; // [esp+18h] [ebp-Ch]

  sub_41F750();
  EngineInstance = (int *)GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v4 = *EngineInstance;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  memset(a1, 0, 0x48u);
  if ( a3[1] )
    *a1 = *a2;
  else
    *a1 = 0;
  if ( a3[3] )
    a1[1] = a2[1];
  else
    a1[1] = 1;
  if ( a3[4] )
    a1[12] = a2[12];
  else
    a1[12] = 1;
  if ( a3[5] )
  {
    a1[2] = a2[2];
  }
  else
  {
    (*(void (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)v4 + 32))(v4, *a1, v10);
    if ( a1[12] )
    {
LABEL_18:
      a1[2] = v11;
    }
    else
    {
      switch ( v11 )
      {
        case 20:
        case 21:
        case 22:
        case 31:
        case 32:
        case 35:
        case 36:
          goto LABEL_18;
        default:
          a1[2] = 22;
          break;
      }
    }
  }
  if ( a3[6] )
    a1[3] = a2[3];
  else
    a1[3] = 64;
  if ( a3[7] )
  {
    v6 = a2[5];
    a1[4] = a2[4];
    a1[5] = v6;
  }
  else if ( a1[12] )
  {
    a1[4] = 640;
    a1[5] = 480;
  }
  else
  {
    (*(void (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)v4 + 32))(v4, *a1, v10);
    v5 = v10[1];
    a1[4] = v10[0];
    a1[5] = v5;
  }
  v7 = 0;
  if ( a3[8] )
    a1[6] = a2[6];
  else
    a1[6] = a1[2];
  if ( a3[9] )
    a1[7] = a2[7];
  else
    a1[7] = 1;
  if ( a3[10] )
  {
    v8 = a2[9];
    a1[8] = a2[8];
    a1[9] = v8;
  }
  else
  {
    a1[8] = 0;
    a1[9] = 0;
  }
  if ( a3[11] )
    a1[10] = a2[10];
  else
    a1[10] = 1;
  if ( a3[12] || a3[13] )
  {
    result = a2[14];
    a1[14] = result;
  }
  else
  {
    result = a1[6] - 20;
    switch ( a1[6] )
    {
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x1F:
      case 0x20:
      case 0x23:
      case 0x24:
        a1[14] = 71;
        break;
      default:
        a1[14] = 80;
        break;
    }
  }
  if ( a3[14] )
    a1[15] = a2[15];
  else
    a1[15] = 2;
  if ( a3[15] )
  {
    result = a2[16];
    a1[16] = result;
  }
  else
  {
    a1[16] = 0;
  }
  if ( a3[16] )
    v7 = a2[17];
  a1[17] = v7;
  return result;
}
